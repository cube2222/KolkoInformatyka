#include <iostream>
#include <vector>

using namespace std;

bool isPrime(const int& x);
int shortestEdgeSum(const int& x);

int main() {
	int temp;
	cin >> temp;
	cout << shortestEdgeSum(temp) << endl;
}

bool isPrime(const int& x) {
	int MaxDivisor = sqrt(x);
	bool isPrime = true;
	for (int i = 2; i <= MaxDivisor; i++) {
		if (x%i == 0) {
			isPrime = false;
		}
	}
	return isPrime;
}

int shortestEdgeSum(const int& x) {
	int MaxDivisor = sqrt(x);
	for (int i = MaxDivisor; i >= 1; i--) {
		if (x % i == 0) {
			return (i * 2 + (x / i) * 2);
		}
	}
	return 0;
}