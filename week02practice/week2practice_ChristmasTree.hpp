#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChristmasTree
{
	int factor(int n, int k) {
		int cal = 1;
		int i = 1;
		while ( i <= k) {
			cal = (cal * (n - i + 1)) / i;
			i++;
		}
		return cal;
	}

	long recursion(int level, int r, int g, int b, int num) {
		long singleLevel = 0;
		if (r < 0 || g < 0 || b < 0)
		{
			return 0;
		}
		if (num == level)
		{
			return 1;
		}
		if (num % 3 == 0)
		{
			long numOfFact = factor(num, num/3) * factor(num - num/3, (num - num/3)/2);
			singleLevel += recursion(level, r-num/3, g-num/3, b-num/3, num+1) * numOfFact;
		}
		if (num % 2 == 0)
		{
			long numOfFact = factor(num, num/2);
			singleLevel += recursion(level, r - num/2, g - num/2, b, num+1) * numOfFact;
			singleLevel += recursion(level, r - num/2, g, b - num/2, num+1) * numOfFact;
			singleLevel += recursion(level, r, g - num/2, b - num/2, num+1) * numOfFact;
		}
		singleLevel += recursion(level, r - num, g, b, num+1);
		singleLevel += recursion(level, r, g - num, b, num+1);
		singleLevel += recursion(level, r, g, b - num, num+1);

		return singleLevel;
	}

public:
	long decorationWays(int N, int red, int green, int blue) {
		long result = recursion(N+1, red, green, blue, 1);
		return result;
	}
};