#ifndef NBA_H
#define NBA_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct NBAPlayer {
    string name;
    string team;
    int gamesPlayed;
    float ppg;
    float apg;
    float rpg;
};
//allow file reading
void loadNBAData(vector<NBAPlayer>& players, const string& filename);
void displayPlayers(const vector<NBAPlayer>& players);
void displayFoundPlayer(vector<NBAPlayer>& players);
map<string, int> countPlayersByTeam(const vector<NBAPlayer>& players);
void displayTeamCounts(const map<string, int>& teamCounts);
void displayPlayersByTeam(const vector<NBAPlayer>& players, const string& team);
float findPPGStats(const vector<NBAPlayer>& players, NBAPlayer& highest, NBAPlayer& lowest);
void sortAndDisplayPlayers(vector<NBAPlayer> players, const string& field);

#endif //NBA_H
