#include <iostream>
#include <vector>
#include <iomanip>
using std::cout;
using std::vector;
using std::endl;
using std::setw;
int main()
{
	vector<int> v;

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

		cout << i+1 << setw(amax+bmax-cnt+1) << v[i] <<  endl;
	}
	return 0;
}
