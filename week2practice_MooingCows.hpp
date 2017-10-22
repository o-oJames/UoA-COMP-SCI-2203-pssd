#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class MooingCows
{
		int cache;
public:
	int dissatisfaction(std::vector<string> farmland) {
		int result = 50 * 50 * 2499;
		int strSize = farmland[0].size();
		int vecSize = farmland.size();
		for (int i = 0; i < vecSize; ++i)
		{
			for (int j = 0; j < strSize; ++j)
			{
				if (farmland[i].at(j) == 'C')
				{
					cache = 0;
					for (int k = 0; k < vecSize; ++k)
					{
						for (int l = 0; l < strSize; ++l)
						{
							if (farmland[k].at(l) == 'C')
							{
								cache += ( pow((i - k), 2) + pow((j - l), 2) );
							}
						}
					}
					result = min(result, cache);
				}
			}
		}
		return result;
	}
	
};

/*loop through all cows and simulate what would happen if that cow mooed, 
and take the minimum of all of those. At most the farmland can be 50 x 50 
squares large, which means that there can be at most 2500 cows on the land. 
This means that 2500 x 2499 distance calculations need to be done.*/