#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class Arrows
{
	bool helper(string str) {
		if (str[0] == '<')
		{
			for (int i = 1; i < str.size(); ++i)
			{
				for (int j = 1; j < str.size(); ++j)
				{
					if (str[i] != str[j])
					{
						return false;
					}
					if ((str[i] != '-') && (str[j] != '='))
					{
						return false;
					}
				}
			}
			return true;
		}
		else if (str[str.size() - 1] == '>')
		{
			for (int i = 0; i < str.size() - 1; ++i)
			{
				for (int j = 0; j < str.size() - 1; ++j)
				{
					if (str[i] != str[j])
					{
						return false;
					}
					if ((str[i] != '-') && (str[j] != '='))
					{
						return false;
					}
				}
			}
			return true;
		} else {
			return false;
		}
	}
public:
	int longestArrow(string s) {
		int result = -1;
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j <= s.size() - i; ++j)
			{
				string temp = s.substr(i, j);
				if (helper(temp))
				{
					result = max(result, (int)temp.size());
				}
			}
		}
		return result;
	}
	
};