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

#define STUDENT_COUNT 73500

using namespace std;

struct Student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};
void read(Student_info&);
void read_hw(vector<double>&);



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

	for(int i=0;i<lim;i++){
		int homework;
		homework=rand()%100+1;
		hw.push_back(homework);
	}
	return;
}

int main()
{
	FILE *out=fopen("t73500.txt","w");
	srand((unsigned int)time(NULL));




	vector<Student_info> stu_v;
	vector<double> homework_t;
	string::size_type maxlen=0;

	for(int i=0;i<STUDENT_COUNT;i++){
		Student_info stu_temp;
		read(stu_temp);
		maxlen=max(maxlen, stu_temp.name.size());
		stu_v.push_back(stu_temp);
	}

	vector<Student_info>::iterator viter;
	for(vector<Student_info>::iterator iter = stu_v.begin();iter!=stu_v.end();iter++){
			viter=iter;
			fprintf(out,"%s %g %g ",iter->name.c_str(),iter->midterm,iter->final);
		//	cout << iter->name << " " << iter->midterm << " " << iter->final << " ";
			for(vector<double>::iterator iter2 = iter->homework.begin();iter2!=iter->homework.end();iter2++){
				if(iter2+1 == iter->homework.end())
					fprintf(out,"%g",*iter2);
				else
					fprintf(out,"%g ",*iter2);
			}
			fprintf(out,"\n");
	}
	return 0;
}
