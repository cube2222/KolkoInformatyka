#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> tab;
	vector<int> counter;
	int numCount;
	int highestCount;
	long long possibilities = 0;
	cin >> numCount;
	cin >> highestCount;

	for (int i = 0; i < numCount; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
	}

	counter.resize(highestCount + 1);
	
	for (int i = 0, j = 0; i < numCount; i++) {
		counter[tab[i]] += 1;
		if (counter[tab[i]] > 1) {
			while (tab[j] != tab[i]) {
				counter[tab[j]]--;
				j++;
			}
			counter[tab[j]]--;
			j++;
		}
		possibilities += i - j + 1;
	}
	cout << possibilities << endl;
}