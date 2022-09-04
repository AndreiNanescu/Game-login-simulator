#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include "playerDB.h"
#include "menu.h"
#include "login.h"
#include "playerNumber.h"
int main()
{
	PlayerDataBase databaseObj;
	srand(time(NULL));
	int poolSize;
	if (!databaseObj.isEmpty())
	{
		menuFunctions menuObj;
		if (menuObj.run() == 0)
			std::cout << "Proceeding with the already generated player pool.";
		else
		{
			std::cout << "Generating a new player pool." << std::endl
				<< "Please set the size of the pool ";
			std::cin >> poolSize;
			std::ofstream temp;
			remove("loggedPlayers.txt");
			rename("temp.txt", "loggedPlayers.txt");
			databaseObj.newPlayerPool(poolSize);
		}
	}
	else
	{
		std::cout << "No previous player pool is generated" << std::endl
			<< "Please set the size of the pool ";
		std::cin >> poolSize;
		databaseObj.newPlayerPool(poolSize);
	}
	std::cout << std::endl;
	login loginObj;
	auto start = std::chrono::system_clock::now();
	bool isRunning{ true };
	while (isRunning)
	{
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> seconds = end - start;
		if (seconds.count() >= 2)
		{
			std::time_t time = std::chrono::system_clock::to_time_t(end);
			std::cout << std::ctime(&time);
			loginObj.logInPlayer();
			loginObj.logOutPlayer();
			std::cout << std::endl;
			start = std::chrono::system_clock::now();
		}
		if (getPoolSize() <= 3)
		{
			isRunning = false;
			std::cout << "Too few players in the player pool.";
		}	
	}
}