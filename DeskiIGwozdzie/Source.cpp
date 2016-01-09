#include <iostream>
#include <vector>

using namespace std;

struct Plank {
	bool NailedIt = false;
	int Begin, End;
};

int main() {
	vector<vector<Plank*> > Floor;
	int PlanksNum;
	int NailsNum;
	cin >> PlanksNum;
	cin >> NailsNum;
	vector<Plank> Planks; //For memory safety purpouses.
	int maxEnd = 0;
	for (int i = 0; i < PlanksNum; i++){
		int tempBegin, tempEnd;
		cin >> tempBegin;
		cin >> tempEnd;
		Plank myPlank;
		myPlank.Begin = tempBegin;
		myPlank.End = tempEnd;
		Planks.push_back(myPlank);
		if (tempEnd > maxEnd) maxEnd = tempEnd;
	}
	Floor.resize(maxEnd + 1);
	for (int i = 0; i < PlanksNum; i++) {
		for (int j = Planks[i].Begin; j <= Planks[i].End; j++) {
			Floor[j].push_back(&Planks[i]);
		}
	}
	cout << "Nails:" << endl;
	vector<int> Nails;
	for (int i = 0; i < NailsNum; i++) {
		int temp;
		cin >> temp;
		Nails.push_back(temp);
	}
	for (int i = 0; i < Nails.size(); i++) {
		for (int j = 0; j < Floor[i].size(); j++) {
			if (Floor[i][j]->NailedIt == false) {
				Floor[i][j]->NailedIt = true;
				PlanksNum--;
				if (PlanksNum == 0) {
					cout << "Finished after " << i << endl;
					return 0;
				}
			}
		}
	}
	cout << "Nie udao sie" << endl;
}