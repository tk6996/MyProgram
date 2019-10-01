#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void Recordscore(const char* Name,int Score);
int main()
{
    char Name[26];
    int score;
    cin >> Name >> score ;
    Recordscore(Name,score);
    return 0;
}
void Recordscore(const char* Name,int Score)
{
    vector<pair<string ,int>> scoreboard;
    int i;
    string Namefile = "Test File.txt";
    ifstream fin(Namefile);
    while(!fin.eof())
    {
        string Player;
        int score ;
        fin >> Player >> score ;
        scoreboard.push_back({ Player,score });
    }
    scoreboard.pop_back();
    for(i=0;i<scoreboard.size();i++)
    {
        if(Score>=scoreboard[i].second) break;
    }
    scoreboard.insert(scoreboard.begin()+i,{ Name,Score });
    fin.close();
    fstream fnew(Namefile,ios::out | ios::trunc);
    for(auto iter = scoreboard.begin(); iter != scoreboard.end(); iter++)
    {
        fnew << (*iter).first << " " << (*iter).second << endl;
    }
    fnew.close();
}