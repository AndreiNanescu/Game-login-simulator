#include "playerDB.h"
#include <fstream>
#include <iostream>

std::ostream& operator <<(std::ostream& output, const PlayerDataBase& DB)
{
	output << DB.PlayerData.getUsername()<< " " << DB.PlayerData.getIP();
	return output;
}

void PlayerDataBase::addPlayers(int numberOfPlayers)
{
	PlayerDataBase auxDB;
	std::ofstream Storage;
	Storage.open("PlayerData.txt",std::ios_base::app);
	for (int i = 0; i < numberOfPlayers; i++)
	{
		auxDB.PlayerData=auxDB.PlayerData.generatePlayer();
		Storage << auxDB<<std::endl;
	}
	Storage.close();
}