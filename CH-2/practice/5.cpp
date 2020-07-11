#include <iostream>
using namespace std;
int main()
{
	cout << "num? : ";
	int num;
	cin >> num;

	cout << endl;

	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++)
			cout << '*';
		cout << endl;
	}
	return 0;
}
