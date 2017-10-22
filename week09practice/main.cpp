#include "ErdosNumber.hpp"
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
	ErdosNumber test;
	std::vector<string> a = {"ERDOS"};
	//cout << test.calculateNumbers(a)  << endl;
	test.calculateNumbers(a);
	std::vector<string> b = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
	//cout << test.calculateNumbers(b)  << endl;
	test.calculateNumbers(b);
	std::vector<string> c = {"ERDOS A", "A B", "B AA C"};
	//cout << test.calculateNumbers(c)  << endl;
	test.calculateNumbers(c);
	std::vector<string> d = {"ERDOS B", "A B C", "B A E", "D F"};
	//cout << test.calculateNumbers(d)  << endl;
	test.calculateNumbers(d);
	std::vector<string> e = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
	//cout << test.calculateNumbers(e)  << endl;
	test.calculateNumbers(e);
	return 0;
}
