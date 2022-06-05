#include "login.h"
#include <string>
#include <fstream>

void login::loginPlayer()
{
	std::string playerData;
	int numberOfPlayers{ 0 };
	std::fstream playerDB;
	playerDB.open("PlayerData");
	while (std::getline(playerDB, playerData))
		++numberOfPlayers;
	playerDB.close();
	int random{ 0 };
	random = rand() % numberOfPlayers;
	playerDB.open("PlayerData");
	
}