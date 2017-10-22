#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ImportantTasks
{
	void sort(std::vector<int> &v) {
		for (int i = 0; i < v.size()-1; ++i)
		{
			int imin = i;
			for (int j = i+1; j < v.size(); ++j)
			{
				if (v[j] < v[imin]) {
					imin = j;
				}
			}
			if (imin != i)
			{
				swap(v[i], v[imin]);
			}
		}
	}
	int eraser(std::vector<int> cx, std::vector<int> cp) {
		std::vector<int> result;
		int sz = cx.size();
		int i = 0;
		while (i <= sz)
		{
			for (int j = 0; j < cp.size(); ++j)
			{
				if (cx[0] <= cp[j])
				{
					result.push_back(cx[0]);
					cp.erase(cp.begin()+j);
					cx.erase(cx.begin());
					i = 0;
					break;
				}
			}
			sz = cx.size();
			i++;
		}
		return result.size();
	}
public:
	int maximalCost(std::vector<int> complexity, std::vector<int> computers) {
		sort(complexity);
		sort(computers);
		return eraser(complexity, computers);
	}
	
};