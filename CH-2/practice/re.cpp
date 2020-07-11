#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main()
{
	string s_temp;
	cout << "Please type your name : ";
	cin >> s_temp;
	const string s = s_temp;
	const string hi = "Hello, " + s_temp + "!";
	const string::size_type len = hi.size();
	const int pad =2;
	const int row = pad*2+3;
	const int col=hi.size() + pad *2 +2;
	cout << endl;

	int c;
	for(int i=0;i<row;i++){
		c=0;
		while(c!=col){
			if(i==0 || i==row-1 || c==0 || c==col-1) cout << '*';
			else if(i==row/2 && c == 1){
				cout<<hi;
				c+=len-1;
			}else cout << ' ';
			c++;
		}
		cout << endl;
	}
	return 0;
}
