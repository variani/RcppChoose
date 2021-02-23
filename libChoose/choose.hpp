#ifndef _CHOOSE_HH
#define _CHOOSE_HH

#include <vector>
#include <unordered_set>
#include <numeric>
#include <iostream>
#include <random>
#include <list>
#include <algorithm> // sort

using namespace std;

int choose(int n, int k);
list<vector<int>> nchoosek_rec(int n, int k);
list<vector<int>> nchoosek_sample(int n, int k, int s);

#endif // _CHOOSE_HH

