#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class Truckloads
{
	int helper(int n, int l) {
		if (n <= l)
		{
			return 1;
		}
		int part1 = n/2;
		int part2 = n - part1;
		return helper(part1, l) + helper(part2, l);
	}
public:
	int numTrucks(int numCrates, int loadSize) {
		return helper(numCrates, loadSize);
	}
	
};