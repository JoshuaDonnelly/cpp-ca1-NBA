#include <iostream>
#include <vector>
#include <map>
#include "nba.h"
#include <iomanip>


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
        cout << "4. Search players by Team\n";
        cout << "5. Find highest, lowest and Average PPG\n";
        cout << "6. Sort players by PPG or APG\n";
        cout << "10. Exit\n";
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
            case 4: {

                string team;
                cin.ignore();
                cout << "Enter team name: ";
                getline(cin, team);
                displayPlayersByTeam(players, team);
                break;
            }
            case 5: {
                NBAPlayer highest, lowest;
                float avgPPG = findPPGStats(players, highest, lowest);

                cout << fixed << setprecision(1);
                cout << "\nPPG Statistics:\n";
                cout << "Average PPG: " << avgPPG << "\n";
                cout << "Highest PPG: " << highest.name << " (" << highest.ppg << " PPG)\n";
                cout << "Lowest PPG: " << lowest.name << " (" << lowest.ppg << " PPG)\n";
                break;
            }
            case 6: {
                string field;
                cout << "Sort players by (PPG/APG): ";
                cin >> field;
                sortAndDisplayPlayers(players, field);
                break;
            }


            case 10:
                cout << "Exiting program...\n";
            break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}
