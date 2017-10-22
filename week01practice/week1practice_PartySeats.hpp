#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class PartySeats
{
public:
	bool lexi(string name1, string name2) {
		int count = 0;
		if (name1.size() > name2.size()) {
			count = name2.size();
		}
		else {count = name1.size();}
		for (int i = 0; i < count; ++i) {
			if (int(name1[i]) < int(name2[i])) {
				return 0;
			}
			else if (int(name1[i]) > int(name2[i])) {
				return 1;
			}
			if ( i == count-1) {
				if (name1.size() > name2.size()) {
					return 1;
				}
				else return 0;
			}
		}
	}

	std::vector<string> lexiVec(std::vector<string> gender) {
		for (int i = 0; i < gender.size()-1; ++i)
		{
			int imin = i;
			for (int j = i+1; j < gender.size(); ++j)
			{
				if (lexi(gender[j], gender[imin]) == 0) {
					imin = j;
				}
			}
			if (imin != i)
			{
				swap(gender[i], gender[imin]);
			}
		}
		return gender;
	}

	std::vector<string> seating(std::vector<string> attendees) {
		std::vector<string> temp;
		std::vector<string> boy;
		std::vector<string> girl;
		for (int i = 0; i < attendees.size(); ++i) {
			istringstream iss(attendees[i]);
			string entry;
			while (iss >> entry) {
				temp.push_back(entry);
			}
		}
		int skip = 1;
		while (skip < temp.size()) {
			if (temp[skip] == "boy") {
				boy.push_back(temp[skip-1]);
			}
			else {girl.push_back(temp[skip-1]);}
			skip += 2;
		}
		std::vector<string> orderBoy = lexiVec(boy);
		std::vector<string> orderGirl = lexiVec(girl);

		std::vector<string> final;
		if (orderBoy.size() != orderGirl.size())
		{
			return final;
		}
		if (orderBoy.size() == 1 && orderGirl.size() == 1)
		{
			return final;
		}
		if (orderBoy.size() % 2 != 0) {
			return final;
		}
		final.push_back("HOST");
		for (int i = 0; i < orderBoy.size()/2; ++i)
		{
			final.push_back(orderGirl[i]);
			final.push_back(orderBoy[i]);
		}
		final.push_back("HOSTESS");
		for (int i = orderBoy.size()/2; i < orderBoy.size(); ++i)
		{
			final.push_back(orderBoy[i]);
			final.push_back(orderGirl[i]);
		}
		return final;
	}
}; 