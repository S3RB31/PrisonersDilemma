#include "MainWindow.h"

/* FieldWidget */

QImage FieldWidget::getImage()
{
	QSize size = this->rect().adjusted(0, 0, -1, -1).size();
	QImage img(size, QImage::Format::Format_ARGB32);
	
	QPainter painter(&img);
	this->render(&painter);

	return img;
}

void FieldWidget::createPlayers(int fieldSize)
{
	for (; this->vPlayer.size() > 0; this->vPlayer.pop_back())
		for (; this->vPlayer.back().size() > 0; this->vPlayer.back().pop_back())
			delete this->vPlayer.back().back();
		
	for (int r = 0; r < this->iFieldSize; r++)
	{
		QVector<Player*> vTmpPlayer;

		for (int c = 0; c < this->iFieldSize; c++)
		{
			Player *pTmpPlayer = new Player(r, c);

			//pTmpPlayer->setType(static_cast<Player::EPlayerType>((rand() % 10) > 1));
			//pTmpPlayer->setPrevType(pTmpPlayer->getType());

			vTmpPlayer.push_back(pTmpPlayer);
		}
		
		this->vPlayer.push_back(vTmpPlayer);
	}

	mainWindow->killGameThread();

	if (this->pGame)
		delete this->pGame;

	this->pGame = new GameEngine(this->iFieldSize, this->vPlayer);
}

/* Private */

void FieldWidget::paintField()
{
	QPainter p(this);
	p.fillRect(this->rect().adjusted(0, 0, -1, -1), QColor(130, 135, 144));

	for (int r = 0; r < this->iFieldSize; r++)
	{
		for (int c = 0; c < this->iFieldSize; c++)
		{
			Qt::GlobalColor color = Qt::black;
			Player *pPlayer = this->getPlayer(c, r);

			if (pPlayer->getType() == Player::EPlayerType::Cooperator)
			{				
				if (pPlayer->getPrevType() == Player::EPlayerType::Cooperator) color = Qt::blue;
				else if (pPlayer->getPrevType() == Player::EPlayerType::Defector) color = Qt::green;
			}
			else if (pPlayer->getType() == Player::EPlayerType::Defector)
			{
				//color = Qt::red;
				if (pPlayer->getPrevType() == Player::EPlayerType::Cooperator) color = Qt::yellow;
				else if (pPlayer->getPrevType() == Player::EPlayerType::Defector) color = Qt::red;
			}
			
			p.fillRect(this->iCellSize * c + 1, this->iCellSize * r + 1, this->iCellSize - 1, this->iCellSize - 1, color);
		}
	}
}

void FieldWidget::paintEvent(QPaintEvent *event)
{
	int iSize = this->rect().height(),
		iMaxSize = this->parentWidget()->rect().width() - this->iControlWidgetSize;

	if (iSize + this->iCellSize + 2 > iMaxSize)
		iSize = iMaxSize - (this->iCellSize + 2);

	if (this->iFieldSize == 0 || (iSize - 2) % this->iCellSize != 0)
	{
		this->iFieldSize = ((iSize + this->iCellSize - 1) / this->iCellSize) - 1;
		this->createPlayers(this->iFieldSize);
		iSize = this->iFieldSize * this->iCellSize + 2;
	}

	this->resize(iSize, iSize);
	this->setFixedWidth(iSize);

	this->paintField();
	this->updateControlWidget();
}

void FieldWidget::mousePressEvent(QMouseEvent *event)
{
	QPointF p = event->localPos();

	if (p.x() && p.y())
	{
		int x = ((p.x() + (this->iCellSize - (int(p.x()) % this->iCellSize ? 1 : 0))) / this->iCellSize) - 1,
			y = ((p.y() + (this->iCellSize - (int(p.y()) % this->iCellSize ? 1 : 0))) / this->iCellSize) - 1;

		if (x < this->iFieldSize && y < this->iFieldSize)
		{
			this->iMouseX = x; this->iMouseY = y;

			Player *pPlayer = this->getPlayer(x, y);
			pPlayer->setType(static_cast<Player::EPlayerType>(!pPlayer->getType()));
			pPlayer->setPrevType(pPlayer->getType());

			this->repaint();
			this->updateControlWidget();
		}
	}
}

void FieldWidget::updateControlWidget()
{
	mainWindow->pUI->cellszEdit->setText(QString("%1").arg(this->iCellSize));

	mainWindow->pUI->statusLabel1->setText(QString("fieldsize = %1; w = %2; h = %3;")
		.arg(this->iFieldSize)
		.arg(parentWidget()->rect().width())
		.arg(parentWidget()->rect().height()));

	int iCops = 0, iDefs = 0;

	for (int r = 0; r < this->iFieldSize; r++)
		for (int c = 0; c < this->iFieldSize; c++)
		{
			Player *pPlayer = this->getPlayer(c, r);
			
			if (pPlayer->getType()) 
				iCops++;
			else iDefs++;
		}

	mainWindow->pUI->statusLabel2->setText(QString("Coops: %1; Defs: %2;").arg(iCops).arg(iDefs));

	mainWindow->pUI->statusLabel3->setText(QString("x: %1; y: %2;").arg(this->iMouseX).arg(this->iMouseY));
}