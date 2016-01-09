#include <iostream>
#include <vector>

using namespace std;

int go(vector<int> tab, int Max, int Sum, int Cuts);
bool check(const vector<int>& tab, int max, int cuts);

int main() {
	int Cuts;
	cin >> Cuts;
	int n;
	cin >> n;
	vector<int> tab;
	int Max = 0;
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		tab.push_back(temp);
		Sum += temp;
		if (temp > Max) Max = temp;
	}
	cout << go(tab, Max, Sum, Cuts) << endl;
}

bool check(const vector<int>& tab, int max, int cuts) {
	int currSum = 0;
	for (int i = 0; i < tab.size(); i++) {
		if (currSum + tab[i] > max) {
			currSum = 0;
			if (cuts > 0) {
				cuts--;
			}
			else {
				return false;
			}
		}
		currSum += tab[i];
	}
	return true;
}

int go(vector<int> tab, int Max, int Sum, int Cuts) {
	if (Max > Sum) { return Sum; }
	int mid = (Max + Sum) / 2;
	if (check(tab, mid, Cuts) == true) {
		if (check(tab, mid - 1, Cuts) == true)
			return go(tab, Max, mid, Cuts);
		else
			return mid;
	}
	else {
		return go(tab, mid + 1, Sum, Cuts);
	}
}