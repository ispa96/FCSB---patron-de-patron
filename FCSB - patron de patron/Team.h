#pragma once

#include "Player.h"

#include <iostream>
#include <vector>

/*class Team {
private:
	std::string m_name;
	std::vector<Player> player_list;
	// Coach coach;
	// Buget buget;
	// std::vector<Game> status;

public:
	Team(std::string&);
};*/

class Team {
private:
	std::string m_name;
	unsigned int m_points;
	std::vector<char> m_status;
	std::vector<unsigned int> m_matches;
	std::vector<Player> m_players;

public:
	Team(std::string);
	void update_points();
	std::string get_name();
	unsigned int get_points();
	void init_playerlist();
	void display_playerlist();
};

