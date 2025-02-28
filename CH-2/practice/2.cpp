#include <iostream>
#include <string>
using std::cin; using std::endl;
using std::cout; using std::string;
int main()
{
	cout << "Please enter your first name: ";

	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";

	// 인사말을 둘러싼 공백의 개수
	const int pad = 5;

	//출력할 행과 열 개수
	const int rows = pad*2+3;
	const string::size_type cols = greeting.size() + pad * 2 ;
	cout << endl;

	for(int r=0;r!=rows;++r){
		string::size_type c = 0;

		while(c!=cols){
			if(r==pad+1 && c==pad){
				cout << greeting;
				c+=greeting.size();
			}
			else{
				if(r==0 || r== rows-1 || c==0 || c==cols-1) cout<< "*";
				else
					cout<<" ";
				++c;
			}
		}
		cout<<endl;
	}
	return 0;
}
