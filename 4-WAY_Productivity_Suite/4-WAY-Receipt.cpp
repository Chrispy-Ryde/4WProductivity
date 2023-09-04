/*******************************************************************************
                            SUPERTAXv13.42.cpp
                        Created by Christian Pryde

   I stripped it down to the basics because trying fancy stuff seems to get
 me into trouble. I really love programming though, very mentally stimulating.
 Honestly it's making it difficult for me to decide on my major... I am completely
 obsessed with machine learning & trying to understand and wield the power of
 language models.
*******************************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include<string>
#include<sstream>
#include<limits>
#include"pos.hpp"

using namespace std;

void posReceipt()
{

beginning:


    vector<string> dialogueText;
    double taxPercent, taxTotal, totalb4Tax = 0.0, grandTotal = 0.0;  // Honestly, I am not sure how much I can say in comments..
    unsigned int i;                                                // I feel that the code is relatively concise and to the point.
    int itemQuantity;
    string border = "*****";

    vector <string> instructText;
    instructText.push_back(" Welcome to the 4-WAY Point-of-Sales Receiptizer");
    instructText.push_back(" Initialize by entering the item quantity, afterwards provide");
    instructText.push_back(" both (1) the name as well as (2) the price for each corresponding item.");
    instructText.push_back(" After providing the tax % program will in turn print a formatted receipt.  ");

    cout << setw(110) << setfill('!') << '\n';
    cout << setw(110) << setfill('!') << '\n';
    for (i = 0; i < instructText.size(); ++i) {
        cout << border << right << setw(50 + (instructText.at(i).size() / 2)) << setfill(' ') << instructText.at(i)
            << setw(50 - (instructText.at(i).size() / 2) + 4) << border << '\n';
    }
    cout << setw(110) << setfill('!') << '\n';
    cout << setw(110) << setfill('!') << '\n';

    dialogueText.push_back("Please enter the item quantity:: ");

    cout << setw(55) << setfill(' ') << setiosflags(ios::fixed) << setprecision(2) << dialogueText.at(0); // getting these manipulators out of the way
    cin >> itemQuantity;
    cout << '\n' << '\n';

    vector<string> productNames;
    vector<double> itemPrices(itemQuantity);          // these are the input vectors, I certainly prefer using vectors & for loops

    string textSwap;

    dialogueText.push_back("Please enter the name of item ");
    dialogueText.push_back("Please enter the price of item ");


    for (i = 0; i < itemPrices.size(); ++i) {
        cout << setw(50) << setfill(' ') << dialogueText.at(1) << "[" << (i + 1) << "]:: ";   // Fills the vector with user values
        cin.ignore();
        getline(cin, textSwap, '\n');
        productNames.push_back(textSwap);

        cout << '\n' << setw(50) << setfill(' ') << dialogueText.at(2) << "[" << (i + 1) << "]:: $";
        cin >> itemPrices.at(i);
        cout << '\n';
    }
    cout << '\n' << '\n';

    dialogueText.push_back("Please enter tax percentage:: %"); // final dialogue

    cout << setw(50) << setfill(' ') << dialogueText.at(3);
    cin >> taxPercent;
    taxPercent = taxPercent / 100;                    // various necessary calculations are here 

    for (i = 0; i < itemQuantity; ++i) {
        totalb4Tax += itemPrices.at(i);
    }

    taxTotal = (totalb4Tax * taxPercent);
    grandTotal = totalb4Tax + taxTotal;

    cout << "\n\n";
    cout << "********************************************" << '\n';
    cout << "********* S A L E S R E C E I P T **********" << '\n';
    cout << "********************************************" << '\n';       // This didn't copypasta well, but I think I fixed it. 
    cout << "**                                        **" << '\n';
    cout << "**  :::ITEM:::           :::PRICE:::      **" << '\n';
    cout << "**                                        **" << '\n';

    for (i = 0; i < itemQuantity; ++i) {
        cout << "**   " << left
            << setw(17) << productNames.at(i) << '$' << right
            << setw(10) << itemPrices.at(i)
            << setw(12) << "**\n";
    }

    cout << "**                                        **" << '\n';
    cout << "**                                        **" << '\n';
    cout << "********************************************" << '\n';
    cout << "********************************************" << '\n';
    cout << "**                                        **" << '\n';
    cout << "**   Total Sales       $" << setw(9) << totalb4Tax << "         **" << '\n';
    cout << "**   Sales tax         $" << setw(9) << taxTotal << "         **" << '\n';
    cout << "**                      -----------       **" << '\n';
    cout << "**   Grand Total       $" << setw(9) << grandTotal << "         **" << '\n';
    cout << "**                                        **" << '\n';
    cout << "********************************************" << '\n';
    cout << "********************************************" << '\n';
    cout << '\n' << '\n';
    cout << "Would you like to print another receipt? (y/n) \n" << flush;          //Here I have the final program options, allowing for a clean restart or program exit.

theEnd:

    char quitVar = '0';

    cin >> quitVar;
    quitVar = toupper(quitVar);

    if (quitVar == 'N') {
        cout << "GOODBYE!";
        system("CLS");
    }

    else if (quitVar == 'Y') {
        cout << "Very Well... " << '\n' << flush;
        goto beginning;                                                             //    scanf(%d, x)  /* */

    }
    else {
        cout << "Invalid Input. Please Try Again." << '\n' << flush;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto theEnd;

    }

}
/*
int main()
{
    posReceipt();
    return 0;
}
*/

