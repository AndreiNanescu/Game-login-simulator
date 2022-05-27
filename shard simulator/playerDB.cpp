#include "playerDB.h"
#include <fstream>
#include <iostream>

std::ostream& operator <<(std::ostream& output, const PlayerDataBase& DB)
{
	output << DB.PlayerData.userName << " " << DB.PlayerData.IP;
	return output;
}

void PlayerDataBase::addPlayers(int numberOfPlayers)
{
	PlayerDataBase auxDB;
	std::ofstream Storage;
	Storage.open("PlayerData.txt");
	for (int i = 0; i < numberOfPlayers; i++)
	{
		auxDB.PlayerData=auxDB.PlayerData.generatePlayer();
		Storage << auxDB<<std::endl;
	}
	Storage.close();
}