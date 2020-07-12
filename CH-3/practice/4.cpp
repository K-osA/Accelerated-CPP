#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::max;
using std::endl;
int main()
{
	string a, b;
	cout << "Please type 2 words: " << endl;
	cin >> a >> b;

	string::size_type alen, blen;
	alen = a.size();
	blen = b.size();

	cout << "MAX LEN is : " <<  max(alen, blen) << endl;

	return 0;
}
