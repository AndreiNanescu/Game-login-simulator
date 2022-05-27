#include "player.h"
class PlayerDataBase
{
private:
	player PlayerData;
	int numberOfPlayerPool;
	int numberOfLoggedPlayers;
public:
	friend std::ostream& operator <<(std::ostream& output,const PlayerDataBase & s);
	bool isEmpty();
	void newPlayerPool(int);
	void addPlayers(int);
	
};