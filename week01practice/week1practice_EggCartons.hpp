#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class EggCartons
{
public:
	int minCartons(int n) {
		int iE = 0;
		int iS = 0;
		std::vector<int> memory;
		if (n < 6)
		{
			return -1;
		}
		/*int rem = n;
		while (rem >= 0) {
			rem = n - (iE * 8);
			if (rem % 6 == 0)
			{
				iS = rem/6;
				memory.push_back(iE+iS);
			}
			
			iE++;
		}*/

		for (int i = 0; i < 13; ++i)
		{
			int rem = n - (i * 8);
			if (rem < 0)
			{
				break;
			}
			if (rem % 6 == 0)
			{
				int sixC = rem / 6;
				memory.push_back(i+sixC);
			}
		}

		if (memory.empty())
		{
			return -1;
		}
		else {
			int min = memory[0];
			for (int i = 0; i < memory.size(); ++i)
			{
				if (min > memory[i])
				{
					min = memory[i];
				}
			}
			return min;
		}
	}
	
};