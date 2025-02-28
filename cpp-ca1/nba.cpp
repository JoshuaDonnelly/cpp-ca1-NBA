#include "nba.h"

#include <algorithm>
#include <fstream>
#include <map>
#include <sstream>

void loadNBAData(vector<NBAPlayer>& players, const string& filename) {
    ifstream infile;
    infile.open(filename);
    if (!infile.is_open()) {
        cerr << "File " << filename << " could not be opened" << endl;
        exit(1);
    }
    string line;
    bool first = true;
    while (getline(infile, line)) {
        //skips header row
        if (first) {
            first = false;
            continue;
        }
        stringstream ss(line);
        NBAPlayer player;
        string gamesPlayed, ppg, apg, rpg;

        getline(ss, player.name, ',');
        getline(ss, player.team, ',');
        getline(ss, gamesPlayed, ',');
        getline(ss, ppg, ',');
        getline(ss, apg, ',');
        getline(ss, rpg, ',');

        //pass csv string data as integers and floats
        player.gamesPlayed = stoi(gamesPlayed);

        player.ppg = stof(ppg);
        player.apg = stof(apg);
        player.rpg = stof(rpg);

        players.push_back(player);
    }
}
void displayPlayers(const vector<NBAPlayer>& players) {
    cout << "Name         | Team | Games | PPG | APG | RPG\n";
    cout << "---------------------------------------\n";

    for (const auto& player : players) {
        cout << player.name << " | " << player.team << " | "
             << player.gamesPlayed << " | " << player.ppg << " | "
             << player.apg << " | " << player.rpg << endl;
    }
}
//find player by name
int findPlayerByName(const vector<NBAPlayer>& players, const string& name) {
    for (int i = 0; i < players.size(); i++) {
        if (players[i].name == name) {
            return i;
        }
    }
    return -1;
}
void displayFoundPlayer(vector<NBAPlayer>& players) {
        string name;
        cin.ignore();
        cout << "Enter player name to search: ";
        getline(cin, name);

        int index = findPlayerByName(players, name);

        if (index != -1) {
            // Display player details if found
            cout << "\nPlayer found:\n";
            cout << "Name: " << players[index].name << "\n";
            cout << "Team: " << players[index].team << "\n";
            cout << "Games Played: " << players[index].gamesPlayed << "\n";
            cout << "PPG: " << players[index].ppg << "\n";
            cout << "APG: " << players[index].apg << "\n";
            cout << "RPG: " << players[index].rpg << "\n";
        } else {
            cout << "Player not found.\n";
        }
    }
map<string, int> countPlayersByTeam(const vector<NBAPlayer>& players) {
    map<string, int> teamCounts;

    for (const auto& player : players) {
        teamCounts[player.team]++;
    }

    return teamCounts;
}

void displayTeamCounts(const map<string, int>& teamCounts) {
    cout << "\nNumber of Players Per Team:\n";
    for (const auto& [team, count] : teamCounts) {
        cout << team << ": " << count << " players\n";
    }
}
void displayPlayersByTeam(const vector<NBAPlayer>& players, const string& teamName) {
    cout << "\nPlayers from " << teamName << ":\n";
    bool found = false;

    for (const auto& player : players) {
        if (player.team == teamName) {
            cout << player.name << " | Games: " << player.gamesPlayed
                 << " | PPG: " << player.ppg
                 << " | APG: " << player.apg
                 << " | RPG: " << player.rpg << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No players found from " << teamName << ".\n";
    }
}
float findPPGStats(const vector<NBAPlayer>& players, NBAPlayer& highest, NBAPlayer& lowest) {
    highest = players[0];
    lowest = players[0];
    float totalPPG = 0;

    for (const auto& player : players) {
        totalPPG += player.ppg;

        if (player.ppg > highest.ppg) {
            highest = player;
        }
        if (player.ppg < lowest.ppg) {
            lowest = player;
        }
    }
    return totalPPG / players.size();
}
//Couldnt get seaching working
void sortAndDisplayPlayers(vector<NBAPlayer> players, const string& field) {
    if (field == "PPG") {
        sort(players.begin(), players.end(), [](const NBAPlayer& a, const NBAPlayer& b) {
            return a.ppg > b.ppg;
        });
    }
        else if (field == "APG") {
            sort(players.begin(), players.end(), [](const NBAPlayer& a, const NBAPlayer& b) {
                return a.apg > b.apg;
            });
        }
        else {
            cout << "Invalid field selection. Choose PPG, APG.\n";
            return;
        }
        cout << "\nPlayers sorted by " << field << " (Descending):\n";
        for (const auto& player : players) {
            cout << player.name << " | " << player.team << " | "
                 << "PPG: " << player.ppg << " | APG: " << player.apg
                 << " | RPG: " << player.rpg << endl;

        }
    }


