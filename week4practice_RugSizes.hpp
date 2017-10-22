#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class RugSizes
{
public:
	int rugCount(int area) {
		int width = 1;
		int height = 1;
		int count = 0;
		while (width * height <= area) {
			for (int height = 1; height * height <= area; ++height)
			{
				if (width * height == area)
				{
					if (width == height)
					{
						//cout << width << ' ' << height << endl;
						count++;
					}else if (width % 2 ==0) {
						if (height % 2 != 0)
						{
							//cout << width << ' ' << height << endl;
							count++;
						}
					}else if (width % 2 != 0)
					{
						//cout << width << ' ' << height << endl;
						count++;
					}
				}
			}
			width++;
		}
		return count;
	}
	
};