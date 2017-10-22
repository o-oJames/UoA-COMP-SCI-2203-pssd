#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FriendlySequences
{
	std::vector<int> digits(int x) {
		std::vector<int> result (10, -1);
		if (x == 0)
		{
			result[0] = 1;
		} else {
			while (x != 0) {
				result[x % 10] = 1;
				x = x / 10;
			}
		}
		return result;
	}
	bool friendly(int first, int second) {
		std::vector<int> a = digits(first);
		std::vector<int> b = digits(second);
		return (a == b ? 1 : 0);
	}

	bool decideFriendly(int begin, int end, std::vector<int> v) {
		for (int i = begin + 1; i <= end; ++i)
		{
			if (friendly(v[begin], v[i]) == 0)
			{
				return 0;
			}
		}
		return 1;
	}
public:
	int count(std::vector<int> array) {
		int result = 0;
		for (unsigned int i = 0; i < array.size(); ++i)
		{
			for (unsigned int j = i + 1; j < array.size(); ++j)
			{
				if (decideFriendly(i, j, array))
				{
					result++;
				} else {
					break;
				}
			}
		}
		return result;
	}
};