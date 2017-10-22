#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class MagicSpell
{
public:
	string fixTheSpell(string spell) {
		std::vector<char> id;
		std::vector<char> reverse;
		for (int i = 0; i < spell.size(); ++i) {
			if (spell[i] == 'A' || spell[i] == 'Z') {
				id.push_back(spell[i]);
				spell[i] = '-';
			} 

		}
		for (int i = id.size() - 1; i >= 0; --i) {
			reverse.push_back(id[i]);
		}
		for (int i = 0; i < spell.size(); ++i) {
			if (spell[i] == '-') {
				spell[i] = reverse[0];
				reverse.erase(reverse.begin());
			}
		}
		return spell;
	}
	
};