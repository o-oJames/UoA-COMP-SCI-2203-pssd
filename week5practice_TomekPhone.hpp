#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TomekPhone
{
public:
	int minKeystrokes(std::vector<int> frequencies, std::vector<int> keySizes) {
		int count = 0;
		for (int i = 0; i < keySizes.size(); ++i) {
			count += keySizes[i];
		}
		if (count < frequencies.size()) {
			return -1;
		}
		std::vector<int> costs;
		int index = 0;
		while (index < keySizes.size()){
			int temp = keySizes[index];
			for (int i = 1; i <= temp; ++i) {
				costs.push_back(i);
			}
			index++;
		}
		sort(costs.begin(), costs.end());
		sort(frequencies.begin(), frequencies.end());
		int result = 0;
		for (int i = 0; i < frequencies.size(); ++i) {
			result += costs[i] * frequencies[frequencies.size() - 1 - i];
		}
		return result;
	}
	
};