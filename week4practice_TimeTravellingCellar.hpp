#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class TimeTravellingCellar
{
	int helper(std::vector<int> profit, std::vector<int> decay) {
		int max = 0;
		for (unsigned int i = 0; i < profit.size(); ++i)
		{
			for (unsigned int j = 0; j < profit.size(); ++j)
			{
				if (i != j)
				{
					int different = profit[i] - decay[j];
					if (different > max)
					{
						max = different;
					}
				}
			}
		}
		return max;
	}
public:
	int determineProfit(std::vector<int> profit, std::vector<int> decay) {
		return helper(profit, decay);
	}
};