#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout << "Do jakiej liczby?" << endl;
	int n;
	cin >> n;
	vector<bool> tab;
	for (int i = 0; i <= n; i++) {
		tab.push_back(1);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += i) {
			tab[j] = 0;
		}
	}
	cout << "pierwsze:" << endl;
	for (int i = 1; i <= n; i++) {
		if (tab[i])
			cout << i << " ";
	}
}