#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "funcs.h"

using namespace std;

struct Account {
	int id;
	string first;
	string last;
	double savings;
	double checking;
};

int main(){
	const int NUM_ACCOUNTS = 10;
	struct Account accountArr[NUM_ACCOUNTS];
	struct Account tempAcc;
	int tempId;
	char userChar;
	unsigned int index;
	string tempFirst, tempLast;
	double tempSavings, tempChecking;
	bool loop = true;
	//Initializing variables and structures for use

	ifstream fin("input.txt");
	index = 0;
	if (fin.is_open()) {
		while (fin >> tempId >> tempFirst >> tempLast >> tempSavings >> tempChecking) {
			tempAcc.id = tempId;
			tempAcc.first = tempFirst;
			tempAcc.last = tempLast;
			tempAcc.savings = tempSavings;
			tempAcc.checking = tempChecking;
			if (++index <= 10) {
				accountArr[index - 1] = tempAcc;
			}
		}
		fin.close();
	}
	//Opening input file and loading data into account structures, loading array with Account structures
	else {
		cout << "input.txt failed to open" << endl;
	}

	while (loop) {
		printMenu();
		cin >> userChar;
		cout << endl << endl;
		switch (userChar) {
		case '1':
			printCustomerData(accountArr, index);
			break;
		case '2':
			printNames(accountArr, index);
			break;
		case '3':
			printBankTotal(accountArr, index);
			break;
		case '4':
		case 'q':
		case 'Q':
			loop = false;
			break;
		default:
			cout << "Invalid menu option, please enter 1, 2, 3, or q/Q" << endl;
			break;
		}
	}
	//Switch that calls appropriate functions or sets loop to false / helps correct user input

	return 0;
}