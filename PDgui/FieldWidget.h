#ifndef FIELDWIDGET_H
#define FIELDWIDGET_H

#include "GameEngine.h"
//#include "QCustomPlot.h"

#include <QWidget>
#include <QImage>
#include <QPainter>

class FieldWidget : public QWidget
{
public:
	GameEngine *pGame;
	
	FieldWidget::FieldWidget(QWidget *parent = 0) : QWidget(parent), pGame(nullptr) { }

	QImage getImage();
	
	int getFieldSize() const { return this->iFieldSize; }
	Player *getPlayer(int column, int row) const { return this->vPlayer.at(row).at(column); }
	
	void setCellSize(int size) { this->iCellSize = size; }
	void setControlWidgetSize(int size) { this->iControlWidgetSize = size; }

private:
	QVector<QVector<Player*>> vPlayer;
	
	int iCellSize = 12, iFieldSize = 0,
		iMouseX = 0, iMouseY = 0, iControlWidgetSize = 0;
		
	void paintField();
	void createPlayers(int fieldSize);
	
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);

	void updateControlWidget();
};

#endif