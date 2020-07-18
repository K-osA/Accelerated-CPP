#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

struct Student_info{
	std::string name;
	//double midterm, final;
	//std::vector<double> homework;

	double grade;
};
double median(vector<double> vec);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double homework);
bool compare(const Student_info& x, const Student_info& y);
istream& read(istream& is, Student_info& s);
istream& read_hw(istream& in, vector<double>& hw);


double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if(size==0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size/2;
	return size%2==0?(vec[mid]+vec[mid-1])/2:vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if(hw.size()==0)
		throw domain_error("student has done no homework");

	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
	return 0.2*midterm+0.4*final+0.4*homework;
}


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
istream& read(istream& is, Student_info& s)
{
	double midterm, final;
	is >> s.name >> midterm >> final;
	vector<double> homework;
	read_hw(is, homework);
	
	s.grade = grade(midterm, final, homework);
	return is;
}
istream& read_hw(istream& in, vector<double>& hw)
{
	if(in){
		hw.clear();

		double x;

		while(in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}



int main()
{
	vector<Student_info> students;
	Student_info record;

	string::size_type maxlen = 0;

	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for(vector<Student_info>::size_type i=0;i!=students.size();++i){
		cout<<students[i].name<<string(maxlen+1-students[i].name.size(), ' ');

		try{
			//double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].grade << setprecision(prec);
		}
		catch(domain_error e){
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
