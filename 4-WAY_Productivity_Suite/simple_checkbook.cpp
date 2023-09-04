/* This Program is a simple electronic checkbook management system, using a user-defined checkbook class for easy object reference*/
/* This Program is a simple electronic checkbook management system, using a user-defined checkbook class for easy object reference*/



#include<vector>
#include<iomanip>
#include<string>
#include<iostream>
#include<limits>
#include"cb.hpp"

using namespace std;
/*
class Checkbook {
public:
	void SetDeposits(double depositAmnt);
	void SetWithdrawals(double withdrawalAmnt);
	double getDeposits(int chooseD) { return deposits.at(chooseD); };
	double getWithdrawals(int chooseW) { return withdrawals.at(chooseW); };
	double getBalance(int chooseB) { return balance.at(chooseB); };
	void printStatement();

private:
	vector <double> deposits;
	vector <double> withdrawals;
	vector <double> balance = { 0.0 };
};*/
void Checkbook::SetDeposits(double depositAmnt) {
	deposits.push_back(depositAmnt);
	balance.push_back(balance.back() + depositAmnt);
}
void Checkbook::SetWithdrawals(double withdrawalAmnt) {
	withdrawals.push_back(withdrawalAmnt);
	balance.push_back(balance.back() - withdrawalAmnt);
}
void Checkbook::printStatement() {
	string border = "|||||";
	string title = "C H E C K - S T A T E M E N T";
	unsigned int i;

	cout << setiosflags(ios::fixed) << setprecision(2) << setw(110) << setfill(':') << '\n';
	cout << border << setw(50 + (title.size() / 2)) << setfill(' ') << title << setw(50 - (title.size() / 2) + 4) << border << '\n';
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	cout << border << setw(104) << setfill(' ') << border << '\n';
	cout << left << setw(5) << border << right << setw(20) << "DEPOSITS" << setw(35) << "WITHDRAWALS" << setw(37) << "BALANCE    " << setw(12) << border << '\n';

	for (i = 0; i < balance.size(); ++i) {
		if (i < deposits.size()) {
			cout << left << setw(5) << border << right << setw(13) << '$' << left << setw(50) << deposits.at(i) << right << setw(19) << '$' << left << setw(17) << balance.at(i) << right << setw(5) << border << '\n';
		}
		else if ((i - deposits.size()) < withdrawals.size()) {
			cout << left << setw(5) << border << right << setw(47) << '$' << left << setw(15) << withdrawals.at(i - deposits.size()) << right << setw(20) << '$' << left << setw(16) << balance.at(i) << right << setw(5) << ' ' + border << '\n';
		}
		else {
			cout << left << setw(5) << border << right << setw(82) << '$' << left << setw(16) << balance.at(i) << right << setw(5) << ' ' + border << '\n';
		}
	}

	cout << right << border << setw(104) << setfill(' ') << border << '\n';
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n' << flush;
}

void checkBook() {

beginning:

	unsigned int i;
	string border = "|||||";
	Checkbook chequebook;

	vector <string> instructText;
	instructText.push_back(" Welcome to the 4-WAY Electronic Checkbook ");
	instructText.push_back(" Initialize by entering corresponding deposits or withdrawals as desired. ");
	instructText.push_back(" Program will balance as necessary. To finalize, invoke the statement option, ");
	instructText.push_back(" after which a formatted statement will print to the screen. ");

	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';
	for (i = 0; i < instructText.size(); ++i) {
		cout << border << right << setw(50 + (instructText.at(i).size() / 2)) << setfill(' ') << instructText.at(i)
			<< setw(50 - (instructText.at(i).size() / 2) + 4) << border << '\n';
	}
	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	instructText.push_back("::Please choose your desired action::");

	cout << border << setw(50 + (instructText.back().size() / 2)) << setfill(' ') << instructText.back() << setw(50 - (instructText.back().size() / 2) + 4) << border << '\n';

	cout << setw(110) << setfill(':') << '\n';
	cout << setw(110) << setfill(':') << '\n';

	cout << border << setw(104) << setfill(' ') << border << '\n';
	cout << (border + ' ') << right << setw(25) << "(A)->Enter Deposit" << setw(35) << "(B)->Enter Withdrawal" << setw(37) << "(C)->Print Statement     " << (' ' + border) << '\n';

	instructText.push_back("OR:: Press (Q) to Quit.");
	cout << border << setw(104) << setfill(' ') << border << '\n';
	cout << border << setw(50 + (instructText.back().size() / 2)) << setfill(' ') << instructText.back() << setw(50 - (instructText.back().size() / 2) + 4) << border << '\n';
	cout << setw(110) << setfill(':') << '\n';



chooseAgain:


	cout << setw(110) << setfill(':') << '\n';

	double depositAmnt = 0.0;
	double withdrawalAmnt = 0.0;
	char choiceN = '0';

	cout << setw(55) << setfill(' ') << "Enter Choice: ";

	cin >> choiceN;
	cout << setw(110) << setfill(':') << '\n';
	choiceN = toupper(choiceN);

	if ((choiceN == 'A') || (choiceN == 'B') || (choiceN == 'C') || (choiceN == 'Q')) {
		switch (choiceN) {
		case 'A':
		{

			cout << setw(55) << setfill(' ') << "Enter Deposit Amount: $";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> depositAmnt;
			chequebook.SetDeposits(depositAmnt);
			cout << setw(110) << setfill(':') << '\n';
			goto chooseAgain;
		}

		case 'B': {
			cout << setw(55) << setfill(' ') << "Enter Withdrawal Amount: $";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> withdrawalAmnt;
			chequebook.SetWithdrawals(withdrawalAmnt);
			cout << setw(110) << setfill(':') << '\n';
			goto chooseAgain;
		}

		case 'C': {
			chequebook.printStatement();
			break;
		}

		case 'Q': {

			system("CLS");
		}
		}
	}
	else {
		cout << setw(70) << setfill(' ') << "Invalid Input. Please Try Again.\n" << flush;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto chooseAgain;

	}


	cout << "\n ";
	cout << setw(40) << setfill(' ') << "Would you like to create another checkbook? (y/n)\n" << flush;
theEnd:

	char quitVar = '0';
	cin >> quitVar;
	quitVar = toupper(quitVar);

	if (quitVar == 'N') {

		cout << "Goodbye!" << "\n";
		system("CLS");
	}
	else if (quitVar == 'Y') {

		cout << "Very Well... " << endl;


		goto beginning;                                                             //    scanf(%d, x)  /* */

	}
	else {
		cout << setw(70) << setfill(' ') << "Invalid Input. Please Try Again.\n" << flush;
		cout << setw(110) << setfill(':') << '\n';

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		goto theEnd;

	}


}
/*
int main() {

	checkBook();

	return 0;*/