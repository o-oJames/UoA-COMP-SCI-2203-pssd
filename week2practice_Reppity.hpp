#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Reppity
{
public:
	int longestRep(string input) {
		int repeat = 0;
		for (unsigned int j = 1; j <= input.size(); ++j)
		{
			for (unsigned int i = 0; i <= input.size()-j; ++i)
			{
				string temp = input;
				string str1 = input.substr(i, j);
				//temp.erase(find(temp.begin(), temp.end(), str1));
				temp.erase(i, j);
				temp.insert(i, 1, ' ');
				//cout << temp << ' ';
				std::string::size_type n;
				n = temp.find(str1);
				if (n != std::string::npos)
				{
					repeat = str1.size();
				}
			}
			//cout << '\n';
		}
		return repeat;
	}

};
		/*for (unsigned int j = 1; j <= input.size(); ++j)
		{
			string str1 = input.substr(0, j);
			cout << str1 << ' ';
			for (unsigned int i = j; i <= input.size(); ++i)
			{
				string str2 = input.substr(i, 1);
				cout << str2;
			}
			cout << '\n';
public class Reppity {
	public int longestRep(String input) {
		int ans = 0;
		
		for(int i=0; i < input.length(); i++)
			for(int j = i+ 1; j <= input.length(); j++)				
				ans = Math.max(ans, length(input, i, j));
		return ans;
	}
	private int length(String x, int a, int b){
		int aa = a, bb = b, ans = 0;
		while(aa < b && bb < x.length() && x.charAt(aa++) == x.charAt(bb++)){
			ans++;
		}
		return ans;
	}
}
		}*/