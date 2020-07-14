#include <iostream>
#include <ios>
#include <vector>
#include <iomanip>
using std::cout;
using std::vector;
using std::endl;
using std::setw;
using std::streamsize;
using std::setprecision;
int main()
{
	vector<double> v;

	for(int i=1;i<=1000;i++)
		v.push_back(i*i);
	int amax, bmax;
	for(int i=0;i<1000;i++){
		int alen, blen, acnt=0, bcnt=0;
		for(int j=i+1;j!=0;j/=10)
			acnt++;
		for(int j=v[i];j!=0;j/=10)
			bcnt++;
		amax=acnt;
		bmax=bcnt;
	}
	for(int i=0;i<1000;i++){
		int len, cnt=0;
		for(int j=i+1;j!=0;j/=10)
			cnt++;
		streamsize sz=cout.precision();
		cout << i+1 << setw(amax+bmax-cnt+1) << setprecision(bmax) << v[i] <<  setprecision(sz) << endl;
	}
	return 0;
}
