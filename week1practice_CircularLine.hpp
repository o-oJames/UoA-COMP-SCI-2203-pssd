#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CircularLine
{
public:
	int longestTravel(std::vector<int> t) {
		int round = 0;
		int i =0;
		while (i < t.size()) {
			int j = i + 1;
			while (j < t.size()) {
				int first = 0;
				int second = 0;
				for (int k = i; k < j; ++k)
				{
					first += t[k];
				}
				for (int k = j; k < t.size(); ++k)
				{
					second += t[k];
				}
				for (int k = 0; k < i; ++k)
				{
					second += t[k];
				}
				round = max(round, min(first, second));
				j++;
			}
			i++;
		}
		return round;
	}
};