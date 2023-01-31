#include "Participant.h"

void Participant::setOnes(int points) {
	ones = points;
		allPoints += ones;
	}
	
	void Participant::setTwos(int points) {
		twos = points;
		allPoints += twos;
	}
	
	void Participant::setThrees(int points) {
		threes = points;
		allPoints += threes;
	}
	
	void Participant::setFours(int points) {
		fours = points;
		allPoints += fours;
	}
	
	void Participant::setFives(int points) {
		fives = points;
		allPoints += fives;
	}
	
	void Participant::setSixes(int points) {
		sixes = points;
		allPoints += sixes;
	}
	
	void Participant::setTriple(int points) {
		triple = points;
		allPoints += triple;
	}
	
	void Participant::setQuadruple(int points) {
		quadruple = points;
		allPoints += quadruple;
	}
	
	void Participant::setFull(int points) {
		full = points;
		allPoints += full;
	}
	
	void Participant::setSmallStrit(int points) {
		smallStrit = points;
		allPoints += smallStrit;
	}
	
	void Participant::setBigStrit(int points) {
		bigStrit = points;
		allPoints += bigStrit;
	}
	
	void Participant::setGeneral(int points) {
		general = points;
		allPoints += general;
	}
	
	void Participant::setChance(int points) {
		chance = points;
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