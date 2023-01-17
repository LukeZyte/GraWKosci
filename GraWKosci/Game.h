#pragma once

#include "Participant.h"
#include "Globals.h"
#include "Interface.h"

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <Windows.h>
#include <conio.h>		// _getch()
#include <random>
#include <algorithm>	// std::count, std::sort

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::to_string;

class Game
{
protected:
	int numOfDices = 5;
	int numOfParticipants;
	vector<Participant> players;	// vector of all participants
	int round = 0;					// current round

public:
	Game(vector<Participant> _players) : players(_players) {
		numOfParticipants = players.size();
	};

	void initGame();
	void gameplay();
	void roundHandler(Participant& player);
	void gameFinished();
};

