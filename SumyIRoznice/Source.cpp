#include <iostream>
#include <vector>

using namespace std;

int main() {
	long n;
	cin >> n;
	long long Pairs = 0;
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		if (temp < 0) {
			Pairs += n - 1;
		}
	}
	cout << Pairs << endl;
}