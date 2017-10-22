#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class StrangeComputer
{
	struct container
	{
		int indexOfDiff;
		char charOfDiff;
		container() : indexOfDiff(0) {}
	};

	void changeString(string &s, int index, char c) {
		for (unsigned int i = index; i < s.size(); ++i)
		{
			s[i] = c;
		}
	}
	container findFirstDiff(string str1, string str2) {
		container c1;
		for (unsigned int i = 0; i < str1.size(); ++i) {
			if (str1[i] != str2[i]) {
				c1.indexOfDiff = (int)i;
				c1.charOfDiff = str2[i];
				break;
			}
		}
		return c1;
	}
	int helper(string str) {
		string base;
		base.assign(str.size(), '0');

		container c2;
		int result = 0;
		while (base != str) {
			c2 = findFirstDiff(base, str);
			changeString(base, c2.indexOfDiff, c2.charOfDiff);
			result++;
		}
		return result;
	}
public:
	int setMemory(string mem) {
		return helper(mem);
	}
	
};