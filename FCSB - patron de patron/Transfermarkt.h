#pragma once

#include "Player.h"
#include <vector>

class Transfermarkt {
private:
	std::vector<Player> m_players;

public:
	Transfermarkt();
	void get_players();
};

