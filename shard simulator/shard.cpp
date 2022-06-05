#include "shard.h"
#include "player.h"
#include <vector>
const int SHRAD_CAP{ 100 };
class shard
{
	std::vector <player> playerList;
public:
	bool isFull();
	void movePlayer();
	void connectPlayer();
	void disconnectPlayer();
};