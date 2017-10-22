#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class FracCount
{
	int gcdNum(int n, int d) {
		while (n != d) {
			if (n > d) {
				n -= d;
			} else {
				d -= n;
			}
		}
		return n;
	}
	void init(int &n, int &d) {
		int findGCD = gcdNum(n, d);
		if (findGCD > 1) {
			n = n / findGCD;
			d = d / findGCD;
		}
	}
	int helper(int n, int d) {
		init(n, d);
		int result = 0;
		for (int i = 2; i <= d; ++i) {
			for (int j = 1; j < i; ++j) {
				if (gcdNum(j, i) == 1)
				{
					result++;
				}
				if ((i == d) && (j == n))
				{
					break;
				}
			}
		}
		return result;
	}

public:
	int position(int numerator, int denominator) {
		return helper(numerator, denominator);
	}
	
};