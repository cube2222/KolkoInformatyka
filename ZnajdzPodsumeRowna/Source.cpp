#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> tab;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
	}
	int searchNum;
	cin >> searchNum;
	int Begin = 0, End = 1, Sum = tab[0];
	while (End <= tab.size()) {
		if (Sum < searchNum) {
			if (End < tab.size()) {
				End += 1;
				Sum += tab[End - 1];
			}
			else {
				cout << "Impossible" << endl;
				return 0;
			}
		}
		else if (Sum > searchNum) {
			Begin += 1;
			Sum -= tab[Begin - 1];
		}
		if (Sum == searchNum) {
			cout << "Possible" << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;

}