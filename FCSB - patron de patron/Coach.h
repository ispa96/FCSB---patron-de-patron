#pragma once

#include <string>
#include <vector>

#include "Player.h"

class Coach {
private:
	std::string m_name;
	unsigned int m_experience, m_salary;	/// experienta este in ani

public:
	void evaluate_players(std::vector<Player>&);	/// metoda care evalueaza jucatorii care au jucat in meciul respectiv
};

