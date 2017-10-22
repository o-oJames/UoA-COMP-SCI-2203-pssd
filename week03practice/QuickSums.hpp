#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

class QuickSums {
	/*int addition(string a, string b, int base) {
		long long i = 0;
		while(a[0] == '0') {
			a.erase(0, 1);
			i++;
		}
		i = 0;
		while(b[0] == '0') {
			b.erase(0, 1);
			i++;
		}
		if (a.empty()) {
			a = "0";
		}
		if (b.empty()) {
			b = "0";
		}
	
		std::vector<string> queue;
		if (a.size() >= b.size()) {
			queue.push_back(a);
			queue.push_back(b);
		}else {
			queue.push_back(b);
			queue.push_back(a);
		}
		std::vector<char> first (queue[0].c_str(), queue[0].c_str() + queue[0].size() + 1);
		std::vector<char> second (queue[1].c_str(), queue[1].c_str() + queue[1].size() + 1);
	
		int cache = 0;
		bool it = 0;
		std::vector<char> resultRev;
		while(!second.empty()) {
			if (it == 0) {
				first.pop_back();
				second.pop_back();
				it = 1;
			}
			int digit1 = first.back() - '0';
			int digit2 = second.back() - '0';
			if (digit2 >= base || digit1 >= base) {
				cout << "Number should be under " << base << endl;
				exit (EXIT_FAILURE);
			}
			if ((digit1 + digit2 + cache) >= base) {
				int temp = (digit1 + digit2 + cache) % base;
				char sum = '0' + temp;
				resultRev.push_back(sum);
				cache = 1;
				first.pop_back();
				second.pop_back();
			}
			else {
				int temp = (digit1 + digit2 + cache) % base;
				char sum = '0' + temp;
				resultRev.push_back(sum);
				cache = 0;
				first.pop_back();
				second.pop_back();
			}
		}
		while (!first.empty()) {
			int digit1 = first.back() - '0';
			if (digit1 >= base) {
				cout << "Number should be under " << base << endl;
				exit (EXIT_FAILURE);
			}
			if ((digit1 + cache) >= base) {
				int temp = (digit1 + cache) % base;
				char sum = '0' + temp;
				resultRev.push_back(sum);
				cache = 1;
				first.pop_back();
			}
			else {
				int temp = (digit1 + cache) % base;
				char sum = '0' + temp;
				resultRev.push_back(sum);
				cache = 0;
				first.pop_back();
			}
		}
		if (cache != 0 && first.empty()) {
			char sum = '0' + cache;
			resultRev.push_back(sum);
			cache = 0;
		}
	
		while (resultRev.back() == '0') {
			resultRev.pop_back();
		}
		if (resultRev.empty()) {
			resultRev.push_back('0');
		}
	
		std::reverse(resultRev.begin(), resultRev.end());
		string result (resultRev.begin(), resultRev.end());
		int resultInt;
		istringstream getResult(result);
		getResult >> resultInt;
		return resultInt;
	}
	std::vector<int> time;
	int helper(string numbers, int sumH, int times) {
		//int curNum = 0;
		//cout << "helper:" << sumH << endl;
		int curTimes = times;
		string temp = numbers;
		int sum = 0;
		for (unsigned int j = 1; j <= temp.size(); ++j) {
			string str1 = temp.substr(0, j);
			int sumStr1 = addition(str1, "0", 10);
			//cout << str1 << ' ';
			int sumStr2 = 0;
			for (unsigned int i = j; i <= temp.size(); ++i) {
				string str2 = temp.substr(i, 1);
				for (unsigned int k = 0; k < str2.size(); ++k)
				{
					sumStr2 += str2[k] - '0';
					curTimes++;
				}
				//cout << str2 << ' ';
			}
			sum = sumStr1 + sumStr2;
			//cout << sum << endl;
			if (sum == sumH )
			{
				//cout << "sum:" << sum << endl;
				//cout << "curTimes:" << curTimes << endl;
				time.push_back(curTimes);
			}
			curTimes = 0;
			sum = 0;
		}
			if (!numbers.empty())
			{
				string str3 = numbers.substr(0, 2);
				string str4 = numbers.substr(0,3);
				int numStr3;
				int numStr4;
				istringstream iss1(str3);
				istringstream iss2(str4);
				iss1 >> numStr3;
				iss2 >> numStr4;
				int cumT = times+1;
				helper(numbers.erase(0,1), sumH - numbers[0] - '0', cumT);
				helper(numbers.erase(0,1), sumH - numStr3, cumT);
				helper(numbers.erase(0,2), sumH - numStr4, cumT);
			}
		return 0;
	}*/
public:
	int minSums(string numbers, int sum) {
		/*helper(numbers, sum, 0);
		if (time.empty())
		{
			return -1;
		}
		int min = time[0];
		for (unsigned int i = 1; i < time.size(); ++i)
		{
			if (min > time[i])
			{
				min = time[i];
			}
		}
		return min;*/
		std::vector<std::vector<int>> vals;
		vals.assign(numbers.size()+1, {-2. -2});
		vals.push_back({0, -1});
		for (unsigned int i = 0; i <= numbers.size(); ++i)
		{
			/* code */
		}
	}
};