#include <iostream>
#include <vector>

using namespace std;

int main() {
	int len;
	cin >> len;
	vector<int> tab;
	vector<int> values;
	for (int i = 0; i < len; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
		values.push_back(-1000000);
	}
	int p, q, x, val, curP, curQ, curX, curVal;
	curP = -1000000;
	curQ = -1000000;
	curX = -1000000;
	p = -1000000;
	q = -1000000;
	x = -1000000;
	val = -1000000;
	curVal = 0;
	for (int i = 1; i < len - 1; i++) {
		if (curP == -1000000) {
			if (tab[i] > -1000000) {
				curP = i - 1;
				curX = i;
			}
		}
		else {
			if (tab[i] >= tab[curX]) {
				curVal += tab[i];
				curQ = i + 1;
			}
			else {
				curVal += tab[curX];
				curX = i;
				curQ = i + 1;
			}
		}

		if (val < curVal) {
			val = curVal;
			p = curP;
			q = curQ;
			x = curX;
		}
	}
	cout << p << " " << x << " " << q << endl;
}