#include "Player.h"
#include <iostream>

Player::Player(std::string name1, std::string name2, std::string position, unsigned int value) {
	m_firstname = name1;
	m_lastname = name2;
	m_position = position;
	m_value = value;
}

void Player::get_details() {
	std::cout << "PRENUME: " << m_firstname << '\n';
	std::cout << "NUME: " << m_lastname << '\n';
	std::cout << "POZITIE: " << m_position << '\n';
	std::cout << "VALOARE: " << m_value;

	if (m_value == 1) std::cout << " milion de euro\n";
	else std::cout << " milioane de euro\n";
}

void Player::update_performance() {
	m_matches_played++;
	/// m_grade i se adauga o valoare la intamplare ce reprezinta nota jucatorului de la meciul respectiv
}