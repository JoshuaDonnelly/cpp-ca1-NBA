#include <iostream>
#include <vector>
#include <map>
#include "nba.h"

using namespace std;

int main() {
    vector<NBAPlayer> players;
    string filename = "nba_player_stats.csv";
    loadNBAData(players, filename);
    int choice;

    do {
        cout << "\n===== NBA Player System =====\n";
        cout << "1. Display All Players\n";
        cout << "2. Search for a Player\n";
        cout << "3. Count Players by Team\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayPlayers(players);
            break;
            case 2:
                displayFoundPlayer(players);
            break;
            case 3: {
                map<string, int> teamCounts = countPlayersByTeam(players);
                displayTeamCounts(teamCounts);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
            break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
