#pragma once

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using std::string;
using std::vector;
using std::set;

class Participant
{
	string nickname;

	// Points from each category; 99 means its empty
	int ones = 99;
	int twos = 99;
	int threes = 99;
	int fours = 99;
	int fives = 99;
	int sixes = 99;

	int triple = 99;
	int quadruple = 99;
	int full = 99;
	int smallStrit = 99;
	int bigStrit = 99;
	int general = 99;
	int chance = 99;

	// End result
	int allPoints = 0;

public:
	Participant(string _nickname) : nickname(_nickname) {}

	string getNickname() {
		return nickname;
	}

	// vector with already taken points from the table
	vector<int> pointsTableSelectedIds;

	void setOnes(vector<int> dices);
	void setTwos(vector<int> dices);
	void setThrees(vector<int> dices);
	void setFours(vector<int> dices);
	void setFives(vector<int> dices);
	void setSixes(vector<int> dices);
	void setTriple(vector<int> dices);
	void setQuadruple(vector<int> dices);
	void setFull(vector<int> dices);
	void setSmallStrit(vector<int> dices);
	void setBigStrit(vector<int> dices);
	void setGeneral(vector<int> dices);
	void setChance(vector<int> dices);

	// returns true if elements = 99
	bool isOnesEmpty();
	bool isTwosEmpty();
	bool isThreesEmpty();
	bool isFoursEmpty();
	bool isFivesEmpty();
	bool isSixesEmpty();

	bool isTripleEmpty();
	bool isQuadrupleEmpty();
	bool isFullEmpty();
	bool isSmallStritEmpty();
	bool isBigStritEmpty();
	bool isGeneralEmpty();
	bool isChanceEmpty();

	bool hasPlayerFinished();
	int getAllPoints();
};

