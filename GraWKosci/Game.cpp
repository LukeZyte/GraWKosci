#include "Game.h"

int randomNum(int min, int max) {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max); // define the range
	return distr(gen);
}

void playerCall(int round, Participant player) {
	color(TEXT_COLOR);
	cout << "\n\t Tura gracza: "; color(PRIMARY_COLOR); cout << player.getNickname(); color(TEXT_COLOR); cout << " : : Runda " << round << "\n\n";
	cout << " Zdobyte punkty: ";
	color(PRIMARY_COLOR);
	cout << player.getAllPoints() << "\n\n";
	color(TEXT_COLOR);
}

void controlsHelper() {
	color(NS_TEXT_COLOR);
	cout << " [ Enter ] - wybór;\n [ strza³ki lewo, prawo ] - ruch miêdzy koœæmi;\n [ e ] - potwierdŸ wybór i rzuæ pozosta³ymi koœæmi;\n [ q ] - zakoncz turê;\n [ h ] - poka¿ tabelê uk³adów\n\n";
	color(TEXT_COLOR);
}

void cheatSheet() {
	cout << "Tabela uk³adów oczek\n\n";
	cout <<
		"    Nazwa    |   Warunek do zdobycia  |  Przyk³ad  |       Wynik\n" <<
		"-------------|------------------------|------------|---------------------\n" <<
		"   Jedynki   |          brak          | "; color(PRIMARY_COLOR); cout << "1 1 1 "; color(TEXT_COLOR); cout << "3 4  | suma jedynek (3 pkt)\n" <<
		"   Dwójki    |          brak          | "; color(PRIMARY_COLOR); cout << "2 2 2 "; color(TEXT_COLOR); cout << "5 6  | suma dwójek (6 pkt)\n" <<
		"   Trójki    |          brak          | "; color(PRIMARY_COLOR); cout << "3 3 3 3 "; color(TEXT_COLOR); cout << "4  | suma trójek (12 pkt)\n" <<
		"   Czwórki   |          brak          | "; color(PRIMARY_COLOR); cout << "4 4 "; color(TEXT_COLOR); cout << "5 5 5  | suma czwórek (8 pkt)\n" <<
		"   Pi¹tki    |          brak          | 1 1 2 2 "; color(PRIMARY_COLOR); cout << "5 "; color(TEXT_COLOR); cout << " | suma pi¹tek (5 pkt)\n" <<
		"   Szóstki   |          brak          | 2 3 "; color(PRIMARY_COLOR); cout << "6 6 6 "; color(TEXT_COLOR); cout << " | suma szóstek (18 pkt)\n" <<
		"-------------|------------------------|------------|---------------------\n" <<
		" 3 jednakowe | trzy jednakowe koœci   | "; color(PRIMARY_COLOR); cout << "4 4 "; color(TEXT_COLOR); cout << "3 "; color(PRIMARY_COLOR); cout << "4 "; color(TEXT_COLOR); cout << "6  | suma oczek (17 pkt)\n" <<
		" 4 jednakowe | cztery jednakowe koœci | "; color(PRIMARY_COLOR); cout << "2 2 "; color(TEXT_COLOR); cout << "6 "; color(PRIMARY_COLOR); cout << "2 2 "; color(TEXT_COLOR); cout << " | suma oczek (15 pkt)\n"; color(TEXT_COLOR); cout <<
		"     Full    |     trójka i para      | "; color(PRIMARY_COLOR); cout << "6 6 4 4 4 "; color(TEXT_COLOR); cout << " | zawsze 25 pkt\n"; color(TEXT_COLOR); cout <<
		"  Ma³y strit |    4 w kolejnoœci      | 5 "; color(PRIMARY_COLOR); cout << "2 3 4 5 "; color(TEXT_COLOR); cout << " | zawsze 30 pkt\n"; cout <<
		"  Du¿y strit |    5 w kolejnoœci      | "; color(PRIMARY_COLOR); cout << "1 2 3 4 5 "; color(TEXT_COLOR); cout << " | zawsze 40 pkt\n"; cout <<
		"   Genera³   | 5 takich samych oczek  | "; color(PRIMARY_COLOR); cout << "2 2 2 2 2 "; color(TEXT_COLOR); cout << " | zawsze 50 pkt\n"; cout <<
		"    Szansa   |          brak          | 1 1 3 3 5 "; color(TEXT_COLOR); cout << " | suma oczek (13 pkt)\n";
}

