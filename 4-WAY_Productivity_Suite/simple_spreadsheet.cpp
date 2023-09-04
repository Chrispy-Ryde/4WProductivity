/* This section of the 4-WAY program features formatted output for a grading spreadsheet. Beginning with an integer input for student quantity, following with the name as well as four (4) test grade inputs for each student included. Displaying output in even columns and calculate grade point average. In a final row calculate the class's grade average */


#include<vector>
#include<iomanip>
#include<string>
#include<iostream>
#include<limits>
#include"spreadsh.hpp"

using namespace std;
/*
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
*/
void spreadSheet() {

beginning:


	int studentQuantity;
	unsigned int i, j;
	string border = ":::::";

	vector <string> instructText;
	instructText.push_back(" Welcome to the 4-WAY Grading Spreadsheet ");
	instructText.push_back(" Initialize by providing (1) the name and quarterly test grades for each student ");
	instructText.push_back(" As well as (2) the quarterly test results for each student. Program will provide ");
	instructText.push_back(" the calculated GPA and class averages in a neatly formatted output. ");

	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';
	for (i = 0; i < instructText.size(); ++i) {
		cout << border << right << setw(50 + (instructText.at(i).size() / 2)) << setfill(' ') << instructText.at(i)
			<< setw(50 - (instructText.at(i).size() / 2) + 4) << border << '\n';
	}
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	instructText.push_back("Enter the number of students: ");
	cout << setfill(' ') << setw(70) << instructText.back();
	cin >> studentQuantity;
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	string name;
	vector <long double> testGrades;
	vector <Student> students(studentQuantity);
	double testG;

	for (i = 0; i < students.size(); ++i) {
		name = "";
		testGrades.clear();
		cout << setfill(' ') << setw(70 - 4) << "Enter the name for student(" << i + 1 << "):: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
		students.at(i).SetName(name);

		for (j = 0; j < TESTNUM; ++j) {
			cout << setw(70 - 5) << "Enter the grade for test(" << j + 1 << "):: %";
			cin >> testG;
			testGrades.push_back(testG);
		}
		students.at(i).SetGrades(testGrades);
		students.at(i).SetGpa(testGrades);
		cout << setw(110) << setfill(':') << '\n';
		cout << setw(110) << setfill(':') << '\n';
	}

	vector <long double> classAvg(5);

	for (i = 0; i < studentQuantity; ++i) {

		for (j = 0; j < testGrades.size(); ++j) {

			classAvg.at(j) += students.at(i).GetTestGrade(j);
		}
		classAvg.back() += students.at(i).GetGpa();

		classAvg.at(i) /= studentQuantity;
	}

	string title = "G R A D I N G - S P R E A D S H E E T";

	cout << endl << endl << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(125) << setfill(':') << '\n';
	cout << border << right << setw(59 + (title.length() / 2)) << setfill(' ') << title << setw(60 - (title.length() / 2)) << border << '\n';
	cout << setw(125) << setfill(':') << '\n';


	cout << setw(125) << setfill(':') << '\n';
	cout << border << setw(119) << setfill(' ') << border << '\n';
	cout << border << left << setw(21) << setfill(' ') << "  Student Name" << setw(19) << " Test 1" << setw(20) << " Test 2" << setw(20) << " Test 3" << setw(19) << "Test 4" << setw(15) << " GPA" << border << '\n';

	for (i = 0; i < studentQuantity; ++i) {
		cout << (border + "  ") << left << setw(21) << students.at(i).GetName();
		for (j = 0; j < testGrades.size(); ++j) {
			cout << setw(19) << students.at(i).GetTestGrade(j);
		}
		cout << students.at(i).GetGpa() << "          " << border << '\n';
	}

	cout << border << right << setw(119) << setfill(' ') << border << '\n';
	cout << setw(125) << setfill(':') << '\n';
	cout << setw(125) << setfill(':') << '\n';
	cout << border << setw(119) << setfill(' ') << border << '\n';

	cout << border << right << setw(28) << setfill(' ') << "  Test 1" << setw(19) << "  Test 2" << setw(20) << "  Test 3" << setw(19) << "Test 4" << setw(28) << "GPA           " << border << '\n';

	cout << border << right << setw(3) << "  Average";
	for (i = 0; i < classAvg.size(); ++i) {
		cout << setw(19) << classAvg.at(i);
	}
	cout << setw(15) << border << '\n';


	cout << border << right << setw(119) << setfill(' ') << border << '\n';
	cout << setw(125) << setfill(':') << '\n';
	cout << setw(125) << setfill(':') << '\n';
	cout << endl << endl;

	cout << "Would you like to create another spreadsheet? (y/n)" << "\n\n" << flush << endl;

theEnd:

	char quitVar = '0';

	cin.ignore();
	cin >> quitVar;
	quitVar = toupper(quitVar);

	if (quitVar == 'N') {
		cout << "Goodbye!\n\n" << endl;
		system("CLS");
	}
	else if (quitVar == 'Y') {

		cout << "Very Well... \n\n" << endl;
		goto beginning;                                                             //    scanf(%d, x)  /* */

	}
	else {
		cout << "Invalid input. Please enter 'y' or 'n'." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto theEnd;
		goto theEnd;
	}

}
/*
int main() {
	spreadSheet();
	return 0;
}*/