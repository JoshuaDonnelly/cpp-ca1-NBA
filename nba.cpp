#include "nba.h";
#include <fstream>
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