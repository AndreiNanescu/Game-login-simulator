#include <iostream>
#include "playerDB.h"
#include "menu.h"

int main()
{
	menuFunctions menuObj;
	if (menuObj.run() == 0)
		std::cout << "Proceeding with the already generated player pool.";
	else
		std::cout << "Generating a new player pool." << std::endl
		<< "Please set the size of the pool ";
	int poolSize;
	std::cin >> poolSize;
	PlayerDataBase databaseObj;
	srand(time(NULL));
	databaseObj.addPlayers(poolSize);

}