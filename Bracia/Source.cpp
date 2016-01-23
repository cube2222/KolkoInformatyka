#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(pair<int, int> a, pair<int, int> b);

int main() {
	int count;
	cin >> count;
	vector<int> people;
	int maxNum = 0;
	for (int i = 0; i < count; i++) {
		int temp;
		cin >> temp;
		if (temp > maxNum) maxNum = temp;
		people.push_back(temp);
	}
	vector<pair<int, int> > begins;
	vector<int> ends;
	begins.resize(maxNum+1, pair<int, int>(-1, -1));
	ends.resize(maxNum+1, -1);
	for (int i = 0; i < count; i++) {
		if (begins[people[i]].second == -1) begins[people[i]] = pair<int, int>(people[i],i);
		ends[people[i]] = i;
	}
	sort(begins.begin(), begins.end(), isSorted);
	int i = 0;
	while (true) {
		if (begins[i].first != -1) {
			int current = i + 1;
			while (true) {
				if (begins[current].first != -1) {
					if(begins[current].first < )
				}
			}
		}
		else {
			i++;
			continue;
		}
	}
}

bool isSorted(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}