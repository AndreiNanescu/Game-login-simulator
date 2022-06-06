#include <iostream>
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
	login loginObj;
	loginObj.logInPlayer();
}