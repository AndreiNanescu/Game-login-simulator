#include "player.h"
#include <ctime>
const int MAX{ 26 };
player player::generatePlayer()
{
	srand(time(0));
	player auxClass;
	//Username generator
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' };
	int randomNameLength{ rand() % 5 + 3 };
	for (int i = 0; i < randomNameLength; i++)
		auxClass.userName += alphabet[rand() % MAX];
	//IP generator
	int randomNumber;
	for (int i = 0; i < 4; i++)
	{
		randomNumber = rand() % 255;
		auxClass.IP = std::to_string(randomNumber);
		auxClass.IP += '.';
	}
	auxClass.IP.pop_back();

	return auxClass;
}