#include "HandsShaking.hpp"
//g++ -std=c++11 -o a -O2 -Wall -pedantic -pthread main.cpp && ./a
using namespace std;

int main(){
	//Reppity test;
	//string a =  "ABCDEXXXYYYZZZABCDEZZZYYYXXX";
	//cout << test.longestRep(a) << endl;
	//string b =  "abcdabcdabcdabCD";
	//cout << test.longestRep(b) << endl;
	//string c =  "abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy";
	//cout << test.longestRep(c) << endl;
	//string d =  "ohbabybabybabyboy";
	/*std::vector<int> alfa (26, 0);
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
	HandsShaking test;
	int a = 2;
	cout << test.countPerfect(a) << "\t1" << endl;
	int b = 4;
	cout << test.countPerfect(b) << "\t2" << endl;
	int c = 8;
	cout << test.countPerfect(c) << "\t14" << endl;
	int d = 50;
	cout << test.countPerfect(d) << endl;
	//string d = "H??LOWOR??";
	//cout << test.describe(d) << "\tNICE" << endl;
	//string e = "EE?FFFF";
	//cout << test.describe(e) << "\tUGLY" << endl;
	//string f = "??????????????????????????????????????????????????";
	//cout << test.describe(f) << endl;
	return 0;
}