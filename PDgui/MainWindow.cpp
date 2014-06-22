#include "MainWindow.h"
#include <QFileDialog>

/* Entrypoint */

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainWindow = new MainWindow();
	mainWindow->show();
	return a.exec();
}

/* MainWindow */

HANDLE hGameThread = nullptr;
MainWindow *mainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), pUI(new Ui::MainWindowClass)
{
	pUI->setupUi(this);

	this->layout = new QHBoxLayout(this->centralWidget());
	this->layout->addWidget(pUI->playField);
	this->layout->addWidget(pUI->controls);
	
	connect(pUI->playButton, SIGNAL(clicked()), this, SLOT(on_playClicked()));
	connect(pUI->imageButton, SIGNAL(clicked()), this, SLOT(on_imageClicked()));
	connect(pUI->cellszButton, SIGNAL(clicked()), this, SLOT(on_setCellClicked()));
	connect(pUI->lockBox, SIGNAL(stateChanged(int)), this, SLOT(on_lockBoxChanged(int)));
	connect(pUI->stepsBox, SIGNAL(stateChanged(int)), this, SLOT(on_stepsBoxChanged(int)));

	pUI->controls->setFrameStyle(QFrame::Panel);
	pUI->controls->setMinimumSize(210, 482);
	pUI->controls->setMaximumSize(210, 482);

	pUI->playField->setControlWidgetSize(pUI->controls->minimumWidth() + 7);
}

void MainWindow::killGameThread()
{
	if (hGameThread)
	{
		TerminateThread(hGameThread, 0);
		CloseHandle(hGameThread);

		hGameThread = nullptr;
		this->changePlayButton();		
	}
}

/* Private */

DWORD __stdcall MainWindow::GameThread(LPVOID lpParam)
{
	int iStepCount = reinterpret_cast<DWORD>(lpParam);

	if (iStepCount == 0) 
		iStepCount = -1;

	while (true)
	{
		if (iStepCount == 0)
			break;

		QMetaObject::invokeMethod(mainWindow, "playGame", Qt::BlockingQueuedConnection);
		
		_sleep(100);
		
		if (iStepCount > 0)
			iStepCount--;
	}

	QMetaObject::invokeMethod(mainWindow, "changePlayButton", Qt::BlockingQueuedConnection);
	
	hGameThread = nullptr;
	return 0;
}

/* Slots */

void MainWindow::playGame()
{
	pUI->playField->pGame->doStep();
	pUI->playField->repaint();
}

void MainWindow::changePlayButton(bool state)
{
	pUI->playButton->setText(state ? QString("PLAY!") : QString("STOP!"));
}

void MainWindow::on_playClicked()
{
	if (!hGameThread)
	{
		this->changePlayButton(false);

		if (!pUI->stepsEdit->isEnabled())
			hGameThread = CreateThread(0, 0, GameThread, 0, 0, 0);
		else
			hGameThread = CreateThread(0, 0, GameThread,
			reinterpret_cast<void*>(atoi(pUI->stepsEdit->text().toStdString().c_str())), 0, 0);
	}	
	else this->killGameThread();
}

void MainWindow::on_imageClicked()
{
	QImage image = pUI->playField->getImage();

	QString qstrListOut =
		QFileDialog::getSaveFileName(this, tr("Save image"), "", tr("PNG Image (*.png)"));

	if (!qstrListOut.isEmpty())
		image.save(qstrListOut);
}

void MainWindow::on_setCellClicked()
{
	int iCellSize = atoi(pUI->cellszEdit->text().toStdString().c_str());

	pUI->playField->setCellSize(iCellSize);
	pUI->playField->repaint();
}

void MainWindow::on_lockBoxChanged(int state)
{
	this->setMinimumSize(state ? this->size() : QSize(717, 500));
	this->setMaximumSize(state ? this->size() : QSize(16777215, 16777215));
}

void MainWindow::on_stepsBoxChanged(int state)
{
	this->pUI->stepsLabel->setDisabled(state ? true : false);
	this->pUI->stepsEdit->setDisabled(state ? true : false);
}
