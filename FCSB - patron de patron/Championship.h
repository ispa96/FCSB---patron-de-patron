#pragma once

#include <iostream>
#include <vector>

#include "Team.h"

class Championship {
private:
	std::string m_name;
	std::vector<Team> m_teams;

public:
	Championship();
	void get_name();
	void add_team(Team);
	void display_rank();
	std::vector<Team> get_teams();
	void set_teams(std::vector<Team>&);
};

