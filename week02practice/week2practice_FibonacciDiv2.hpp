#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FibonacciDiv2
{
public:
	int find(int N) {
		std::vector<int> cache;
		cache.assign(50, 0);
		cache[0] = 0;
		cache[1] = 1;
		int dist = abs(cache[0] - N);
		for (int i = 2; i < cache.size(); ++i)
		{
			cache[i] = cache[i-1] + cache[i-2];
			dist = min(dist, abs(cache[i] - N));
		}
		return dist;
	}
	
};