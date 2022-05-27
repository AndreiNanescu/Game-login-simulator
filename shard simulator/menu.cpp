#include "menu.h"
#include <iostream>
#include <conio.h>
void greeting();
menuFunctions::menuFunctions()
{
	int i{ 0 };
	menu[i].isSelected = true;
	menu[i].selection = i;
	menu[i].commandLine = "Yes";
	i++;
	menu[i].isSelected = false;
	menu[i].selection = i;
	menu[i].commandLine = "No";
}

int menuFunctions::run()
{
	bool running{ true };
	char input;
	do
	{
		greeting();
		for (int i = 0; i < maxSize; i++)
		{
			if (i == 0)
			{
				if (menu[i].isSelected == true)
					std::cout << " >>" << menu[i].commandLine;
				else
					std::cout << "   " << menu[i].commandLine;
			}
			else
				if (menu[i].isSelected == true)
					std::cout << " >>" << menu[i].commandLine;
				else
					std::cout << "   " << menu[i].commandLine;
		}
		input = _getch();
		if ((input == 0) || (input == 0xE0))
			input = _getch();
		switch (input)
		{
		case 77:
		case 75:
		{
			menu[0].isSelected = !menu[0].isSelected;
			menu[1].isSelected = !menu[1].isSelected;
		}break;
		case '\r':
		{
			if (menu[0].isSelected)
			{
				std::cout << std::endl;
				return 0;
			}
			if (menu[1].isSelected)
			{
				std::cout << std::endl;
				return 1;
			}
		}
		break;
		case 27:
			running = !running;
			break;
		}
		system("cls");
	} while (running);



}

void greeting()
{
	std::cout << "A batch of X players is already generated" << std::endl
		<< "Do you wish to proceed? " << std::endl;
}
