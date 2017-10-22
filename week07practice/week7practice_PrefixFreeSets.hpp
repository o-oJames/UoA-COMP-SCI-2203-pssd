#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PrefixFreeSets
{
	bool lexi(string name1, string name2) {
		int count = 0;
		if (name1.size() > name2.size()) {
			count = name2.size();
		}
		else {count = name1.size();}
		for (int i = 0; i < count; ++i) {
			if (int(name1[i]) < int(name2[i])) {
				return 0;
			}
			else if (int(name1[i]) > int(name2[i])) {
				return 1;
			}
			if ( i == count-1) {
				if (name1.size() > name2.size()) {
					return 1;
				}
				//else return 0;
			}
		}
		return 0;
	}

	void lexiVec(std::vector<string> &words) {
		for (int i = 0; i < words.size()-1; ++i)
		{
			int imin = i;
			for (int j = i+1; j < words.size(); ++j)
			{
				if (lexi(words[j], words[imin]) == 0) {
					imin = j;
				}
			}
			if (imin != i)
			{
				swap(words[i], words[imin]);
			}
		}
	}


	bool compare(string prefix, string word) {
		int match = 0;
		for (int i = 0; i < prefix.size(); ++i) {
			if (prefix[i] == word[i]) {
				match++;
			}
		}
		if (match == prefix.size()) {
			return true;
		}
		return false;
	}
	std::vector<string> result;
	void init() {
		result.clear();
		result.shrink_to_fit();
	}
public:
	int maxElements(std::vector<string> words) {
		init();
		if (words.size() < 2)
		{
			return 1;
		}
		lexiVec(words);
		for (int i = 0; i < words.size()-1; ++i)
		{
			if (!compare(words[i], words[i+1]))
			{
				result.push_back(words[i]);
			}
		}
		return result.size()+1;
	}
	
};