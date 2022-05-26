#include "player.h"
#include <ctime>
player player::generatePlayer()
{
	player auxClass;
	int randomNumber;
	srand(time(0));
	for (int i = 0; i < 4; i++)
	{
		randomNumber = rand() % 255;
		auxClass.IP = std::to_string(randomNumber);
		auxClass.IP += '.';
	}
	auxClass.IP.pop_back();
}