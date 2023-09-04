#ifndef TK_HPP
#define TK_HPP


using namespace std;
class timeKeep {
public:
	void SetTime(int hrs, int mins, int secs);
	void SetMilitary(bool mil, bool night);
	int getHours() { return hours; };
	int getMinutes() { return minutes; };
	int getSeconds() { return seconds; };
	void printTime();
	//void SetTime();
private:
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	string milTime, civTime;
};

void timeConversion();



#endif // !TK_HPP