#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class HandsShaking
{
	std::vector<long> cache;
	void init(){
		cache.assign(55, 0);
		cache[0] = 1;
		cache[1] = 1;
	}
	long effCatalan(long n) {
		if (n == 0 || n % 2 != 0)
		{
			return 0;
		}
		if (n == 2)
		{
			return 1;
		}
		else {
			for (int i = 2; i <= n; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					cache[i] += cache[j] * cache[i - j - 1];
				}
			}
			return cache[n/2];
		}
	}
public:
	long countPerfect(int n){
		init();
		return effCatalan((long) n);
	}
	
};