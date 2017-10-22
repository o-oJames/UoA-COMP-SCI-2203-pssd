#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class DownloadingFiles
{
public:
	double actualTime(std::vector<string> tasks) {
		//string str = tasks;
		//istringstream iss(str);
		//double val;
		//int q = 0;
		//std::vector<double> v;
		//while (iss >> val) {
		//	v.push_back(val);
		//	q++;
		//}
		std::vector<double> v;
		int q = tasks.size();
		for (int i = 0; i < q; ++i)
		{
			istringstream iss(tasks[i]);
			double val;
			while (iss >> val) {
				//double temp = atoi(tasks.at(i).c_str());
				v.push_back(val);
			}
		}
		double sumSize = 0;
		double sumSpeed = 0;
		int vecSize = v.size();
		for (int i = 0; i < vecSize; ++i) {
			double product = 0;
			if (i % 2 != 0) {
				product = v[i]*v[i-1];
				sumSize += product;
			}
			if (i % 2 == 0)
			{
				sumSpeed += v[i];
			}
		}
		double result = sumSize / sumSpeed;
		return result;
	}	
};