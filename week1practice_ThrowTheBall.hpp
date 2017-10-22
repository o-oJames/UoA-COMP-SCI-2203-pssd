#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ThrowTheBall
{
	int helper(int N, int M, int L) {
		int times = 0;
		std::vector<int> people;
		people.assign(N, 0);
		int currentT = 0;
		people[0] = 1;
		while (people[currentT] < M) {
			if (people[currentT] % 2 == 0 )
			{
				currentT = (currentT + L) % N;
			}
			else {
				currentT = ((currentT - L) % N + N) % N;
			}
			times++;
			people[currentT] += 1;
		}
		return times;
	}
public:
	int timesThrown(int N, int M, int L) {
		int result = helper(N, M, L);
		return result;
	}
	
};

/*One way to solve this problem was to simply simulate the ball's movement, 
using an array to keep track of how many times each person has held the ball. 
First, assume that the first player is actually numbered "player 0". 
If there are N players, and player k needs to pass the ball L places to his left, 
then using modular arithmetic, the player who he passes the ball to is player (k+L)%N. 
Similarly, if player k needs to pass the ball L places to his right, 
he passes the ball to player (k-L+N)%N. As soon as a player has held the ball M times, 
we return how many times the ball was thrown.*/