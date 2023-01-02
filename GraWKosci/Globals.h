#pragma once

#include <Windows.h>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <string>
//
//using std::vector;
//using std::set;
//using std::string;

#define KEY_UP 72
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_ENTER '\r'
#define KEY_END_TURN 'q'
#define KEY_ROLL_AGAIN 'e'
#define KEY_HELP 'h'

#define PRIMARY_COLOR 3
#define SECONDARY_COLOR 2
#define TEXT_COLOR 7
#define NS_TEXT_COLOR 8

void color(int color);
void boldFont();
void normalFont();

//int sumValuesWithKey(int key, vector<int> vec) {
//	int sum = 0;
//	for (auto& el : vec) {
//		if (el == key) {
//			sum += el;
//		}
//	}
//	return sum;
//}

//int sumXSameValues(vector<int> vec, int x);
//bool areXInOrder(vector<int> vec, int x);
//bool areXUniqueValues(vector<int> vec, int x);
//int sumAllValues(vector<int> vec);