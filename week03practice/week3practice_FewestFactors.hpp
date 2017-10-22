#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class FewestFactors
{
	int helper(std::vector<int> digits) {
		int result = 0;
		int val = 0;
		std::sort(digits.begin(), digits.end());
		int constrain = pow(10, 6);
		do {
			val = 0;
			stringstream transf;
			for (unsigned int i = 0; i < digits.size(); ++i)
			{
				transf << digits[i];
			}
			int temp;
			transf >> temp;
			int j = 1;
			while (j <= temp) {
				if (temp % j == 0)
				{
					val++;
				}
				j++;
			}
			if (val < constrain)
			{
				result = temp;
				constrain = val;
			}
		}while (std::next_permutation(digits.begin(), digits.end()));
		return result;
	}
public:
	int number(vector <int> digits) {
		return helper(digits);
	}
};