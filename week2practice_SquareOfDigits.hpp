#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SquareOfDigits
{
public:
	int getMax(std::vector<string> data) {
		int strLen = data[0].size();
		int vecSize = data.size();
		int operSize = min(strLen, vecSize);
		for (int i = operSize - 1; i >= 0; i--)
		{
			for (int j = 0; j < vecSize - i; ++j)
			{
				for (int k = 0; k < strLen - i; ++k)
				{
					if ( ( data[j].at(k) == data[j].at(k+i) ) && ( data[j].at(k) == data[j+i].at(k+i) ) && ( data[j].at(k) == data[j+i].at(k) ) )
					{
						return (i + 1) * (i + 1);
					}
				}
			}
		}
		return 1;
	}
	
};

/* Loop through all possible size of squares. 
(note that maximum size of squares is the 
smaller edge)
Loop through all possible top left corners 
of the squares
Get the largest square.*/