#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;

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
