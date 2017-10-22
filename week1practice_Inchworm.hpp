#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Inchworm
{
	int greatestCommDeno(int rest, int leaf) {
		if (leaf == 0)
		{
			return rest;
		}
		return greatestCommDeno(leaf, rest%leaf);
	}

	int lowestCommonMul(int rest, int leaf) {
		return rest / greatestCommDeno(rest, leaf) * leaf;
	}

public:
	int lunchtime(int branch, int rest, int leaf) {
		return branch / lowestCommonMul(rest, leaf) + 1;
	}
};