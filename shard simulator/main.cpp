#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include "playerDB.h"
#include "menu.h"
#include "login.h"
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
	while (true)
	{
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> seconds = end - start;
		if (seconds.count() >= 1)
		{
			std::time_t time = std::chrono::system_clock::to_time_t(end);
			std::cout << std::ctime(&time);
			
			loginObj.logInPlayer();
			start = std::chrono::system_clock::now();
		}
	}
	



	
}