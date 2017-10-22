#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

class AzimuthMonitoring
{
public:
	bool checkDigit(string s) {
		if (isdigit(s[0])) {
			return 1;
		}
		else
			return 0;
	}
	int makeNum(string dg) {
		int result;
		istringstream iss(dg);
		iss >> result;
		return result;
	}

	int getAzimuth(std::vector<string> instructions) {
		std::vector<string> ins;
		int q = instructions.size();
		for (int i = 0; i < q; ++i)
		{
			if (instructions[i] == "TURN AROUND")
			{
				ins.push_back("TURN");
			}
			else {
				istringstream iss(instructions[i]);
				string temp;
				while (iss >> temp) {
					ins.push_back(temp);
				}
			}
		}
		std::vector<int> clockwise;
		for (int i = 0; i < ins.size()-1; ++i)
		{
			if (ins[i] == "LEFT")
			{
				if (checkDigit(ins[i+1]) == 0)
				{
					clockwise.push_back(270);
				}
				else {
					int num = makeNum(ins[i+1]);
					clockwise.push_back(360-num);
					if (i+1 == ins.size()-1)
					{
						ins.push_back("HALT");
					}
				}
			}
			else if (ins[i] == "RIGHT")
			{
				if (checkDigit(ins[i+1]) == 0)
				{
					clockwise.push_back(90);
				}
				else {
					int num = makeNum(ins[i+1]);
					clockwise.push_back(num);
					if (i+1 == ins.size()-1)
					{
						ins.push_back("HALT");
					}
				}
			}
			else if (ins[i] == "TURN")
			{
				clockwise.push_back(180);
			}
			else if (ins[i] == "HALT")
			{
				clockwise.push_back(0);
				int sum = 0;
				for (int i = 0; i < clockwise.size(); ++i)
				{
					sum += clockwise[i];
				}
				return sum % 360;
			}
		}


		string last = ins[ins.size()-1];
		if (last == "LEFT")
		{
			clockwise.push_back(270);
			int sum = 0;
			for (int i = 0; i < clockwise.size(); ++i)
			{
				sum += clockwise[i];
			}
			return sum % 360;
		}
		else if (last == "RIGHT")
		{
			clockwise.push_back(90);
			int sum = 0;
			for (int i = 0; i < clockwise.size(); ++i)
			{
				sum += clockwise[i];
			}
			return sum % 360;
		}
		else if (last == "TURN")
		{
			clockwise.push_back(180);
			int sum = 0;
			for (int i = 0; i < clockwise.size(); ++i)
			{
				sum += clockwise[i];
			}
			return sum % 360;
		}
		else if (last == "HALT")
		{
			int sum = 0;
			for (int i = 0; i < clockwise.size(); ++i)
			{
				sum += clockwise[i];
			}
			return sum % 360;
		}
	}

};
