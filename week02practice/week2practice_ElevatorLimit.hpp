#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ElevatorLimit
{
public:
	std::vector<int> getRange(std::vector<int> enter, std::vector<int> exit, int physicalLimit) {
		std::vector<int> result;
		std::vector<int> exitEach;
		std::vector<int> enterEach;
		int numInElevator = 0;
		for (int i = 0; i < enter.size(); ++i)
		{
			if (enter[i] > physicalLimit || exit[i] > physicalLimit)
			{
				return result;
			}
			numInElevator -= exit[i];
			exitEach.push_back(numInElevator);
			numInElevator += enter[i];
			enterEach.push_back(numInElevator);
		}

		int max = enterEach[0];
		int min = exitEach[0];
		for (int i = 1; i < enterEach.size(); ++i)
		{
			if (max < enterEach[i])
				max = enterEach[i];
			if (min > exitEach[i])
				min = exitEach[i];
		}

		int range = max - min;
		min = abs(min);
		if (physicalLimit < physicalLimit - max)
			max = physicalLimit;
		else {
			max = physicalLimit - max;
		}
		if(range > physicalLimit || min > max)
		{
			return result;
		}
		//if (min > physicalLimit || max > physicalLimit)
		//{
		//	return result;
		//}
		result.push_back(min);
		result.push_back(max);

		return result;
	}
	
};