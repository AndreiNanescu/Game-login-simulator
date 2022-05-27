#pragma once
#include <string>
class player
{
private:
	std::string userName;
	std::string IP;
public:
	player generatePlayer();
	std::string getUsername() const;
	std::string getIP() const;

};

