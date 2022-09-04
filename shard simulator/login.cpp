#include "login.h"
#include "playerNumber.h"
#include <iostream>
#include <string>
#include <fstream>
void login::logInPlayer()
{
	std::ifstream playerData;
	playerData.open("PlayerData.txt");
	std::ofstream temp;
	temp.open("temp.txt");
	std::ofstream loggedPlayers;
	loggedPlayers.open("LoggedPlayers.txt", std::ios_base::app);
	srand(time(0));
	int randomNumber{ (rand() % (getPoolSize() / 2)) + 1 };
	updatePoolSize(-randomNumber);
	std::cout << "Logged in " << randomNumber << " players." << std::endl;
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

void login::logOutPlayer()
{
	std::ifstream loggedPlayers;
	loggedPlayers.open("loggedPlayers.txt");
	std::ofstream temp;
	temp.open("temp.txt");
	std::ofstream playerData;
	playerData.open("PlayerData.txt", std::ios_base::app);
	srand(time(0));
	int randomNumber{ (rand() % (getPoolSize() / 2)) + 1 };
	updatePoolSize(randomNumber);
	std::cout << "Logged out " << randomNumber << " players." << std::endl;
	std::string line;
	while (getline(loggedPlayers, line))
	{
		randomNumber--;
		if (randomNumber >= 0)
			playerData << line << std::endl;
		else
			temp << line << std::endl;

	}
	loggedPlayers.close();
	temp.close();
	playerData.close();
	remove("loggedPlayers.txt");
	rename("temp.txt", "loggedPlayers.txt");

}