#ifndef CB_HPP
#define CB_HPP


using namespace std;
class Checkbook {
public:
	void SetDeposits(double depositAmnt);
	void SetWithdrawals(double withdrawalAmnt);
	double getDeposits(int chooseD) { return deposits.at(chooseD); };
	double getWithdrawals(int chooseW) { return withdrawals.at(chooseW); };
	double getBalance(int chooseB) { return balance.at(chooseB); };
	void printStatement();

private:
	std::vector <double> deposits;
	std::vector <double> withdrawals;
	std::vector <double> balance = { 0.0 };
};
void checkBook();




#endif // !CB_HPP
