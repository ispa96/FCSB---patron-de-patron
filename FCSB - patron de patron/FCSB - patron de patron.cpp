/**



**/


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Championship.h"
#include "Team.h"
#include "Transfermarkt.h"

#define FAST std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)

/// citeste jucatorii de pe transfermarkt
std::ifstream fin("Transfermarkt.in");

static void transform_answer(std::string& string)
{
	unsigned int len = string.size();

	for (unsigned int i = 0; i < len; i++)
		if (string[i] >= 'a' and string[i] <= 'z')
			string[i] -= 32;
}

int main()
{
	FAST;

	bool participate = true;
	std::string str;

	std::cout << "--- Welcome to your new club! ---\n";
	std::cout << "Press [ENTER] to start the adventure!\n";
	std::getline(std::cin, str);

	while (participate) {
		/// o sa inceapa meciurile din campionat
		Championship championship;
		
		/// initializeaza lista cu jucatorii de pe Transfermarkt
		Transfermarkt transfermarkt;
		std::cout << "*** " << championship.get_name() << " ***\n[WARNING]: Prima parte a SUPERLIGII va contine primele 15 meciuri din acest sezon.\n[WARNING]: Bafta !!!\n\n";

		/// adaug echipa mea in championship + initializam lotul echipei + initializam meciurile echipei
		Team team("FCSB");
		championship.add_team(team);
		team.init_playerlist();
		team.init_matches();

		/// pentru randomizare
		srand(static_cast <unsigned int> (time(0)));

		/// joaca primele 15 meciuri din campionat
		for (auto& _team : team.play_matches()) {
			int goals1 = rand() % 100 + 1;
			int goals2 = rand() % 100 + 1;

			// std::cout << goals1 << ' ' << goals2 << '\n';
			if (goals1 > goals2) team.increase_points();
		}

		/// scoate echipa cu punctajul vechi si o baga cu punctajul nou
		auto teams = championship.get_teams();  
		for (unsigned int i = 0; i < teams.size(); i++)
			if (teams[i].get_name() == "FCSB") {
				teams.erase(teams.begin() + i);
				championship.add_team(team); 
				break;
			}

		/// afisarea clasamentului initial cu toate echipele
		championship.display_rank();
		std::cout << '\n';

		std::cout << "\n\nDo you want to be the boss for the next year?\n";
		std::cin >> str;
		transform_answer(str);

		if (str == "NO")	/// daca nu vrea sa mai continue
			participate = false;
	}

	system("cls");
	return 0;
}


/**



**/
