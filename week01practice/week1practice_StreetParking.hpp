#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class StreetParking
{
public:
	int freeParks(string street) {
		int sum = 0;
		int i = 0;
		while ( i < street.size())
		{
		//cout << sum << endl;
			int dash = 0;
			for (int j = i; j < street.size(); ++j)
			{
				if (street[j] == '-')
				{
					sum++;
					dash++;
				}
				else if ( street[j] == 'B' )
				{
					if (dash >= 2) {
						sum = sum - 2;
					}
					else {
						sum = sum - dash;
					}
					i = j+1;
					dash=0;
					break;
				}
				else if ( street[j] == 'S' )
				{
					if (dash >= 1) {
						sum = sum - 1;
						//i = j+2;
						//dash=0;
						//break;
					}
					if (street[j+1] == '-') {
						i = j+2;
						dash=0;
						break;
					}
					if (street[j+1] != '-') { 
						i = j+1;
						dash=0;
						break;
					}
				}
				else if ( street[j] == 'D') {
					if (street[j+1] != 'B') {
						i = j+1;
						dash=0;
						break;
					}
					else if ( street[j-1] == '-' && street[j-2] != 'S') {
						sum = sum - 1;
						i = j+1;
						dash = 0;
						break;
					}
				}
				if ( j == street.size()-1 ) {
					i = street.size();
				}
			}
		}
		return sum;
	}
};