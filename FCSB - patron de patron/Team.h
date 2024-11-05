#pragma once

#include "Player.h"

#include <iostream>
#include <vector>

class Team {
private:
	std::string m_name;
	unsigned int m_points;
	std::vector<char> m_status;
	std::vector<Player> m_players;
	std::vector<Team> m_matches;

public:
	Team(std::string);
	void update_points();
	std::string get_name();
	unsigned int get_points();
	void init_playerlist();
	void display_playerlist();
	void init_matches();
	void get_matches();
};

