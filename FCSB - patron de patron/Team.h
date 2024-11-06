#pragma once

#include "Player.h"

#include <iostream>
#include <vector>

class Team {
private:
	std::string m_name;
	unsigned int m_points;
	int m_budget;
	std::vector<char> m_status;
	std::vector<Player> m_players;
	std::vector<Team> m_matches;

public:
	Team(std::string);
	void update_points();
	std::string get_name();
	unsigned int get_points();
	unsigned int get_budget();
	void init_playerlist();
	void display_playerlist();
	void init_matches();
	void get_matches();
	void win_increase_points();
	void draw_increase_points();
	void win_increase_budget(const unsigned int&);
	void draw_increase_budget(const unsigned int&);
	void game_increase_budget(unsigned int&);
	void set_points(unsigned int&);
	std::vector<Team> play_matches();
};

