#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
using namespace std;

struct Student_info{
	string name;
	double midterm, final;
	double score;
	vector<double> homework;
};

istream& read(istream&, Student_info&);
istream& read_hw(istream&, vector<double>&);
void score(Student_info&);
double score(double, double, double);
double score(vector<double>&);

bool compare(const Student_info& a, const Student_info& b){
	return a.name < b.name;
}

istream& read(istream& in, Student_info& s){
	in >> s.name >> s.midterm >> s.final;
	read_hw(in, s.homework);
	return in;
}

istream& read_hw(istream& in, vector<double>& hw){
	if(in){
		hw.clear();
		double x;
		while(in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}
void score(Student_info& s){
	if(s.homework.size()==0)
		throw domain_error("? there is no homework");
	double hw;
	hw = score(s.homework);
	s.score =  score(s.midterm, s.final, hw);

}

double score(double mid, double final, double hw){
	return mid*0.2+final*0.4+hw*0.4;
}


double score(vector<double>& hw){
	double avg=0;
	for(vector<double>::iterator iter=hw.begin();iter!=hw.end();iter++)
		avg+=(*iter);
	avg/=hw.size();
	return avg;
}
int main()
{
	vector<Student_info> stu_v;
	Student_info stu_temp;
	vector<double> homework_t;
	string::size_type maxlen=0;

	while(read(cin, stu_temp)){
		maxlen=max(maxlen, stu_temp.name.size());
		stu_v.push_back(stu_temp);
	}
	sort(stu_v.begin(), stu_v.end(), compare);

	vector<Student_info>::iterator viter;
	for(vector<Student_info>::iterator iter = stu_v.begin();iter!=stu_v.end();iter++){
		try{
			viter=iter;
			score(*iter);
			cout << iter->name << string(maxlen+1-(*iter).name.size(),' ') << setprecision(3) <<  iter->score << endl;
		}catch(domain_error e){
		cout << viter->name << e.what() << endl;
		}
	}
	return 0;
}
