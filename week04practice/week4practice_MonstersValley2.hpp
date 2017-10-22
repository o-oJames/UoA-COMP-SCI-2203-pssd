#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class MonstersValley2
{
	std::vector<unsigned long> globalDread;
	std::vector<int> globalPrice;
	int queueSize;
	void init(std::vector<unsigned long> &v, int size) {
		v.assign(size, 0);
	}
	int helper(int index, unsigned long curDread) {
		if (index == queueSize)
		{
			return 0;
		} else {
			int money = helper(index+1, curDread + globalDread[index]) + globalPrice[index];
			if (curDread >= globalDread[index])
			{
				money = min(money, helper(index+1, curDread));
			}
			return money;
		}
	}
public:
	int minimumPrice(std::vector<int> dread, std::vector<int> price) {
		queueSize = dread.size();
		init(globalDread, queueSize);
		for (unsigned int i = 0; i < dread.size(); ++i)
		{
			globalDread[i] = (long)dread[i];
		}
		globalPrice = price;
		return helper(0, 0);
	}
	
};