#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class SimpleCompressor
{
	struct bracket {
		int repeat;
		int openBr;
		int closeBr;
		bracket() : repeat(0),  
					openBr(-1),
					closeBr(-1) {}
	};
	bracket findLastOpBracket(string s) {
		bracket find;
		for (unsigned int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '[')
			{
				find.openBr = i;
			}
			if (s[i] == ']')
			{
				find.closeBr = i;
				break;
			}
		}
		if (find.openBr >= 0)
		{
			find.repeat = s[find.openBr + 1] - '0';
		}
		return find;
	}
	string repeatDeepest(string s) {
		bracket find;
		find = findLastOpBracket(s);
		if (find.openBr == -1)
		{
			return s;
		}

		string wholeStr;
		for (int i = 0; i < find.openBr; ++i)
		{
			wholeStr += s[i];
		}
		string repeatStr;
		for (int i = 0; i < find.repeat; ++i)
		{
			for (int j = find.openBr + 2; j <= find.closeBr - 1; ++j)
			{
				wholeStr += s[j];
			}
		}
		for (unsigned int i = find.closeBr+1; i < s.size(); ++i)
		{
			wholeStr += s[i];
		}
		return repeatDeepest(wholeStr);
	}

public:
	string uncompress(string data){
		return repeatDeepest(data);
	}
	
};