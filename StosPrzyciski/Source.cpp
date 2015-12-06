#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<char> nawiasy;
	string input;
	cin >> input;
	for (auto i : input) {
		if (i == '(' || i == '[') {
			nawiasy.push(i);
		}
		else {
			if ((i == ')' && nawiasy.top() == '(') || (i == ']' && nawiasy.top() == '[')) {
				nawiasy.pop();
			}
			else {
				cout << "Error, incorrect input. Wrong pairing." << endl;
			}
		}
	}
	if (nawiasy.size() != 0) {
		cout << "Error, incorrect input. No pair" << endl;
	}
	else {
		cout << "Correct." << endl;
	}
}