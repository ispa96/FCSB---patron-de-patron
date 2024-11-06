#include "Championship.h"

#include <algorithm>
#include <iostream>
#include <Windows.h>

Championship::Championship() {
	m_name = "SUPERLIGA";

	Team t1("Universitatea Cluj");
	m_teams.emplace_back(t1);
	Team t2("Universitatea Craiova");
	m_teams.emplace_back(t2);
	Team t3("CFR Cluj");
	m_teams.emplace_back(t3);
	Team t4("Otelul Galati");
	m_teams.emplace_back(t4);
	Team t5("Petrolul Ploiesti");
	m_teams.emplace_back(t5);
	Team t6("Dinamo Bucuresti");
	m_teams.emplace_back(t6);
	Team t7("Sepsi Sf. Gheorghe");
	m_teams.emplace_back(t7);
	Team t8("Poli Iasi");
	m_teams.emplace_back(t8);
	Team t9("Rapid Bucuresti");
	m_teams.emplace_back(t9);
	Team t10("UTA Arad");
	m_teams.emplace_back(t10);
	Team t11("FC Hermannstadt");
	m_teams.emplace_back(t11);
	Team t12("Gloria Buzau");
	m_teams.emplace_back(t12);
	Team t13("Farul Constanta");
	m_teams.emplace_back(t13);
	Team t14("FC Botosani");
	m_teams.emplace_back(t14);
	Team t15("Unirea Slobozia");
	m_teams.emplace_back(t15);
}

void Championship::get_name() {
	for (unsigned int i = 0; i < m_name.size(); i++)
		std::cout << m_name[i], Sleep(100);
}

std::vector<Team> Championship::get_teams() {
	return m_teams;
}

void Championship::add_team(Team team) {
	m_teams.emplace_back(team);
}

bool cmp(Team t1, Team t2) {
	return t1.get_points() > t2.get_points();
}

void Championship::display_rank() {
	sort(m_teams.begin(), m_teams.end(), cmp);

	for (auto& i : m_teams)
		std::cout << i.get_points() << " pts. " << i.get_name() << '\n', Sleep(700);
}

void Championship::set_teams(std::vector<Team>& vec) {
	m_teams = vec;
}