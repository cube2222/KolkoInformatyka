#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> Buttons;
	int ButtonCount, OpCount;
	cin >> ButtonCount;
	cin >> OpCount;
	int max = 0;
	int min = 0;
	for (int i = 0; i < ButtonCount; i++) {
		Buttons.push_back(0);
	}
	for (int i = 0; i < OpCount; i++) {
		int temp;
		cin >> temp;
		if (temp - 1 == ButtonCount) {
			min = max;
		}
		else {
			if (Buttons[temp - 1] < min) {
				Buttons[temp - 1] = min + 1;
			}
			else {
				Buttons[temp - 1]++;
			}
			
			if (Buttons[temp - 1] > max) max = Buttons[temp - 1];
		}
	}
	for (int i = 0; i < Buttons.size(); i++) {
		if (Buttons[i] < min) cout << min << " ";
		else cout << Buttons[i] << " ";
	}
}