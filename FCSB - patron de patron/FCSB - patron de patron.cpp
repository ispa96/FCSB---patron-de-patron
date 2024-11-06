/**



**/


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

#include "Championship.h"
#include "Team.h"
#include "Transfermarkt.h"

#define FAST std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

/// citeste jucatorii de pe transfermarkt
std::ifstream fin("Transfermarkt.in");

static void transform_answer(std::string& string) {
	unsigned int len = string.size();

	for (unsigned int i = 0; i < len; i++)
		if (string[i] >= 'a' and string[i] <= 'z')
			string[i] -= 32;
}

static void print_sleep() {
	std::string aux = "*****";
	for (unsigned int i = 0; i < aux.size(); i++)
		std::cout << aux[i], Sleep(100);
}

static void loading_bar() {
	int times = 0, it = 1;
	std::cout << '\n';

	while (times != 30) {
		system("cls");
		std::cout << "-------------------------------";
		std::cout << '\n';
		std::cout << '|';
		for (unsigned int j = 0; j < it - 1; j++)
			std::cout << char(35);
		for (unsigned int j = 0; j < 29 - times; j++)
			std::cout << ' ';
		std::cout << "|";
		std::cout << '\n';
		std::cout << "-------------------------------";

		times++;
		it++;
		Sleep(30);
	}
}

int main()
{
	FAST;

	bool participate = true;
	std::string str;

	std::cout << "--- Bun venit la noul tau club ! ---\n";
	std::cout << "Apasa [ENTER] pentru a incepe aventura !\n";
	std::getline(std::cin, str);
	system("cls");

	while (participate) {
		/// o sa inceapa meciurile din campionat
		Championship championship;
		/// initializeaza lista cu jucatorii de pe Transfermarkt
		Transfermarkt transfermarkt;

		print_sleep();
		std::cout << ' ';
		championship.get_name();
		std::cout << ' ';
		print_sleep();
		std::cout << "\n[WARNING]: Prima parte a SUPERLIGII va contine primele 15 meciuri din acest sezon.\n[WARNING]: Multa Bafta !!!\n";

		/// adaug echipa mea in championship + initializam lotul echipei + initializam meciurile echipei
		Team team("FCSB");
		championship.add_team(team);
		team.init_playerlist();
		team.init_matches();

		std::cout << "[WARNING]: Asa arata tabloul cu echipele inainte de inceperea partidelor:\n\n";
		championship.display_rank();
		std::cout << "\n";

		std::cout << "[WARNING]: Apasa [ENTER] pentru derularea primelor 15 meciuri din campionat !\n";
		std::getline(std::cin, str);

		loading_bar();
		std::cout << "\n\n[WARNING]: Asa arata clasamentul dupa primele 15 meciuri !\n\n";

		/// pentru randomizare
		srand(static_cast <unsigned int> (time(0)));
																							/// PRIMA PARTE A CAMPIONATULUI
		/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		/// joaca primele 15 meciuri din campionat
		for (auto& _team : team.play_matches()) {
			int goals1 = rand() % 100 + 1;
			int goals2 = rand() % 100 + 1;

			unsigned int price_ticket = rand() % 100 + 1;
			unsigned int supporters = rand() % 100 + 1;
			unsigned int value = supporters * (supporters + 10) * price_ticket * 10;
			team.game_increase_budget(value);

			// std::cout << goals1 << ' ' << goals2 << '\n';
			if (goals1 > goals2) {	/// daca echipa mea a castigat
				team.win_increase_points();
				team.win_increase_budget(100000);
			}
			else {	/// daca echipa mea a facut egal
				team.draw_increase_points();
				team.draw_increase_budget(50000);
			}
		}

		/// scoate echipa cu punctajul vechi si o baga cu punctajul nou (echipa mea)
		auto teams = championship.get_teams();  
		for (unsigned int i = 0; i < teams.size(); i++)
			if (teams[i].get_name() == "FCSB") {
				teams.erase(teams.begin() + i);
				teams.emplace_back(team);
				break;
			}
		/// trebuie sa dam un punctaj random celorlalte echipe, in apropiere de punctajul exhipei noastre
		unsigned int left = 0, right = 0;
		if (team.get_points() <= 20) left = 1;
		else left = team.get_points() - 20;
		right = team.get_points() + 10;

		for (auto& _team : team.play_matches()) {	/// luam fiecare adversara a echipei noastre
			unsigned int num = 1000;	/// num o sa fie o valoare random intre left si right
			while (num < left or num > right)
				num = rand() % 100 + 1;

			_team.set_points(num);	/// updatam punctele echipei respective

			for (unsigned int i = 0; i < teams.size(); i++) {	/// cautam in echipele din campionat
				if (teams[i].get_name() == _team.get_name()) {	/// cand o gasim
					teams.erase(teams.begin() + i);	/// o stergem
					teams.emplace_back(_team);
					break;
				}
			}
		}
		championship.set_teams(teams);

		/// afisarea clasamentului initial cu toate echipele
		championship.display_rank();
		std::cout << '\n';

																						/// PERIOADA DE TRANSFERURI
		/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		std::cout << "[WARNIMG]: Urmeaza perioada de transferuri !\n";
		std::cout << "[WARNIMG]: Apasa [ENTER] pentru a vedea lista jucatorilor disponibili:\n";
		std::getline(std::cin, str);

		std::cout << "[WARNING]: Acestia sunt jucatorii transferabili:\n\n";
		transfermarkt.get_players();

		std::cout << "[WARNING]: Apasa [ENTER] pentru a vedea bugetul echipei!\n";
		std::getline(std::cin, str);
		std::cout << "[WARNING]: Bugetul echipei tale este in valoare de " << team.get_budget() << " milioane de euro !\n\n";

																						/// A DOUA PARTE A CAMPIONATULUI
		/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		std::cout << "\n\nDo you want to be the boss for the next year?\n";
		std::cin >> str;
		transform_answer(str);
		if (str == "NO") participate = false;	/// daca nu vrea sa mai continue
	}

	system("cls");
	return 0;
}


/**



**/
