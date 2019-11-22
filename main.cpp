#include <iostream>
#include <fstream>
#include "election.h"
#include "vote.h"

int main() {
    std::fstream in(R"(..\votes.txt)");
    if (in.is_open()) {
        auto election = read_votes(in);
        bool winnerFound = false;
        int roundCounter = 1;
        while (!winnerFound) {
            std::cout << "Round " << roundCounter << ": " << election.vote_count() << " votes" << "\n";
            std::cout << "First preferences: " << "\n";

            for(std::pair<candidate , int> p : election.ranked_candidates()){
                std::cout << "  Candidate " << p.first << ": " << p.second << "\n";
            }

            if (election.ranked_candidates().front().second > election.vote_count() / 2) {
                std::cout << "Candidate " << election.ranked_candidates().front().first << " is selected." << "\n";
                winnerFound = true;
            } else {
                candidate temp = election.ranked_candidates().back().first;
                std::cout << "Candidate " << temp << " is eliminated." << "\n";
                election.eliminate(temp);
            }
            roundCounter++;
        }
    }
    return 0;
}