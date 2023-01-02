#pragma once

#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;

class Player
{
	string nickname;
	int wins;

public: 
	Player(string _nickname) : nickname(_nickname), wins(0) {};

	string getNickname() {
		return nickname;
	}
};

