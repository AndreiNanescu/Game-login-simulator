#include "player.h"
class PlayerDataBase
{
private:
	player PlayerData;
public:
	void setPoolSize(int);
	int getPoolSize();
	void updatePoolSize(int);
	friend std::ostream& operator <<(std::ostream& output,const PlayerDataBase & s);
	bool isEmpty();
	void newPlayerPool(int);
	void addPlayers(int);	
	
};