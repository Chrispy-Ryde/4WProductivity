
#include<vector>
#include<iomanip>
#include<string>
#include<iostream>
#include<sstream>
#include<limits>
#include"tk.hpp"

using namespace std;
/*
class timeKeep {
public:
	void SetTime(int hrs, int mins, int secs);
	void SetMilitary(bool mil, bool night);
	int getHours() { return hours; };
	int getMinutes() { return minutes; };
	int getSeconds() { return seconds; };
	void printTime();
private:
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	string milTime, civTime;

};*/
void timeKeep::SetTime(int hrs, int mins, int secs) {
	hours = hrs;
	minutes = mins;
	seconds = secs;
}

//void timeKeep::SetTime() { hours = 0; minutes = 0; seconds = 0; }

void timeKeep::SetMilitary(bool mil, bool night /* = false */) {
	// Temporary variables for military and civilian time formats
	string tempMilTime;
	string tempCivTime;
	stringstream timeMil, timeCiv;




	// Calculate the military time format
	if (mil == true) {
		stringstream timePass;
		timeMil << setw(2) << setfill('0') << hours << ':'
			<< setw(2) << setfill('0') << minutes << ':'
			<< setw(2) << setfill('0') << seconds << " MIL";
		tempMilTime = timeMil.str();
		timeMil.clear();

		if (hours > 12) {
			timeCiv << setw(2) << setfill('0') << (hours - 12) << ':'
				<< setw(2) << setfill('0') << minutes << ':'
				<< setw(2) << setfill('0') << seconds << " PM";
			tempCivTime = timeCiv.str();
			timeCiv.clear();
		}

		else if (hours < 12) {
			timeCiv << setw(2) << setfill('0') << hours << ':'
				<< setw(2) << setfill('0') << minutes << ':'
				<< setw(2) << setfill('0') << seconds << " AM";
			tempCivTime = timeCiv.str();
			timeCiv.clear();
		}

	}

	// Calculate the civilian time format
	else if (mil == false) {
		stringstream timePass;
		timeCiv << setw(2) << setfill('0') << hours << ':'
			<< setw(2) << setfill('0') << minutes << ':'
			<< setw(2) << setfill('0') << seconds;
		tempCivTime = timeCiv.str();
		timeCiv.clear();

		if (night == true) {
			tempCivTime.append(" PM");
			timeMil << setw(2) << setfill('0') << (hours + 12) << ':'
				<< setw(2) << setfill('0') << minutes << ':'
				<< setw(2) << setfill('0') << seconds << " MIL";
			tempMilTime = timeMil.str();
			timeMil.clear();
		}
		else if (night == false) {
			tempCivTime.append(" AM");
			timeMil << setw(2) << setfill('0') << hours << ':'
				<< setw(2) << setfill('0') << minutes << ':'
				<< setw(2) << setfill('0') << seconds << " MIL";
			tempMilTime = timeMil.str();
			timeMil.clear();
		}

	}

	// Assign the temporary variables to milTime and civTime
	milTime = tempMilTime;
	civTime = tempCivTime;
}

void timeKeep::printTime() {
	string border = "=====", civty = ">>>>Civilian Time->>>> ", milty = ">>>>Military Time->>>> ";
	cout << setw(110) << setfill('+') << '\n';
	cout << left << setw(5) << border << right << setw(104) << setfill(' ') << border << '\n';
	cout << left << setw(5) << border << right << setw(40 + (milty.size() / 2)) << milty << setw(10) << milTime << setw(41) << border << '\n';
	cout << left << setw(5) << border << right << setw(40 + (civty.size() / 2)) << civty << setw(10) << civTime << setw(42) << border << '\n';
	cout << left << setw(5) << border << right << setw(104) << setfill(' ') << border << '\n';
	cout << setw(110) << setfill('+') << '\n';
}


