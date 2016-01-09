#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBeFibbed(const vector<int>& fibbs, int num);

int main() {
	vector<int> fibbs;
	fibbs.push_back(0);
	fibbs.push_back(1);
	vector<int> tab;
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
	}
	int max = 0;
	for (auto i : tab) {
		if (i > max) max = i;
	}
	for (int i = 2; fibbs[i - 1] < max; i++) {
		fibbs.push_back(fibbs[i - 1] + fibbs[i - 2]);
	}
	int possible = 0;
	for (int i = 0; i < len; i++) {
		if (canBeFibbed(fibbs, tab[i]) == true) possible++;
	}

	cout << possible;
}

bool canBeFibbed(const vector<int>& fibbs, int num) {
	for (int i = 0; fibbs[i] < num; i++) {
		if (binary_search(fibbs.begin(), fibbs.end(), num - fibbs[i]) == true) return true;
	}
	return false;
}