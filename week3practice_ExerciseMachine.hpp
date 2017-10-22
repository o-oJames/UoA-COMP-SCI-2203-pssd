#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class ExerciseMachine
{
	int getSeconds(string t) {
		std::vector<int> time;
		string puc = ":";
		size_t pos = 0;
		string temp;
		while ((pos = t.find(puc)) != string::npos) {
			string temp = t.substr(0, pos);
			istringstream iss(temp);
			int num = 0;
			iss >> num;
			time.push_back(num);
			t.erase(0, pos + puc.length());
		}
		istringstream iss(t);
		int num = 0;
		iss >> num;
		time.push_back(num);

		int result = 0;
		int index = 1;
		for (int i : time) {
			if (index == 1) {
				result += i * 60 * 60;
			}
			if (index == 2) {
				result += i * 60;
			}
			if (index == 3) {
				result += i;
			}
			index++;
		}
		return result;
	}
public:
	int getPercentages(string time){
		int sec = getSeconds(time);
		int result = 0;
		for (int i = 0; i < 100; ++i)
		{
			if ( (sec * i) % 100 == 0 )
			{
				result ++;
			}
		}
		return result-1;
	}
	
};