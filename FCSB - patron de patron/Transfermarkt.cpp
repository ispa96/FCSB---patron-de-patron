#include "Transfermarkt.h"
#include "Player.h"

#include <fstream>
#include <string>
#include <Windows.h>

std::ifstream read("Transfermarkt.in");

Transfermarkt::Transfermarkt() {
	std::string line;

	while (std::getline(read, line)) {
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

		/// creeaza jucatorul cu datele respective si il baga pe Transfermarkt 
		Player p(first_name, last_name, position, value);
		m_players.emplace_back(p);
	}
}

void Transfermarkt::get_players() {
	for (auto& player : m_players)
		player.get_details(), std::cout << '\n', Sleep(700);
}