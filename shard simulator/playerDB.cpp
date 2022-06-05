#include "playerDB.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

int PlayerDataBase::getPoolSize()
{
	std::ifstream playerNumber;
	playerNumber.open("playerNumber.txt");;
	std::string auxString;
	playerNumber >> auxString;
	playerNumber.close();
	return stoi(auxString);
}
void PlayerDataBase::setPoolSize(int numberOfPlayers)
{
	std::ofstream playerNumber;
	playerNumber.open("playerNumber.txt");
	playerNumber << numberOfPlayers;
	playerNumber.close();
}
void PlayerDataBase::updatePoolSize(int numberOfPlayers)
{
	std::fstream playerNumber;
	int oldNumberOfPlayers;
	playerNumber >> oldNumberOfPlayers;
	oldNumberOfPlayers += numberOfPlayers;
	playerNumber << oldNumberOfPlayers;
	playerNumber.close();
}
std::ostream& operator <<(std::ostream& output, const PlayerDataBase& DB)
{
	output << DB.PlayerData.getUsername()<< " " << DB.PlayerData.getIP();
	return output;
}
bool PlayerDataBase::isEmpty()
{
	std::ifstream Storage("PlayerData.txt");
	return Storage.peek() == std::ifstream::traits_type::eof();
}
void PlayerDataBase::newPlayerPool(int numberOfPlayers)
{
	setPoolSize(numberOfPlayers);
	PlayerDataBase auxDB;
	std::ofstream Storage;
	Storage.open("PlayerData.txt");
	for (int i = 0; i < numberOfPlayers; i++)
	{
		auxDB.PlayerData = auxDB.PlayerData.generatePlayer();
		Storage << auxDB << std::endl;
	}
	Storage.close();
}
void PlayerDataBase::addPlayers(int numberOfPlayers)
{
	updatePoolSize(numberOfPlayers);
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
