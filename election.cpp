//
// Created by Aqib on 15/11/2019.
//

#include "election.h"
#include "vote.h"
#include <sstream>

void election::add_vote(const vote &v){
    votes.push_back(v);
}

int election::vote_count() const {
    return votes.size();
}

void election::eliminate(candidate c){
    for(vote &vote: votes){
        vote.discard(c);
    }
    std::remove_if(votes.begin(),votes.end(),
            [] (vote &vote) {
                return vote.spent();
    });
}

std::vector<std::pair<candidate, int>> election::ranked_candidates() const{
    std::vector<std::pair<candidate,int>> pairs;
    //loop through all votes
    for(const vote& vote: votes){
        //create bool if the candidate and vote match
        bool counted = false;
        //for search through 2nd vector pair for voting pairs
        for(std::pair<candidate,int> &pair: pairs ){
            if (pair.first ==  vote.first_preference()){
                pair.second = pair.second+1;
                counted = true;
            }
        }
        //new candidate gets created and gets 1 vote added to their tally
        if (!counted){
            pairs.emplace_back(vote.first_preference(), 1);
        }
    }
    return pairs;
}

election read_votes(std::istream &in){
   // return;
}
