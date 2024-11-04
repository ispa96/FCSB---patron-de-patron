#include "Team.h"

#include <fstream>
#include <string>

std::ifstream f("FCSB_TEAM.in");

Team::Team(std::string name) {
	m_name = name;
	m_points = 0;

	/// initializeaza vectorul cu statusul echipei
	for (unsigned int i = 0; i < 30; i++)
		m_status.emplace_back('-');
}

void Team::update_points() {
	if (m_status[m_status.size() - 1] == 'I')
		return;
	else if (m_status[m_status.size() - 1] == 'E')
		m_points++;
	else m_points += 3;
}

void Team::init_playerlist() {
	std::string line;

	while (std::getline(f, line)) {
		unsigned int ant = 0, cnt = 0;
		std::string first_name, last_name, position;
		unsigned int value = line[line.size() - 1] - '0';

		for (unsigned int i = 0; i < line.size(); i++) {
			if (!isdigit(line[i]) and !isalpha(line[i])) {
				cnt++;

				if (cnt == 1) first_name = line.substr(ant, i - ant);
				else if (cnt == 2) last_name = line.substr(ant, i - ant);
				else if (cnt == 3) position = line.substr(ant, i - ant);

				ant = i + 1;
			}
		}

		/// creeaza jucatorul cu datele respective si il baga in echipa 
		Player p(first_name, last_name, position, value);
		m_players.emplace_back(p);
	}
}

void Team::display_playerlist() {
	for (auto& player : m_players)
		player.get_details();
}

std::string Team::get_name() {
	return m_name;
}

unsigned int Team::get_points() {
	return m_points;
}