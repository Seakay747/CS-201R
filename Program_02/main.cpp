#include <iostream>
#include <vector>
#include <random>
#include "card_funcs.h"
using namespace std;

int main() {
	vector<int> dead_cards;
	vector<int> held_cards;
	vector<int> live_cards;
	vector<int> draw_cards{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	bool loop = true;
	int totScore, maxNum;
	int index;
	char userChar;

	while (loop) {
		cout << "Shuffling cards..." << endl;
		card_shuffle(draw_cards);
		maxNum = 0;
		totScore = 0;
		dead_cards.clear();
		held_cards.clear();
		held_cards.push_back(0);
		for (int i = 1; i <= 16; i++) {
			live_cards.push_back(i);
		}
		cout << "Shuffle complete!" << endl;
		//Resets the game before a loop

		for (int i = 0; i < 16; i++) {
			index = card_find(live_cards, draw_cards.at(i));
			//Keeps track of the live_cards index associated with the draw_cards card
			cout << "Current Score: " << totScore << endl;
			cout << "Dead Cards: ";
			card_print(dead_cards);
			cout << endl;
			cout << "Live Cards: ";
			card_print(live_cards);
			cout << endl;
			cout << "Next Card: " << draw_cards.at(i) << endl;
			//Prints the menu
			if (draw_cards.at(i) > maxNum) {
				//Checks maxNum against the drawn card, prompts the user accordingly
				cout << "[T]ake it or [L]eave it? ";
				cin >> userChar;
				userChar = toupper(userChar);
				if (userChar == 'T') {
					//If user takes, updates score, updates decks, updates hand
					dead_cards.push_back(draw_cards.at(i));
					held_cards.push_back(draw_cards.at(i));
					card_pop(live_cards, index);
					totScore += draw_cards.at(i);
				}
				else if (userChar == 'L') {
					//If user leaves cards, updates decks
					dead_cards.push_back(draw_cards.at(i));
					card_pop(live_cards, index);
				}
			}
			else if (draw_cards.at(i) <= maxNum) {
				//Jumps here and updates decks, prints dead
				cout << "Dead" << endl;
				dead_cards.push_back(draw_cards.at(i));
				card_pop(live_cards, index);
			}
			maxNum = find_max(held_cards);
			//Updates maxNum with the largest card in the user's hand
			card_sort(dead_cards);
			//Sorts the dead_cards to correct for the nature of push_back
			cout << endl;
		}
		cout << "Final Score: " << totScore << endl;
		cout << "Dead Cards: ";
		card_print(dead_cards);
		cout << endl;
		cout << "Live Cards: ";
		card_print(live_cards);
		cout << endl;
		//Final menu print to show off the user's ending score and the full set of dead_cards and final score
		cout << "Press 'Q' to quit or any key to continue ==> ";
		cin >> userChar;
		userChar = toupper(userChar);
		if (userChar == 'Q') {
			loop = false;
		}
	}


	return 0;
}