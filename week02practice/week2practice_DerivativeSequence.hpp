#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DerivativeSequence {
    std::vector<int> diffSequence(std::vector<int> a) {
    	std::vector<int> temp;
    	temp.assign(a.size()-1, 0);
    	for (int i = 0; i < temp.size(); ++i)
    	{
    		temp[i] = a[i+1] - a[i];
    	}
    	return temp;
    }
    
public:
    std::vector<int> derSeq(std::vector<int> a, int n) {
    	if (n == 0)
    	{
    		return a;
    	}
    	return derSeq(diffSequence(a), n-1);
    }
};
