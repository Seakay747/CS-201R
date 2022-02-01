#include <iostream>
using namespace std;

void print_menu() {
	//Defining a menu function to reduce redundancy in the code
	cout << "\nWhat would you like to order today?" << endl;
	cout << "1 ==> 4-Pack Cookies" << endl;
	cout << "2 ==> 6-Pack Cookies" << endl;
	cout << "3 ==> Party Box (12-Pack Cookies)" << endl;
	cout << "Please enter '1' or '2' or '3' to proceed: " << endl;
}

int main() {
	//Declaring constant floats, a total cost, and a quantity temporary for use when calculating total cost later
	const float FOUR_PACK = 13.20;
	const float SIX_PACK = 19.49;
	const float TWELVE_PACK = 34.08;
	float totalCost = 0;
	int tempQuantity;
	//Creating token variable to use during loop iteration and menu choice selection
	char userChar;
	int userNum;
	
	//Printing out the single-print opening menu
	cout << "Welcome to KC Cookies!" << endl;
	cout << "We offer 3 different packs of Cookies" << endl;
	cout << "4-Pack Box\t$13.20" << endl;
	cout << "6-Pack Box\t$19.49" << endl;
	cout << "Party Box '12'\t$34.08" << endl << endl;

	do {
		print_menu();
		cin >> userNum;
		cout << "How many packs do you want?" << endl;
		cin >> tempQuantity;
		cout << "\nYou ordered: " << tempQuantity; 
		// if, else if ladder to increment totalCost and print relative statement based on the user entered option and quantity + invalid option catcher
		if (userNum == 1) {
			cout << " 4-Pack Cookies" << endl;
			totalCost += (FOUR_PACK * tempQuantity);
		}
		else if (userNum == 2) {
			cout << " 6-Pack Cookies" << endl;
			totalCost += (SIX_PACK * tempQuantity);
		}
		else if (userNum == 3) {
			cout << " Party Pack Cookies" << endl;
			totalCost += (TWELVE_PACK * tempQuantity);
		}
		else {
			cout << " nothing(s); you have entered an invalid menu option, please try again" << endl;
			continue;
		}

		//Loop iteration continue/exit statement + invalid option catcher
		cout << "Do you want to add anything else? Y/y or N/n" << endl;
		cin >> userChar;
		while ((userChar != 'n') && (userChar != 'N') && (userChar != 'y') && (userChar != 'Y')) {
			cout << "Invalid option; Do you want to add anything else? Y/y or N/n" << endl;
			cin >> userChar;
		}
	} while ((userChar == 'y') || (userChar == 'Y'));
	
	cout << "The total for your order is $" << totalCost << endl;

	return 0;
}