void timeConversion() {
beginning:
	timeKeep timeLog1;
	bool milTime, pmTime = false;
	int hrsIn = 00, minsIn = 00, secsIn = 00;
	char choice;
	unsigned int i;
	string border = "+++++";

	vector <string> instructText;
	instructText.push_back(" Welcome to the 4-WAY Mil-Civ Time Converter ");
	instructText.push_back(" Initialize by providing integers values for either hours, minutes, or seconds. ");
	instructText.push_back(" Then clarify which format for the provided time to receive conversion.");

	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';
	for (i = 0; i < instructText.size(); ++i) {
		cout << border << right << setw(50 + (instructText.at(i).size() / 2)) << setfill(' ') << instructText.at(i)
			<< setw(50 - (instructText.at(i).size() / 2) + 4) << border << '\n';
	}
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	instructText.push_back("Please enter time format:: (C)ivilian or (M)ilitary");

chooseForm:

	choice = '0';


	cout << border << setw(50 + (instructText.back().size() / 2)) << setfill(' ') << instructText.back() << setw(50 - (instructText.back().size() / 2) + 4) << border << '\n';
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(60) << setfill(' ') << "Choice?::";
	cin >> choice;
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';
	choice = toupper(choice);

	if (choice == 'C' || choice == 'M') {

		if (choice == 'C') {
		chooseForm2:
			milTime = false;
			choice = ' ';
			instructText.push_back("Very well, is the time (A)M->Before Noon or (P)M->After Noon?:: ");
			cout << setw(60) << setfill(' ') << instructText.back();
			cin >> choice;
			cout << setw(110) << setfill('+') << "\n";
			cout << setw(110) << setfill('+') << "\n";
			choice = toupper(choice);

			if (choice == 'A' || choice == 'P') {
				pmTime = (choice == 'P') ? true : false;

			}

			else {
				cout << setw(70) << setfill(' ') << "!!!<INVALID INPUT, TRY AGAIN>!!!\n";
				cout << setw(110) << setfill('+') << "\n";
				cout << setw(110) << setfill('+') << "\n";
				cin.clear();
				goto chooseForm2;
			}
		}
		else {
			milTime = true;

		}
	}
	else {
		cout << setw(70) << setfill(' ') << "!!!<INVALID INPUT, TRY AGAIN>!!!\n";
		cout << setw(110) << setfill('+') << "\n";
		cout << setw(110) << setfill('+') << "\n";
		cin.clear();
		goto chooseForm;
	}


	instructText.push_back("Hour value or enter for default(= 00):: ");
tryHours:
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << setw(60) << setfill(' ') << instructText.back();
	cin >> hrsIn;
	cout << setw(110) << setfill('+') << "\n";
	cout << setw(110) << setfill('+') << "\n";

	if (milTime == true) {
		if ((hrsIn < 0) || (hrsIn > 24) || (!cin)) {
			cout << setw(70) << setfill(' ') << "!!!<INVALID INPUT, TRY AGAIN>!!!\n";
			cout << setw(110) << setfill('+') << "\n";
			cout << setw(110) << setfill('+') << "\n";
			cin.clear();

			goto tryHours;
		}
	}

	else if (milTime == false) {
		if ((hrsIn < 0) || (hrsIn > 12) || (!cin)) {
			cout << setw(70) << "!!!<INVALID INPUT, TRY AGAIN>!!!\n" << endl;
			cout << setw(110) << setfill('+') << "\n";
			cout << setw(110) << setfill('+') << "\n";
			cin.clear();
			goto tryHours;
		}
	}

tryMins:
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	instructText.push_back("Minute value or enter for default(= 00):: ");

	cout << setw(60) << setfill(' ') << instructText.back();
	cin >> minsIn;
	cout << setw(110) << setfill('+') << "\n";
	cout << setw(110) << setfill('+') << "\n";

	if ((minsIn < 0) || (minsIn > 60) || (!cin)) {
		cout << setw(70) << setfill(' ') << "!!!<INVALID INPUT, TRY AGAIN>!!!\n";
		cout << setw(110) << setfill('+') << "\n";
		cout << setw(110) << setfill('+') << "\n";
		cin.clear();

		goto tryMins;
	}
trySecs:
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	instructText.push_back("Second value or enter for default(= 00)::");

	cout << setw(60) << setfill(' ') << instructText.back();
	cin >> secsIn;
	cout << setw(110) << setfill('+') << "\n";
	cout << setw(110) << setfill('+') << "\n";

	if ((secsIn < 0) || (secsIn > 60) || (!cin)) {
		cout << setw(70) << setfill(' ') << "!!!<INVALID INPUT, TRY AGAIN>!!!\n";
		cout << setw(110) << setfill('+') << "\n";
		cout << setw(110) << setfill('+') << "\n";
		cin.clear();

		goto trySecs;
	}
	timeLog1.SetTime(hrsIn, minsIn, secsIn);
	timeLog1.SetMilitary(milTime, pmTime);
	timeLog1.printTime();

	cout << "Would you like to convert another time format?:: (y/n)\n" << flush << endl;

theEnd:

	char quitVar = '0';

	cin >> quitVar;
	quitVar = toupper(quitVar);
	if (quitVar == 'N') {
		cout << "Goodbye!" << "\n";
		system("CLS");
	}
	if (quitVar == 'Y') {

		cout << "Very Well... " << endl;


		goto beginning;

	}
	else {
		cout << "Invalid Input, Try Again" << endl;
		goto theEnd;
	}


}

//int main() {
//	timeConversion(); // Call the main program function
//	return 0;
//}