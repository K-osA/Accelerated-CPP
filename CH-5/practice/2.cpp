#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

#define STUDENT_COUNT 4999

using namespace std;

struct Student_info{
	string name;
	double midterm, final;
	double score;
	vector<double> homework;
};
void read(Student_info&);
void read_hw(vector<double>&);
void score(Student_info&);
double score(double, double, double);
double score(vector<double>&);

bool compare(const Student_info& a, const Student_info& b){
	return a.name < b.name;
}


void read(Student_info& s){
	int lim;
	char name[12]={0};
	lim=rand()%10+1;

	for(int i=0;i<lim;i++){
		int ch;
		ch=rand()%26+97;
		name[i]=(char)ch;
	}
	string res(name);
	s.name=res;
	s.midterm=rand()%100+1;
	s.final=rand()%100+1;

	read_hw(s.homework);
	return;
}

void read_hw(vector<double>& hw){
	int lim;
	lim=rand()%8+1;

	for(int i=0;i<lim;i++)
		hw.push_back(lim);
	return;
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
	FILE *out=fopen("output.txt","w");
	srand((unsigned int)time(NULL));




	vector<Student_info> stu_v;
	Student_info stu_temp;
	vector<double> homework_t;
	string::size_type maxlen=0;

	for(int i=0;i<STUDENT_COUNT;i++){
		read(stu_temp);
		maxlen=max(maxlen, stu_temp.name.size());
		stu_v.push_back(stu_temp);
	
	}
	//sort(stu_v.begin(), stu_v.end(), compare);

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
