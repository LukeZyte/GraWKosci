#include "Participant.h"

#include <iostream>

int sumValuesWithKey2(int key, vector<int> vec) {
	int sum = 0;
	for (auto& el : vec) {
		if (el == key) {
			sum += el;
		}
	}
	return sum;
}

int sumXSameValues2(vector<int> vec, int x) {
	for (auto& el : vec) {
		int number = std::count(vec.begin(), vec.end(), el);
		if (number == x) {
			return el * x;
		}
	}
	return 0;
}

bool areXInOrder2(vector<int> vec, int x) {
	int sum = 1;
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i + 1] == vec[i] + 1) {
			sum++;
			if (sum == x) {
				return true;
			}
		}
		else {
			sum = 1;
		}
	}
	return false;
}

bool areXUniqueValues2(vector<int> vec, int x) {
	set<int> unique;
	for (auto& el : vec) {
		unique.insert(el);
	}
	if (unique.size() == x) {
		return true;
	}
	return false;
}

int sumAllValues2(vector<int> vec) {
	int sum = 0;
	for (auto& el : vec) {
		sum += el;
	}
	return sum;
};

void Participant::setOnes(vector<int> dices) {
	ones = sumValuesWithKey2(1, dices);
	allPoints += ones;
}

void Participant::setTwos(vector<int> dices) {
	twos = sumValuesWithKey2(2, dices);
	allPoints += twos;
}

void Participant::setThrees(vector<int> dices) {
	threes = sumValuesWithKey2(3, dices);
	allPoints += threes;
}

void Participant::setFours(vector<int> dices) {
	fours = sumValuesWithKey2(4, dices);
	allPoints += fours;
}

void Participant::setFives(vector<int> dices) {
	fives = sumValuesWithKey2(5, dices);
	allPoints += fives;
}

void Participant::setSixes(vector<int> dices) {
	sixes = sumValuesWithKey2(6, dices);
	allPoints += sixes;
}

void Participant::setTriple(vector<int> dices) {
	triple = sumXSameValues2(dices, 3);
	allPoints += triple;
}

void Participant::setQuadruple(vector<int> dices) {
	quadruple = sumXSameValues2(dices, 3);
	allPoints += quadruple;
}

void Participant::setFull(vector<int> dices) {
	if (areXUniqueValues2(dices, 2))
		full = 25;
	else 
		full = 0;

	allPoints += full;
}

void Participant::setSmallStrit(vector<int> dices) {
	if (areXInOrder2(dices, 4))
		smallStrit = 30;
	else smallStrit = 0;

	allPoints += smallStrit;
}

void Participant::setBigStrit(vector<int> dices) {
	if (areXInOrder2(dices, 5))
		bigStrit = 40;
	else bigStrit = 0;

	allPoints += bigStrit;
}

void Participant::setGeneral(vector<int> dices) {
	if (areXUniqueValues2(dices, 1))
		general = 40;
	else general = 0;

	allPoints += general;
}

void Participant::setChance(vector<int> dices) {
	chance = sumAllValues2(dices);
	allPoints += chance;
}


bool Participant::isOnesEmpty() {
	if (ones == 99) {
		return true;
	}
	else { return false; }
};
bool Participant::isTwosEmpty() {
	if (twos == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isThreesEmpty(){
	if (threes == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isFoursEmpty() {
	if (fours == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isFivesEmpty() {
	if (fives == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isSixesEmpty() {
	if (sixes == 99) {
		return true;
		}
	else { return false; }
};

bool Participant::isTripleEmpty() {
	if (triple == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isQuadrupleEmpty() {
	if (quadruple == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isFullEmpty() {
	if (full == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isSmallStritEmpty() {
	if (smallStrit == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isBigStritEmpty() {
	if (bigStrit == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isGeneralEmpty() {
	if (general == 99) {
		return true;
		}
	else { return false; }
};
bool Participant::isChanceEmpty() {
	if (chance == 99) {
		return true;
		}
	else { return false; }
};

bool Participant::hasPlayerFinished() {
	if (ones == 99)
		return false;
	if (twos == 99)
		return false;
	if (threes == 99)
		return false;
	if (fours == 99)
		return false;
	if (fives == 99)
		return false;
	if (sixes == 99)
		return false;
	if (triple == 99)
		return false;
	if (quadruple == 99)
		return false;
	if (full == 99)
		return false;
	if (smallStrit == 99)
		return false;
	if (bigStrit == 99)
		return false;
	if (general == 99)
		return false;
	if (chance == 99)
		return false;

	return true;
}

int Participant::getAllPoints() {
	//allPoints = ones + twos + threes + fours + fives + sixes + triple + quadruple + full + smallStrit + bigStrit + general + chance;
	return allPoints;
}