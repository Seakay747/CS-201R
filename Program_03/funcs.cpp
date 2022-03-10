#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Account {
	int id;
	string first;
	string last;
	double savings;
	double checking;
};

void printMenu() {
	//Basic print menu that displays func menu and prompts user for input
	cout << "1. Print all customers data" << endl;
	cout << "2. Print names and IDs" << endl;
	cout << "3. Print accounts total" << endl;
	cout << "4. Enter Q/q to quit" << endl << endl;
	cout << "Enter your choice or Q/q to quit: ";
}

void printCustomerData(struct Account arr[], int size) {
	//Prints all user data from Account array in a nice format
	cout << setw(12) << left << "Last";
	cout << setw(12) << left << "First";
	cout << setw(20) << left << "ID";
	cout << setw(18) << left << "Savings Account";
	cout << setw(18) << left << "Checking Account" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(12) << left << arr[i].last;
		cout << setw(12) << left << arr[i].first;
		cout << setw(20) << left << arr[i].id;
		cout << setw(18) << left << arr[i].savings;
		cout << setw(18) << left << arr[i].checking << endl;
	}
	cout << endl;
}

void printNames(struct Account arr[], int size) {
	//Okay just hear me out on this on
	struct Account tempAcc;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].first > arr[j + 1].first) {
				tempAcc = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tempAcc;
			}
			if (arr[j].first == arr[j + 1].first) {
				if (arr[j].last > arr[j + 1].last) {
					tempAcc = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tempAcc;
				}
			}
		}
	}
	//Bubble sorts the array of accounts by first name, uses last name for same first name
	cout << setw(12) << left << "First";
	cout << setw(12) << left << "Last";
	cout << setw(6) << left << "ID" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(12) << left << arr[i].first;
		cout << setw(12) << left << arr[i].last;
		cout << setw(6) << left << arr[i].id << endl;
	}
	cout << endl;
	cout << setfill('*') << setw(31) << right << "" << endl;
	cout << "Total number of customers is " << size << endl;
	cout << setw(31) << right << "" << endl;
	cout << setfill(' ') << endl;
	//Prints the names and associated IDs and the total number of customers
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].id > arr[j + 1].id) {
				tempAcc = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tempAcc;
			}
		}
	}
	//Resorts array by id value
}

void printBankTotal(struct Account arr[], int size) {
	//Prints savings and checking accounts as well as account totals and bank total
	float bankTot = 0;
	cout << setw(8) << left << "ID";
	cout << setw(18) << left << "Savings Account";
	cout << setw(18) << left << "Checking Account";
	cout << setw(10) << left << "Total" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(8) << left << arr[i].id;
		cout << setw(18) << left << arr[i].savings;
		cout << setw(18) << left << arr[i].checking;
		cout << setw(10) << left << arr[i].savings + arr[i].checking << endl;
		bankTot += arr[i].savings + arr[i].checking;
	}
	cout << endl;
	cout << setfill('*') << setw(25) << right << "" << endl;
	cout << "The bank total is " << bankTot << endl;
	cout << setw(25) << right << "" << endl;
	cout << setfill(' ') << endl;
}
