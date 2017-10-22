#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class UnsealTheSafe
{
	std::vector<long> column;
	std::vector<std::vector<long> > row;
	void init(long (n)) {
		column.assign(20, 0);
		row.assign(50, column);
		for (unsigned int i = 0; i < 10; ++i)
		{
			row[1][i] = 1;
		}
		for (unsigned int i = 2; i <= n; ++i)
		{
			row[i][0] = row[i-1][7];
			row[i][1] = row[i-1][2] + row[i-1][4];
			row[i][2] = row[i-1][1] + row[i-1][3] + row[i-1][5];
			row[i][3] = row[i-1][2] + row[i-1][6];
			row[i][4] = row[i-1][1] + row[i-1][5] + row[i-1][7];
			row[i][5] = row[i-1][2] + row[i-1][4] + row[i-1][6] + row[i-1][8];
			row[i][6] = row[i-1][3] + row[i-1][5] + row[i-1][9];
			row[i][7] = row[i-1][4] + row[i-1][8] + row[i-1][0];
			row[i][8] = row[i-1][5] + row[i-1][7] + row[i-1][9];
			row[i][9] = row[i-1][6] + row[i-1][8];
			row[i][0] = row[i-1][7];
		}
	}
public:
	long countPasswords(int N) {
		init(N);
		long result = 0;
		for (int i = 0; i < 10; ++i)
		{
			result += row[N][i];
		}
		return result;
	}
};