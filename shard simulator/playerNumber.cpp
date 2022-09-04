#include "playerNumber.h"
#include <fstream>
#include <string>
int getPoolSize()
{
	std::ifstream playerNumber;
	playerNumber.open("poolSize.txt", std::ios::in);;
	std::string auxString;
	playerNumber >> auxString;
	playerNumber.close();
	return stoi(auxString);
}
void setPoolSize(int numberOfPlayers)
{
	std::ofstream playerNumber;
	playerNumber.open("poolSize.txt", std::ios::out);
	playerNumber << numberOfPlayers;
	playerNumber.close();
}
void updatePoolSize(int numberOfPlayers)
{
	std::fstream playerNumber;
	playerNumber.open("poolSize.txt", std::ios::in);
	int oldNumberOfPlayers;
	playerNumber >> oldNumberOfPlayers;
	playerNumber.close();
	playerNumber.open("poolSize.txt", std::ios::out);
	oldNumberOfPlayers += numberOfPlayers;
	playerNumber << oldNumberOfPlayers;
	playerNumber.close();
}