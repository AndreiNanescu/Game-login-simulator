#pragma once
#include <string>
class player
{
public:
	std::string userName;
	std::string IP;
	player generatePlayer();
	std::string getUsername() const;
	std::string getIP() const;

};

