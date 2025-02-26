#include <iostream>
#include "nba.h";

int main() {
    //initialising the vector and filename
    vector<NBAPlayer> players;
    string filename = "nba_player_stats.csv";

    //Calls load NBA data and loads file data
    loadNBAData(players, filename);


    displayPlayers(players);

    //search for a player
    displayFoundPlayer(players);

    return 0;
}


