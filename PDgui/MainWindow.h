#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <windows.h>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	friend class FieldWidget;

public:
	MainWindow(QWidget *parent = 0);

	void killGameThread();

private slots:		
	void playGame();
	void changePlayButton(bool state = true);

	void on_playClicked();
	void on_imageClicked();
	void on_setCellClicked();

	void on_lockBoxChanged(int state);
	void on_stepsBoxChanged(int state);
	
private:
	QHBoxLayout *layout;
	Ui::MainWindowClass *pUI;

	static DWORD __stdcall GameThread(LPVOID lpParam);
};

extern MainWindow *mainWindow;

#endif // MAINWINDOW_H
