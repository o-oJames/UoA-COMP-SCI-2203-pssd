#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class NiceOrUgly
{
	std::vector<std::vector<std::vector<int> > > cache;
	int endOfString;
	string globalS = "";
	void init() {
		std::vector<int> v1 (5, -1);
		std::vector<std::vector<int> > v2 (4, v1);
		cache.assign(endOfString, v2);
	}
	bool checkVowels(char letter) {
		if ((letter == 'A') || (letter == 'E') || (letter == 'I') || (letter == 'O') || (letter == 'U'))
		{
			return 1;
		}
		return 0;
	}
	int rec(int index, int vowels, int consonants) {
		if ((vowels >= 3) || (consonants >= 5)) {
			return 2;
		}
		if (index >= globalS.size()) {
			return 1;
		}
		if (cache[index][vowels][consonants] != -1) {
			return cache[index][vowels][consonants];
		}
		int result = 0;
		if ( globalS[index] == '?')
		{
			result |= rec(index + 1, vowels + 1, 0);
			result |= rec(index + 1, 0, consonants + 1);
		} else {
			if ( checkVowels(globalS[index]) ) {
				result |= rec(index + 1, vowels + 1, 0);
			} else {
				result |= rec(index + 1, 0, consonants + 1);
			}
		}
		return cache[index][vowels][consonants]= result;
	}
public:
	string describe(string s) {
		globalS = s;
		endOfString = s.size();
		init();
		int result = rec(0, 0, 0);
		if (result == 3)
		{
			return "42";
		}
		if (result == 1)
		{
			return "NICE";
		}
		return "UGLY";
	}
	
};