void Game::initGame() {
	gameplay();
}

void dicesList(map<int, int> resultsSet, int selectedDice) {
	// indexes
	for (int i = 0; i < resultsSet.size(); i++) {
		if (resultsSet[i] == 0) { // do not show 0
			continue;
		}
		color(NS_TEXT_COLOR);
		cout << "\t" << "(" << i << ")";
		color(TEXT_COLOR);
	}
	cout << "\n";
	// values
	for (int i = 0; i < resultsSet.size(); i++) {
		if (resultsSet[i] == 0) { // do not show 0
			continue;
		}
		if (selectedDice == i) {
			color(PRIMARY_COLOR);
		}
		else {
			color(NS_TEXT_COLOR);
		}
		cout << "\t " << resultsSet[i];
		color(TEXT_COLOR);
	}
}

int sumValuesWithKey(int key, vector<int> vec) {
	int sum = 0;
	for (auto& el : vec) {
		if (el == key) {
			sum += el;
		}
	}
	return sum;
}

int sumXSameValues(vector<int> vec, int x) {
	for (auto& el : vec) {
		int number = std::count(vec.begin(), vec.end(), el);
		if (number == x) {
			return el * x;
		}
	}
	return 0;
}

bool areXInOrder(vector<int> vec, int x) {
	int sum = 1;
	int numOfCopies = 1;
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i + 1] == vec[i] + 1) {
			sum++;
			if (sum == x) {
				return true;
			}
		}
		else if (vec[i + 1] == vec[i]) {
			numOfCopies--;
			if (numOfCopies < 0) {
				return false;
			}
		}
		else {
			sum = 1;
		}
	}
	return false;
}

bool areXUniqueValues(vector<int> vec, int x) {
	set<int> unique;
	for (auto& el : vec) {
		unique.insert(el);
	}
	if (unique.size() == x) {
		return true;
	}
	return false;
}

bool isFull(vector<int>vec, int x) {
	if (!areXUniqueValues(vec, x))
		return false;
	// two variables with 2 unique numbers from vec
	int firstNum = vec[0];
	int secondNum = 0;
	for (auto& el : vec) {
		if (el != firstNum)
			secondNum = el;
	}
	int numOfFirstNums = std::count(vec.begin(), vec.end(), firstNum);
	int numOfSecondNums = std::count(vec.begin(), vec.end(), secondNum);
	
	if ((numOfFirstNums == 2 && numOfSecondNums == 3) || (numOfFirstNums == 3 && numOfSecondNums == 2))
		return true;
	return false;
}

int sumAllValues(vector<int> vec) {
	int sum = 0;
	for (auto& el : vec) {
		sum += el;
	}
	return sum;
};

