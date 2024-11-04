#pragma once

#include <iostream>

class Player {
private:
	std::string m_firstname, m_lastname, m_position;
	unsigned int m_salary, m_value, m_age, m_matches_played, m_grade;	/// m_grade este totalul notelor obtinute la fiecare meci

public:
	Player(std::string, std::string, std::string, unsigned int);
	void update_value();
	void update_performance();
	void get_details();
};

