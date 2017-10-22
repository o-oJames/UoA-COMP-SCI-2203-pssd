#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
//#include <limits>
using namespace std;

//int const MAX = std::numeric_limits<int>::max();
class RGBStreet
{
	std::vector<int> r;
	std::vector<int> g;
	std::vector<int> b;
	int count = 0;
	void init(std::vector<string> &houses) {
		int q = houses.size();
		for (int i = 0; i < q; ++i)
		{
			istringstream iss(houses[i]);
			int val = 0;
			int j = 0;
			while (iss >> val) {
				if (j == 0) {
					r.push_back(val);
				}
				if (j == 1) {
					g.push_back(val);
				}
				if (j == 2) {
					b.push_back(val);
				}
				j++;
			}
			j = 0;
		}
		count = r.size();
	}
	int colorCost(int i, int houseNum) {
		if (i == 0) {
			return r[houseNum];
		}
		if (i == 1) {
			return g[houseNum];
		}
		if (i == 2) {
			return b[houseNum];
		}
		return -1;
	}
	int minimumCost(int previousCost, int houseNum) {
		//cout << previousCost << ' ' << houseNum << '\n';
		if (houseNum >= count) {
			return 0;
		}
		int curBest = 2147483647;
		if (previousCost != 0) {
			curBest = min(curBest, minimumCost(0, houseNum + 1) + colorCost(0, houseNum));
		}
		if (previousCost != 1) {
			curBest = min(curBest, minimumCost(1, houseNum + 1) + colorCost(1, houseNum));
		}
		if (previousCost != 2) {
			curBest = min(curBest, minimumCost(2, houseNum + 1) + colorCost(2, houseNum));
		}
		return curBest;
	}
public:
	int estimateCost(std::vector<string> houses) {
		init(houses);
		int result = minimumCost(-1, 0);
		r.clear();
		g.clear();
		b.clear();
		return result;
	}

};