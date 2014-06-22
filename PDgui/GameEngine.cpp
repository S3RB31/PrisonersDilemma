#include "GameEngine.h"

/* GameEngine */

void GameEngine::doStep()
{
	this->playPD();
	this->setTypes();
}

/* Private */

void GameEngine::setTypes()
{
	for (int r = 0; r < this->iFieldSize; r++)
	{
		for (int c = 0; c < this->iFieldSize; c++)
		{
			Player *pPlayer = this->getPlayer(c, r);
			QVector<Player*> vOpponents = this->getNeighbours(pPlayer);

			pPlayer->setPrevType(pPlayer->getType());

			float iBestValue = 0;

			for (int i = 0; i < vOpponents.size(); i++)
			{
				if (vOpponents.at(i)->getWealth() > iBestValue)
				{
					iBestValue = vOpponents.at(i)->getWealth();
					pPlayer->setType(vOpponents.at(i)->getType());
				}
			}
		}
	}
}

void GameEngine::playPD()
{
	for (int r = 0; r < this->iFieldSize; r++)
		for (int c = 0; c < this->iFieldSize; c++) 
			this->getPlayer(c, r)->clearWealth();
	
	for (int r = 0; r < this->iFieldSize; r++)
	{
		for (int c = 0; c < this->iFieldSize; c++)
		{
			Player *pPlayer = this->getPlayer(c, r);
			QVector<Player*> vOpponents = this->getNeighbours(pPlayer);

			for (int i = 0; i < vOpponents.size(); i++)
			{
				Player *pDetractor = vOpponents.at(i);
		
				if (pDetractor->getType() == Player::EPlayerType::Cooperator &&	
					pPlayer->getType() == Player::EPlayerType::Cooperator)
				{
					pPlayer->addWealth(this->fReward);
					vOpponents.at(i)->addWealth(this->fReward);
					continue;
				}

				if (pDetractor->getType() == Player::EPlayerType::Defector && 
					pPlayer->getType() == Player::EPlayerType::Cooperator)
				{
					vOpponents.at(i)->addWealth(this->fTemptation);
					continue;
				}				

				if (pDetractor->getType() == Player::EPlayerType::Cooperator && 
					pPlayer->getType() == Player::EPlayerType::Defector)
				{
					pPlayer->addWealth(this->fTemptation);
					continue;
				}			
			}
		}
	}
}

QVector<Player*> GameEngine::getNeighbours(Player *player, ENeighbourType eNeighbourType)
{
	QVector<Player*> vReturn;
	int x = player->getX(), y = player->getY();

	vReturn.push_back(player); // self (as Nowak/May)
	
	/*
	if (x > 0 && y < this->iFieldSize - 1)	vReturn.push_back(this->getPlayer(x - 1, y + 1));
	if (y < this->iFieldSize - 1)			vReturn.push_back(this->getPlayer(x, y + 1));
	if (x < this->iFieldSize - 1 && y < this->iFieldSize - 1)	vReturn.push_back(this->getPlayer(x + 1, y + 1));

	if (x > 0)								vReturn.push_back(this->getPlayer(x - 1, y));
	if (x < this->iFieldSize - 1)			vReturn.push_back(this->getPlayer(x + 1, y));

	if (x > 0 && y > 0)						vReturn.push_back(this->getPlayer(x - 1, y - 1));
	if (y > 0)								vReturn.push_back(this->getPlayer(x, y - 1));
	if (x < this->iFieldSize - 1 && y > 0)	vReturn.push_back(this->getPlayer(x + 1, y - 1));
	*/

	

	if (x < this->iFieldSize - 1)	vReturn.push_back(this->getPlayer(x + 1, y));
	if (y < this->iFieldSize - 1)	vReturn.push_back(this->getPlayer(x, y + 1));

	if (y > 0)						vReturn.push_back(this->getPlayer(x, y - 1));
	if (x > 0)						vReturn.push_back(this->getPlayer(x - 1, y));

	if (eNeighbourType == ENeighbourType::Moore)
	{
		if (x > 0 && y > 0)											vReturn.push_back(this->getPlayer(x - 1, y - 1));
		if (x > 0 && y < this->iFieldSize - 1)						vReturn.push_back(this->getPlayer(x - 1, y + 1));
		if (x < this->iFieldSize - 1 && y > 0)						vReturn.push_back(this->getPlayer(x + 1, y - 1));		
		if (x < this->iFieldSize - 1 && y < this->iFieldSize - 1)	vReturn.push_back(this->getPlayer(x + 1, y + 1));
	}


	return vReturn;
}