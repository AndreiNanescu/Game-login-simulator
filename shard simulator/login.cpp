#include "login.h"
#include <iostream>
#include <string>
#include <fstream>
#include "playerNumber.h"
void login::logInPlayer()
{
	std::ifstream playerData;
	playerData.open("PlayerData.txt");
	std::ofstream temp;
	temp.open("temp.txt");
	std::ofstream loggedPlayers;
	loggedPlayers.open("LoggedPlayers.txt", std::ios_base::app);
	srand(time(0));
	int randomNumber{ rand() % (getPoolSize() / 4) };
	updatePoolSize(-randomNumber);
	std::cout << "Logged " << randomNumber << " players."<<std::endl;
	std::string line;
	while (getline(playerData, line))
	{
		randomNumber--;
		if (randomNumber >= 0)
			loggedPlayers << line << std::endl;
		else
			temp << line << std::endl;

	}
	playerData.close();
	temp.close();
	loggedPlayers.close();
	remove("PlayerData.txt");
	rename("temp.txt", "PlayerData.txt");
}