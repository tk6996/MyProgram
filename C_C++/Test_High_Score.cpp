#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	const int score = 15;
	string name = "Ron!";
    vector<pair<int, string>> scoreboard;
	ofstream myFile;
	myFile.open("example.txt",ios::out | ios::app);
	myFile << "\n" << name << " " << score;
	myFile.close();

	ifstream loadFile;
	loadFile.open("example.txt");
	while (!loadFile.eof()) {
		string tempName;
		int tempScore;
		loadFile >> tempName >> tempScore;
		cout << ">> \"" << tempName << "\" " << tempScore << endl;
		scoreboard.push_back({ tempScore,tempName });
	}
    cout << scoreboard.size() ;
        sort(scoreboard.begin(), scoreboard.end(), greater<pair<int, string>>());
	cin.ignore();

	return 0;
}