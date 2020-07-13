struct Student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}
double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen =0;

	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	
	sort(students.begin(), students.end(), compare);

	for(vector<Student_info>::size_type i=0;i!=students.size();++i){
		cout << students[i].name << string(maxlen+1-students[i].name.size(),' ');

		try{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch(domain_error e){
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
