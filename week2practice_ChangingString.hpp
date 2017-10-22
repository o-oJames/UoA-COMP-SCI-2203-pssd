#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class ChangingString
{
	int result = 0;
public:
	int distance(string A, string B, int K) {
		result = 0;
		std::vector<int> temp;
		temp.assign(A.size(), 0);
		for (int i = 0; i < temp.size(); ++i)
		{
			temp[i] = abs( int(A[i]) - int(B[i]) );
		}
		sort(temp.begin(), temp.end());
		for (int i = 0; i < A.size() - K; ++i)
		{
			result += temp[i];
		}
		for (int i = A.size() - K; i < temp.size(); ++i)
		{
			if (temp[i] == 0)
			{
				result += 1;
			}
		}
		for (int i : temp) {
			cout << i << " ";
		}
		cout << endl;
		return result;
	}
	
};

/*to gain the minimal possible target the distance between 
each letter in A, after changed, and the corresponding 
letter in B must be 0 (if they are different from each 
other) or 1 otherwise.
choose K letters in A that have K maximal distance with 
K corresponding letters in B and change them in that way.*/
//result += temp[i] == 0 ? 1 : 0;