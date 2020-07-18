#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<double> a;
	a.push_back(1);
	a.push_back(100.7);
	a.push_back(5.3);

	double sum=0;

	for(vector<double>::size_type i=0;i<a.size();i++){
		sum+=a[i];
	}

	cout<<"avg: " << setprecision(2) << sum/a.size() << endl;
	return 0;
}
