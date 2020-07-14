#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;
using std::vector;
using std::string;
using std::endl;
int main()
{
	int cnt=1;
	string s;
	vector<string> vs;
	while(cin>>s){
		vs.push_back(s);
	}
	sort(vs.begin(), vs.end());

	typedef vector<string>::size_type vst;

	vst v =vs.size();

	for(vst i=0;i<v;i++){
		if(i==0)
			cout << vs[i] << ": ";
		else if(vs[i]==vs[i-1])
			cnt++;
		else{
			cout << cnt << endl;
			cnt=1;
			cout << vs[i] << ": ";
		}
	}
	cout << cnt << endl;
	return 0;
}