void pointsTable(vector<int> finalDices, Participant& player, int round) {
	system("cls");
	playerCall(round, player);
	cout << " Twoje koœci: ";
	for (auto& el : finalDices) {
		cout << el << ", ";
	}
	cout << "\n\n Wybierz uk³ad:\n\n";
	cout << " Nazwa\t    Punkty do zdobycia\n-------------------------------\n";

	/*
	vector<string> pointsTableVec;
	if (player.isOnesEmpty()) { pointsTableVec.push_back(" Jedynki:\t\t " + to_string(sumValuesWithKey(1, finalDices)) + "\n"); }
	if (player.isTwosEmpty()) { pointsTableVec.push_back(" Dwójki:\t\t " + to_string(sumValuesWithKey(2, finalDices)) + "\n"); }
	if (player.isThreesEmpty()) { pointsTableVec.push_back(" Trójki:\t\t " + to_string(sumValuesWithKey(3, finalDices)) + "\n"); }
	if (player.isFoursEmpty()) { pointsTableVec.push_back(" Czwórki:\t\t " + to_string(sumValuesWithKey(4, finalDices)) + "\n"); }
	if (player.isFivesEmpty()) { pointsTableVec.push_back(" Pi¹tki:\t\t " + to_string(sumValuesWithKey(5, finalDices)) + "\n"); }
	if (player.isSixesEmpty()) { pointsTableVec.push_back(" Szóstki:\t\t " + to_string(sumValuesWithKey(6, finalDices)) + "\n"); }
	if (player.isTripleEmpty()) { pointsTableVec.push_back(" 3 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 3)) + "\n"); }
	if (player.isQuadrupleEmpty()) { pointsTableVec.push_back(" 4 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 4)) + "\n"); }
	if (player.isFullEmpty()) { pointsTableVec.push_back(areXUniqueValues(finalDices, 2) ? " Full:\t\t\t 25\n" : " Full:\t\t\t 0\n"); }
	if (player.isSmallStritEmpty()) { pointsTableVec.push_back(areXInOrder(finalDices, 4) ? " Ma³y strit:\t\t 30\n" : " Ma³y strit:\t\t 0\n"); }
	if (player.isBigStritEmpty()) { pointsTableVec.push_back(areXInOrder(finalDices, 5) ? " Du¿y strit:\t\t 40\n" : " Du¿y strit:\t\t 0\n"); }
	if (player.isGeneralEmpty()) { pointsTableVec.push_back(areXUniqueValues(finalDices, 1) ? " Genera³:\t\t 50\n" : " Genera³:\t\t 0\n"); }
	if (player.isChanceEmpty()) { pointsTableVec.push_back(" Szansa:\t\t " + to_string(sumAllValues(finalDices)) + "\n"); }
	*/
	//vector<int> pointsTableSelectedIds;
	//if (player.isOnesEmpty()) { pointsTableVec.insert({ 0, " Jedynki:\t\t " + to_string(sumValuesWithKey(1, finalDices)) + "\n" }); }
	//if (player.isTwosEmpty()) { pointsTableVec.insert({ 1, " Dwójki:\t\t " + to_string(sumValuesWithKey(2, finalDices)) + "\n"}); }
	//if (player.isThreesEmpty()) { pointsTableVec.insert({ 2, " Trójki:\t\t " + to_string(sumValuesWithKey(3, finalDices)) + "\n"}); }
	//if (player.isFoursEmpty()) { pointsTableVec.insert({ 3, " Czwórki:\t\t " + to_string(sumValuesWithKey(4, finalDices)) + "\n"}); }
	//if (player.isFivesEmpty()) { pointsTableVec.insert({ 4, " Pi¹tki:\t\t " + to_string(sumValuesWithKey(5, finalDices)) + "\n"}); }
	//if (player.isSixesEmpty()) { pointsTableVec.insert({ 5, " Szóstki:\t\t " + to_string(sumValuesWithKey(6, finalDices)) + "\n"}); }
	//if (player.isTripleEmpty()) { pointsTableVec.insert({ 6, " 3 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 3)) + "\n"}); }
	//if (player.isQuadrupleEmpty()) { pointsTableVec.insert({ 7, " 4 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 4)) + "\n"}); }
	//if (player.isFullEmpty()) { 
	//	areXUniqueValues(finalDices, 2) ? pointsTableVec.insert({ 8, " Full:\t\t\t 25\n"}) : pointsTableVec.insert({ 8, " Full:\t\t\t 0\n" }); }
	//if (player.isSmallStritEmpty()) { 
	//	areXInOrder(finalDices, 4) ? pointsTableVec.insert({ 9, " Ma³y strit:\t\t 30\n"}) : pointsTableVec.insert({ 9, " Ma³y strit:\t\t 0\n" }); }
	//if (player.isBigStritEmpty()) { 
	//	areXInOrder(finalDices, 5) ? pointsTableVec.insert({ 10, " Du¿y strit:\t\t 40\n"}) : pointsTableVec.insert({ 10, " Du¿y strit:\t\t 0\n" }); }
	//if (player.isGeneralEmpty()) { 
	//	areXUniqueValues(finalDices, 1) ? pointsTableVec.insert({ 11, " Genera³:\t\t 50\n"}) : pointsTableVec.insert({ 11, " Genera³:\t\t 0\n" }); }
	//if (player.isChanceEmpty()) { pointsTableVec.insert({ 12, " Szansa:\t\t " + to_string(sumAllValues(finalDices)) + "\n"}); }

	map<int, string> pointsALLTableVec;
	pointsALLTableVec.insert({ 0, " Jedynki:\t\t " + to_string(sumValuesWithKey(1, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 1, " Dwójki:\t\t " + to_string(sumValuesWithKey(2, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 2, " Trójki:\t\t " + to_string(sumValuesWithKey(3, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 3, " Czwórki:\t\t " + to_string(sumValuesWithKey(4, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 4, " Pi¹tki:\t\t " + to_string(sumValuesWithKey(5, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 5, " Szóstki:\t\t " + to_string(sumValuesWithKey(6, finalDices)) + "\n" });
	pointsALLTableVec.insert({ 6, " 3 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 3)) + "\n" });
	pointsALLTableVec.insert({ 7, " 4 jednakowe:\t\t " + to_string(sumXSameValues(finalDices, 4)) + "\n" });
		isFull(finalDices, 2) ? pointsALLTableVec.insert({ 8, " Full:\t\t\t 25\n" }) : pointsALLTableVec.insert({ 8, " Full:\t\t\t 0\n" });
		areXInOrder(finalDices, 4) ? pointsALLTableVec.insert({ 9, " Ma³y strit:\t\t 30\n" }) : pointsALLTableVec.insert({ 9, " Ma³y strit:\t\t 0\n" });
		areXInOrder(finalDices, 5) ? pointsALLTableVec.insert({ 10, " Du¿y strit:\t\t 40\n" }) : pointsALLTableVec.insert({ 10, " Du¿y strit:\t\t 0\n" });
		areXUniqueValues(finalDices, 1) ? pointsALLTableVec.insert({ 11, " Genera³:\t\t 50\n" }) : pointsALLTableVec.insert({ 11, " Genera³:\t\t 0\n" });
	pointsALLTableVec.insert({ 12, " Szansa:\t\t " + to_string(sumAllValues(finalDices)) + "\n" });

	int selected = 0;
	bool updated = true;
	bool selecting = true;
	int numChoices = pointsALLTableVec.size();

	// making sure that selected starts with avalilable value
	while (true) {
		if (!std::count(player.pointsTableSelectedIds.begin(), player.pointsTableSelectedIds.end(), selected))
			break;
		else {
			selected++;
		}

		if (selected > numChoices) {
			cout << "Dziwne, ta sytuacja nigdy nie powinna siê wydarzyæ. Wygl¹da na to, ¿e wykorzysta³eœ wszystkie pola z tablicy a mimo to gra siê nie zakoñczy³a...\n WyjdŸ i rozpocznij grê od nowa...\n\n";
			break;
		}
	}

	// printing the list with options
	int i = 0;
	for (auto& item : pointsALLTableVec) {
		if (i == selected) 
			color(PRIMARY_COLOR);
		else color(TEXT_COLOR);

		if (std::count(player.pointsTableSelectedIds.begin(), player.pointsTableSelectedIds.end(), i)) {
			color(NS_TEXT_COLOR);
		}
		cout << item.second;
		i++;
	}
	char key;
	do {
		switch ((key = _getch())) { //Check inputed key character.
		case KEY_UP:
			if (selected > 0) {
				--selected;
				while (true) {
					if (selected < 0) {
						selected = numChoices - 1;
					}

					if (std::count(player.pointsTableSelectedIds.begin(), player.pointsTableSelectedIds.end(), selected)) {
						--selected;
					}
					else {
						break;
					}
				}
				updated = true;
			}
			break;
		
		case KEY_DOWN:
			if (selected < numChoices - 1) {
				++selected;
				while (true) {
					if (selected > numChoices - 1) {
						selected = 0;
					}

					if (std::count(player.pointsTableSelectedIds.begin(), player.pointsTableSelectedIds.end(), selected)) {
						++selected;
					}
					else {
						break;
					}
				}
				updated = true;
			}
			break;
		case KEY_ENTER:
			selecting = false;
			break;
		default: break;
		}

		if (updated) {  //Lets us know what the currently selected value is.
			system("cls");
			color(TEXT_COLOR);
			playerCall(round, player);
			cout << " Twoje koœci: ";
			for (auto& el : finalDices) {
				cout << el << ", ";
			}
			cout << "\n\n Wybierz uk³ad:\n\n";
			cout << " Nazwa\t    Punkty do zdobycia\n-------------------------------\n";
			i = 0;
			for (auto& item : pointsALLTableVec) {
				if (i == selected)
					color(PRIMARY_COLOR);
				else color(TEXT_COLOR);

				if (std::count(player.pointsTableSelectedIds.begin(), player.pointsTableSelectedIds.end(), i)) {
					color(NS_TEXT_COLOR);
				}
				cout << item.second;
				i++;
			}
			updated = false;
		}

		/*cout << "\n\n";
		for (auto& el : player.pointsTableSelectedIds) {
			cout << el << ", ";
		}
		cout << "   ::: selected = " << selected;*/
	} while (selecting);

	// NAPRAWIC SYSTEM... NIE UWZGLEDNIA WYBRANYCH POZYCJI
	if (selected == 0) {
		player.setOnes(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
	}
	else if (selected == 1) {
		player.setTwos(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
	}
	else if (selected == 2) {
		player.setThrees(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 3) {
		player.setFours(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 4) {
		player.setFives(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 5) {
		player.setSixes(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 6) {
		player.setTriple(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 7) {
		player.setQuadruple(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 8) {
		player.setFull(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 9) {
		player.setSmallStrit(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 10) {
		player.setBigStrit(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 11) {
		player.setGeneral(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
	else if (selected == 12) {
		player.setChance(finalDices);
		player.pointsTableSelectedIds.push_back(selected);
		}
}

void Game::roundHandler(Participant& player) { // one full round

	map<int, int> resultsSet;		// set of current points of dices and its indexes
	map<int, int> selectedDices;	// selected numbers to stay and its indexes
	map<int, int> finalSet;			// set of final points on dices the player wants
	vector<int> finalDices;			// finalSet values but in vector

	for (int attempt = 0; attempt < 3; attempt++) { // all chances to roll
		system("cls");
		playerCall(round, player);
		controlsHelper();
		cout << " Kliknij Enter aby rzuciæ koœæmi\n\n";
		resultsSet.clear();
		while (true) {
			if (_getch() == KEY_ENTER) {
				for (int i = selectedDices.size(); i < numOfDices; i++) { // all dices left (gives 0 if has been already selected)
					resultsSet.insert(std::pair<int, int>(i, randomNum(1, 1)));
				}
				break;
			}
		}
		
		char key;
		int selectedDice = numOfDices - 1;
		bool selecting = true;
		bool updated = false;

		dicesList(resultsSet, selectedDice);

		cout << "\n\n Wybrane do zachowania ( (id) cyfra ):\n ";
		for (auto& el : selectedDices) {
			color(NS_TEXT_COLOR); cout << "(" << el.first + 1 << ") "; color(TEXT_COLOR); cout << el.second << ", ";
		}

		do {
			switch ((key = _getch())) { //Check inputed key character.
			case KEY_LEFT:
				if (selectedDice > finalSet.size()) {
					--selectedDice;
					updated = true;
				}
				break;
			case KEY_RIGHT:
				if (selectedDice < numOfDices - 1) {
					++selectedDice;
					updated = true;
				}
				break;
			case KEY_ENTER:
				if (selectedDices.count(selectedDice)) { // already exists
					selectedDices.erase(selectedDice);
				}
				else {
					selectedDices.insert(std::pair<int, int>(selectedDice, resultsSet[selectedDice]));
				}
				updated = true;
				break;
			case KEY_HELP:
				cheatSheet();
				break;
			case KEY_END_TURN:
				finalSet = selectedDices;
				finalSet.insert(resultsSet.begin(), resultsSet.end());
				selecting = false;
				attempt = 3;
				break;
			case KEY_ROLL_AGAIN:
				int index = 0;
				for (auto& el : selectedDices) {
					finalSet.insert(std::pair<int, int>(index, el.second));
					index++;
				}
				selectedDices = finalSet;
				selecting = false;

				if (selectedDices.size() >= numOfDices) {
					attempt = 3;
				}
				break;
			//default: break;
			}

			if (updated) {  //Lets us know what the currently selected value is.
				system("cls");
				playerCall(round, player);
				controlsHelper();
				cout << " Kliknij Enter aby rzuciæ koœæmi\n\n";
				dicesList(resultsSet, selectedDice);
				cout << "\n\n Wybrane do zachowania ( (id) cyfra ):\n ";
				for (auto& el : selectedDices) {
					color(NS_TEXT_COLOR); cout << "(" << el.first + 1 << ") "; color(TEXT_COLOR); cout << el.second << ", ";
				}
				updated = false;
			}
		} while (selecting);
	}
	finalSet = selectedDices;
	finalSet.insert(resultsSet.begin(), resultsSet.end());

	for (auto& el : finalSet) {
		finalDices.push_back(el.second);
	}

	pointsTable(finalDices, player, round);
}

void Game::gameFinished() {
	system("cls");
	int maxPoints = 0;
	int numberOfWinners;
	vector<int> playersPoints;

	color(PRIMARY_COLOR);
	cout << "\n\t W Y N I K I   G R Y\n";
	color(TEXT_COLOR);
	cout <<	"\t=====================\n\n" <<
		" Punktacja: \n\n";
	for (auto& player : players) {
		color(PRIMARY_COLOR);
		cout << " " << player.getNickname();
		color(TEXT_COLOR);
		cout << ": " << player.getAllPoints() << " pkt.\n";
	}

	for (auto& player : players) {
		playersPoints.push_back(player.getAllPoints());
	}

	std::sort(playersPoints.begin(), playersPoints.end());
	maxPoints = playersPoints[playersPoints.size() - 1];

	if (std::count(playersPoints.begin(), playersPoints.end(), maxPoints) > 1) {
		// many Players have won
		cout << "\n Zwyciê¿aj¹ gracze ";
		color(PRIMARY_COLOR);
		for (auto& player : players) {
			if (player.getAllPoints() == maxPoints)
				cout << player.getNickname() << ", ";
		}
		color(TEXT_COLOR);
		cout << "maj¹c t¹ sam¹ iloœæ punktów!";
	}
	else {
		// one Player has won
		for (auto& player : players) {
			if (player.getAllPoints() == maxPoints) {
				cout << "\n Zwyciê¿a gracz ";
				color(PRIMARY_COLOR);
				cout << player.getNickname();
				color(TEXT_COLOR);
				cout << "!\n";
			}
		}
	}

	cout << "\n Wciœnij Enter aby wyjœæ do Menu...";
	while(true) {
		if (KEY_ENTER == _getch())
			break;
	}

	// At this point the whole Game ends and program continues in the Interface class after initGame() method
}

void Game::gameplay() {	// plays the game from start to end

	bool gameIsActive = true;

	while (gameIsActive) {
		round++;
		for (auto& player : players) {
			if (!player.hasPlayerFinished())
				roundHandler(player);
			else {
				gameIsActive = false;
			}
		}
	}
	gameFinished();
}