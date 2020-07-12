#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin;
using std::vector; using std::endl;
using std::string;
int main()
{
	cout << "Please type any word : ";
	string s;
	cin >> s;

	cout << endl;

	vector<int> v;

	for(int i=0;i<26;i++)
		v.push_back(0);
	for(int i=0;i<s.size();i++)
		v[s[i]-'A']++;

	for(int i=0;i<26;i++)
		cout << static_cast<char>((i)+'A') << ": " << v[i] << endl;
	return 0;
}
