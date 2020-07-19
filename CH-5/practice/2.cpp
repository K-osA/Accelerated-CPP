#include <vector>
#include <list>
using namespace std;
struct Student_info{
	int grade;
};
bool fgrade(const Student_info& s)
{
	return s.grade < 60;
}
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
	while(iter!=students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter=students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while(iter!=students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter=students.erase(iter);
		}
		else
			++iter;
	}
	return fail;
}
int main()
{
	list<Student_info> l;
	vector<Student_info> s;
	Student_info si;
	vector<double> test;
	for(int i=0;i<1000;i++){
		si.grade=(i);
		l.push_back(si);
		s.push_back(si);
	}
	extract_fails(l);
	return 0;
}
