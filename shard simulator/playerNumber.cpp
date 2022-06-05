#include <fstream>
#include <string>
int getPoolSize()
{
	std::ifstream playerNumber;
	playerNumber.open("playerNumber.txt");;
	std::string auxString;
	playerNumber >> auxString;
	playerNumber.close();
	return stoi(auxString);
}
void setPoolSize(int numberOfPlayers)
{
	std::ofstream playerNumber;
	playerNumber.open("playerNumber.txt");
	playerNumber << numberOfPlayers;
	playerNumber.close();
}
void updatePoolSize(int numberOfPlayers)
{
	std::fstream playerNumber;
	int oldNumberOfPlayers;
	playerNumber >> oldNumberOfPlayers;
	oldNumberOfPlayers += numberOfPlayers;
	playerNumber << oldNumberOfPlayers;
	playerNumber.close();
}