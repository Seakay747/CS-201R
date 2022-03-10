#include <iostream>
#include <vector>
#include <random>
#include "card_funcs.h"
using namespace std;

int card_shuffle(vector<int>& deck) {
	int rand1, rand2, temp;
	srand(time(0));
	for (int i = 0; i < 100; ++i) {
		rand1 = (rand() % 16);
		rand2 = (rand() % 16);
		temp = deck.at(rand1);
		deck.at(rand1) = deck.at(rand2);
		deck.at(rand2) = temp;
	}
	return 0;
}

int card_sort(vector<int>& deck) {
	int temp;
	for (int i = 0; i < deck.size(); i++) {
		for (int j = i + 1; j < deck.size(); j++) {
			if (deck[j] < deck[i]) {
				temp = deck[i];
				deck[i] = deck[j];
				deck[j] = temp;
			}
		}
	}
	return 0;
}

int card_pop(vector<int>& deck, unsigned int index) {
	deck.erase(deck.begin() + index);
	return 0;
}

int card_print(vector<int>& deck) {
	for (int i = 0; i < deck.size(); i++) {
		cout << deck.at(i) << " ";
	}
	return 0;
}

int find_max(vector<int>& deck) {
	int max = deck.at(0);
	for (int i = 0; i < deck.size(); i++) {
		if (max < deck.at(i)) {
			max = deck.at(i);
		}
	}
	return max;
}

int card_find(vector<int>& deck, int num) {
	for (int i = 0; i < deck.size(); i++) {
		if (deck.at(i) == num) {
			return i;
		}
	}
	return -1;
}