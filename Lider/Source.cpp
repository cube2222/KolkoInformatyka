#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int temp;
	int count;
	cin >> count;
	vector<int> tab;
	stack<int> finder;
	for (int i = 0; i < count; i++) {
		cin >> temp;
		tab.push_back(temp);
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
		if (amount > tab.size() / 2) cout << "Leader: " << leader << endl;
	}
	else {
		cout << "No leader." << endl;
	}

}