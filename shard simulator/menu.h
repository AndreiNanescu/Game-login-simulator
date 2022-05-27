#pragma once
#include<string>
const int maxSize{ 2 };
struct menuTemplate
{
	int selection;
	bool isSelected;
	std::string commandLine;
};
class menuFunctions
{
private:
	menuTemplate menu[maxSize];
public:
	menuFunctions();
	int run();
};

