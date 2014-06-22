#ifndef GAME_H
#define GAME_H

#include <QPoint>
#include <QVector>

#define NOMINMAX
#include <windows.h>

class Player
{
public:
	enum EPlayerType
	{
		Defector = 0,
		Cooperator
	};

	Player(int row, int column) : p(column, row) {}

	int getX() const { return this->p.x(); }
	int getY() const { return this->p.y(); }

	float getWealth() const { return this->fWealth; }
	void  addWealth(float val) { this->fWealth += val; }
	void  clearWealth() { this->fWealth = 0; }

	EPlayerType getType() const { return this->eType; }
	void setType(EPlayerType eType) { this->eType = eType; }
	
	EPlayerType getPrevType() const { return this->ePrevType; }
	void setPrevType(EPlayerType eType) { this->ePrevType = eType; }

private:
	QPoint const p;
	float fWealth = 0;

	EPlayerType eType = EPlayerType::Cooperator,
				ePrevType = EPlayerType::Cooperator;
};


class GameEngine
{
public:
	struct GameThreadInfo
	{
		int count;
	};

	GameEngine(int fieldSize, QVector<QVector<Player*>> &vPlayer)
		: iFieldSize(fieldSize), vPlayer(vPlayer) {}

	void doStep();
	void setTypes();

	int getFieldSize() const { return this->iFieldSize; }	

private:
	enum ENeighbourType
	{
		Moore = 1, 
		vonNeumann
	};

	int iFieldSize = 0, 
		iRow = 0, iCol = 0;
	
	float fReward = 1, fPayoff = 0,
		  fPunishment = 0, fTemptation = 1.85;
		
	QVector<QVector<Player*>> vPlayer;

	void playPD();


	Player *getPlayer(int column, int row) const { return this->vPlayer.at(row).at(column); }
	QVector<Player*> getNeighbours(Player *player, ENeighbourType eNeighbourType = ENeighbourType::Moore);
};

#endif