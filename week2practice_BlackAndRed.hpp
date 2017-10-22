#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BlackAndRed
{
	int helper(string deck) {
		for (int i = 0; i < deck.size(); ++i)
		{
			string front = deck.substr(0, i);
			string end = deck.substr(i, deck.size()-i);
			string endFront = end + front;

			int win = 1;
			int countB = 0;
			for (int j = 0; j < endFront.size(); ++j)
			{
				if (countB < 0)
				{
					win = 0;
					break;
				}
				else {
					if (endFront[j] == 'B')
					{
						countB++;
					}
					else {
						countB--;
					}
				}
			}
			if ((win = 1) && (countB >= 0))
			{
				return i;
			}
		}
		return 0;
	}
public:
	int cut(string deck) {
		int result = helper(deck);
		return result;
	}
	
};

/*The simplest way to solve this problem is to try cutting the deck 
in every possible location, and then simulate the game for each one 
to see if you win. If you start your search with a cut of zero, and 
work your way up to N-1, you can return the size of the cut as soon 
as you find one where you win the game. This solution has a running 
time of O(N^2), which is perfectly fine since N is at most 50.*/