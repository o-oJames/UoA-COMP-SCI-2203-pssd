#include "BlackAndWhiteSolitaire.hpp"
//g++ -std=c++11 -o a -O2 -Wall -pedantic -pthread main.cpp && ./a
using namespace std;

int main(){
	//Reppity test;
	//cout << test.longestRep(a) << endl;
	//cout << test.longestRep(b) << endl;
	//cout << test.longestRep(c) << endl;
	/*int alfa (26, 0);
	string a = "aeiou";
	for (int i = 0; i < a.size(); ++i)
	{
		char let = a[i];
		alfa[int(let)-'a'] = 1;
	}
	for (int i = 0; i < alfa.size(); ++i)
	{
		if (alfa[i] == 1)
		{
			cout << i << ' ';
		}
	}
	//0 4 8 14 20
	cout << endl;
	for (int i : alfa) {
		cout << i << ' ';
	}
	
	cout << endl;*/
	BlackAndWhiteSolitaire test;
	string a = "BBBW";
	cout << test.minimumTurns(a)  << endl;
	string b = "WBWBW";
	cout << test.minimumTurns(b)  << endl;
	string c = "WWWWWWWWW";
	cout << test.minimumTurns(c)  << endl;
	string d = "BBWBWWBWBWWBBBWBWBWBBWBBW";
	cout << test.minimumTurns(d)  << endl;
	return 0;
}
