#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
using namespace std;
double median(vector<double> homework){
	if(homework.size()==0)
		throw domain_error("student has done no homework");
	sort(homework.begin(), homework.end());
	return homework.size()%2==0 ? (homework[homework.size()/2-1]+homework[homework.size()/2])/2 : homework[homework.size()/2];
}
double grade(double midterm, double final, double homework){
	return midterm*0.2+final*0.4+homework*0.4;
}
double grade(double midterm, double final, const vector<double>& homework){
	return grade(midterm, final, median(homework));
}
istream& read_hw(istream& in, vector<double>& homework){
	if(in){
		homework.clear();
		double temp;
		while(in >> temp){
			homework.push_back(temp);
		}
		in.clear();
	}
	return in;
}


int main()
{
	//이름 묻고 있음
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간, 기말 시험 점수 묵도 있음.
	cout << "Please enter your midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm, final;

	//과제 점수 물음.
	cout << "Enter all your homework grades, "
		"followed by end-of-file: ";
	vector<double> homework;

	//과제 점수 읽음.
	read_hw(cin, homework);

	// 종합 점수를 계산해 생성.
	try{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch(domain_error){
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}
	return 0;
}
