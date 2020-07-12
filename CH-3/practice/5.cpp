#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string name_temp;
	int score_temp;
	vector<string> name;
	vector<int> score;

	int cnt;
	cout << "Please type the count : ";
	cin >> cnt;
	cout << endl;

	for(int i=0;i<cnt;i++){
		cout << "Please type the name : ";
		cin >> name_temp;
		cout << "Please type the score : ";
		cin >> score_temp;

		name.push_back(name_temp);
		score.push_back(score_temp);
	}

	cout << "NAME\tSCORE" << endl;
	for(int i=0;i<cnt;i++){
		cout << name[i] << "\t" << score[i] << endl;
	}
	return 0;
}
