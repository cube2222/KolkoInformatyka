#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findLeader(vector<int> &tab, int& myAmount);

int main() {
	int tabLen;
	cin >> tabLen;
	vector<int> tab;
	for (int i = 0; i < tabLen; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
	}
	int amount;
	int leader = findLeader(tab, amount);
	if (leader < 0) {
		cout << "No leader." << endl;
		return 0;
	}
	int count = 0;
	int slicePossibilities = 0;
	for (int i = 0; i < tab.size() - 1; i++) {
		if (tab[i] == leader) {
			count++;
		}
		if (i + 1 < count * 2 && tab.size() - (i + 1) < (amount - count) * 2) {
			slicePossibilities++;
		}
	}
	cout << slicePossibilities << endl;
}

int findLeader(vector<int> &tab, int& myAmount) {
	stack<int> finder;
	for (auto temp : tab) {
		if (finder.empty() != true && finder.top() != temp) finder.pop();
		else finder.push(temp);
	}
	int leader;
	if (finder.size() > 0) {
		leader = finder.top();
		int amount = 0;
		for (auto i : tab) {
			if (i == leader) amount++;
		}
		if (amount > tab.size() / 2) {
			myAmount = amount;
			return leader;
		}
	}
	return -1;
}