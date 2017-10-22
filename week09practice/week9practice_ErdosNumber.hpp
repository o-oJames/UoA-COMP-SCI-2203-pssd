#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class ErdosNumber
{
	struct pubisher
	{
		string name;
		int numEdo;
		int repeat;
		pubisher(): name(""),
					numEdo(-1),
					repeat(0) {}
	};
	std::vector<std::vector<pubisher> > vec;
	std::vector<pubisher> nameV;
	void init() {
		vec.clear();
		//vec.shrink_to_fit();
		nameV.clear();
		//nameV.shrink_to_fit();
	}


	void numAssign(std::vector<string> v) {
		std::vector<pubisher> pubisherVec;
		for (unsigned int i = 0; i < v.size(); ++i) {
			pubisherVec.clear();
			//pubisherVec.shrink_to_fit();
			string author;
			istringstream iss(v[i]);
			while (iss >> author) {
				pubisher temp;
				temp.name = author;
				pubisherVec.push_back(temp);
			}
			vec.push_back(pubisherVec);
		}
	}

	bool checkRep(string str) {
		for (unsigned int i = 0; i < nameV.size(); ++i) {
			if (str == nameV[i].name) {
				nameV[i].repeat++;
				return 1;
			}
		}
		return 0;
	}

	void findEdo() {
		for (unsigned int i = 0; i < vec.size(); ++i) {
			for (unsigned int j = 0; j < vec[i].size(); ++j) {
				if (vec[i][j].name == "ERDOS") {
					vec[i][j].numEdo = 0;
					if (!checkRep(vec[i][j].name))
					{
						nameV.push_back(vec[i][j]);
					}
				}
			}
		}
	}
	void sync(string str, int num) {
		for (unsigned int i = 0; i < vec.size(); ++i) {
			for (unsigned int j = 0; j < vec[i].size(); ++j) {
				if (vec[i][j].name == str)
				{
					vec[i][j].numEdo = num;
				}
			}
		}
	}

	void assign(std::vector<pubisher> v) {
		std::vector<pubisher> temp = v;
		if (v.empty())
		{
			return;
		}
		for (unsigned int i = 0; i < vec.size(); ++i) {
			for (unsigned int j = 0; j < vec[i].size(); ++j) {
				if (vec[i][j].name == temp[0].name) {
					int edo = temp[0].numEdo + 1;
					for (unsigned int k = 0; k < vec[i].size(); ++k) {
						if (k != j) {
							if (vec[i][k].numEdo == -1 && !checkRep(vec[i][k].name))
							{
								vec[i][k].numEdo = edo;
								sync(vec[i][k].name, edo);
								nameV.push_back(vec[i][k]);
								temp.push_back(vec[i][k]);
							}
						}
					}
				}
			}
		}
		temp.erase(temp.begin());

		//cout << "erase:" << temp.begin()->name << endl;
		//for (int i = 0; i < temp.size(); ++i)
		//{
		//	cout << "temp:" << temp[i].name << ' ' << temp[i].numEdo << std::endl;
		//}

		assign(temp);

	}
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
				//else return 0;
			}
		}
		return 0;
	}
	void lexiVec(std::vector<pubisher> &words) {
		for (int i = 0; i < words.size()-1; ++i)
		{
			int imin = i;
			for (int j = i+1; j < words.size(); ++j)
			{
				if (lexi(words[j].name, words[imin].name) == 0) {
					imin = j;
				}
			}
			if (imin != i)
			{
				swap(words[i], words[imin]);
			}
		}
	}

	std::vector<string> helper(std::vector<string> v) {
		numAssign(v);
		findEdo();
		assign(nameV);

		for (unsigned int i = 0; i < vec.size(); ++i) {
			for (unsigned int j = 0; j < vec[i].size(); ++j) {
				if (vec[i][j].numEdo == -1 && !checkRep(vec[i][j].name))
				{
					nameV.push_back(vec[i][j]);
				}
			}
		}

		lexiVec(nameV);

		std::vector<string> result;

		for (int i = 0; i < nameV.size(); ++i)
		{
			//cout << nameV[i].name << ' ' << nameV[i].numEdo << std::endl;
			string temp;
			if (nameV[i].numEdo != -1)
			{
				stringstream ss;
				ss << nameV[i].numEdo;
				temp = nameV[i].name + ' ' + ss.str();
			} else {
				temp = nameV[i].name;
			}
			result.push_back(temp);
		}
		//cout << endl;
		//for (unsigned int i = 0; i < vec.size(); ++i) {
		//	for (unsigned int j = 0; j < vec[i].size(); ++j) {
		//		cout << vec[i][j].name << "->" << vec[i][j].numEdo << ' ';
		//	}
		//	cout << endl;
		//}
		//for (string i : result) {
		//	cout << i << ' ';
		//}
		//cout << endl;
		return result;
	}



public:
	std::vector<string> calculateNumbers(std::vector<string> publications) {
		std::vector<string> res;
		init();
		res = helper(publications);
		return res;
	}
	
};