#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PaternityTest
{
	bool curFather(string child, string mother, string man) {
		unsigned int match = 0;
		for (unsigned int i = 0; i < child.size(); ++i)
		{
			if (child[i] == man[i])
			{
				match++;
			}
			else if (child[i] != mother[i])
			{
				return 0;
			}
		}
		return (match >= child.size()/2 ? 1 : 0);
	}
public:
	std::vector<int> possibleFathers(string child, string mother, std::vector<string> men) {
		std::vector<int> result;
		for (unsigned int i = 0; i < men.size(); ++i)
		{
			if (curFather(child, mother, men[i]) == 1)
			{
				result.push_back(i);
			}
		}
		return result;
	}
};