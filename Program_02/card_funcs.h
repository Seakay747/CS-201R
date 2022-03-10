#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "card_funcs.h"
using namespace std;

int card_shuffle(vector<int>& deck);

int card_sort(vector<int>& deck);

int card_pop(vector<int>& deck, unsigned int index);

int card_print(vector<int>& deck);

int find_max(vector<int>& deck);

int card_find(vector<int>& deck, int num);
