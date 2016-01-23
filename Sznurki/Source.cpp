#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long numStrings, height;
	cin >> numStrings;
	cin >> height;
	vector<int> tab;
	long long count = 0;
	long sum = 0;
	for (long long i = 0; i < numStrings; i++) {
		long long temp;
		scanf("%d", &temp);
		sum += temp;
		if (sum >= height) {
			sum = 0;
			count += 1;
		}
	}
	cout << count << endl;
}