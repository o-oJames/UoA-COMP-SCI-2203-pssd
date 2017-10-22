#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class AlternateColors
{
	char helper(long r, long g, long b, long k) {
		long MIN = min(r, min(g, b));
		
		if (k <= 3 * MIN)
		{
			switch (k % 3) {
				case(1):
					return 'r';
					break;
				case(2):
					return 'g';
					break;
				case(0):
					return 'b';
					break;
			}
		}
		k -= 3 * MIN;
		r -= MIN;
		g -= MIN;
		b -= MIN;

		if (b == 0)
		{
			if (k <= 2 * min(r, g))
			{
				switch (k%2) {
					case(1):
						return 'r';
						break;
					case(0):
						return 'g';
						break;
				}
			}
			else if (r >= g)
			{
				return 'r';
			}
			else {
				return 'g';
			}
		}
		if (r == 0)
		{
			if (k <= 2 * min(g, b))
			{
				switch (k%2) {
					case (1):
						return 'g';
						break;
					case (0):
						return 'b';
						break;
				}
			}
			else if (g >= b)
			{
				return 'g';
			}
			else {
				return 'b';
			}
		}
		if (g == 0)
		{
			if (k <= 2 * min(r, b))
			{
				switch (k%2) {
					case(1):
						return 'r';
						break;
					case(0):
						return 'b';
						break;
				}
			}
			else if (r >= b)
			{
				return 'r';
			}
			else {
				return 'b';
			}
		}

		
	}
public:
	string getColor(long r, long g, long b, long k) {
		char result = helper(r, g, b, k);
		switch (result) {
			case('r'):
				return "RED";
			case('g'):
				return "GREEN";
			case('b'):
				return "BLUE";
		}
	}
	
};