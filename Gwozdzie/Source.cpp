#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> nails;
	int hits, tabLen;
	cin >> tabLen;
	cin >> hits;
	for (int i = 0; i < tabLen; i++) {
		int temp;
		cin >> temp;
		nails.push_back(temp);
	}
	sort(nails.begin(), nails.end());
	int current = nails[0];
	int amount = 1;
	int max = 0;
	for (int i = 1; i < tabLen - hits; i++) {
		if (nails[i] == current) {
			amount++;
		}
		else {
			if (amount > max) max = amount;
			amount = 1;
			current = nails[i];
		}
	}
	if (amount > max) max = amount;
	if (max + hits > nails.size()) cout << nails.size();
	else cout << max + hits;
}