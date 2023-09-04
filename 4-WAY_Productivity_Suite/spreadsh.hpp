#ifndef SPREADSH_HPP
#define SPREADSH_HPP


using namespace std;
const int TESTNUM = 4;

class Student {
public:
	void SetName(string studentName) { name = studentName; }
	void SetGrades(vector <long double>& testGrades) { grades = testGrades; }
	void SetGpa(vector <long double>& testGrades) {
		for (int i = 0; i < grades.size(); ++i) {
			gpa += grades.at(i);
		}
		gpa /= grades.size();
	}
	string GetName() { return name; }
	double GetTestGrade(int choiceN) { return grades.at(choiceN); }
	double GetGpa() { return gpa; }
private:
	long double gpa = 0;
	string name;
	vector <long double> grades;
};
void spreadSheet();




#endif // !SPREADSH_HPP
