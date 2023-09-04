
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include<limits>
#include <fstream>
#include"cb.hpp"
#include"tk.hpp"
#include"spreadsh.hpp"
#include"pos.hpp"

using namespace std;

int main() {
begin:

    unsigned int i;
    string border1 = ">>>>>";
    string border2 = "<<<<<";
    int chooseN=0;
    vector <string> instructText;
    instructText.push_back(" 4 - W A Y  P R O D U C T I V I T Y  S U I T E ");
    instructText.push_back(" --Enter (1) to launch the POS Receipt Program-- ");
    instructText.push_back(" --Enter (2) to launch the GPA Spreadsheet Program-- ");
    instructText.push_back(" --Enter (3) to launch the Checkbook Program-- ");
    instructText.push_back(" --Enter (4) to launch the Time Conversion Program-- ");

    cout << setw(110) << setfill('*') << "\n";
    cout << setw(110) << setfill('*') << "\n";
    cout << left << setw(5) << border1 << right << setw(55) << setfill(' ') << " " << setw(50) << border2 << "\n";
    for (i = 0; i < instructText.size(); ++i) {
        cout << left << setw(5) << border1 << right << setw(50 + (instructText[i].size() / 2)) << setfill(' ') << instructText[i]
            << setw(50 - (instructText[i].size() / 2) + 4) << border2 << "\n";
    }
    cout << left << setw(5) << border1 << right << setw(55) << setfill(' ') << " " << setw(50) << border2 << "\n";
    cout << setw(110) << setfill('*') << "\n";
    cout << setw(110) << setfill('*') << "\n";

    cout << setw(50) << setfill(' ') << " " << "Enter your choice:: ";
    cin >> chooseN;
    cout << setw(110) << setfill('*') << "\n";
    cout << setw(110) << setfill('*') << endl;

 
    fstream gpaS;
    fstream checkB;
    fstream timeK;

    if ((chooseN > 0) && (chooseN < 5)) {
        switch (chooseN) {

        case 1:
            posReceipt();
			
			break;
            
        case 2:
            spreadSheet();
            
            break;
            

        case 3:
            checkBook();

			break;
            

        case 4:
            timeConversion();
            break;
        }
   
    }
   else if ((chooseN <= 0)||(chooseN >= 5) ||(!cin)) {
        cout << setw(70) << setfill(' ') << " " << "Invalid choice. Please try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto begin;
    }

}