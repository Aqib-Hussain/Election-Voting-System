//
// Created by Aqib on 15/11/2019.
//

#include "election.h"
#include "vote.h"


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

std::vector<std::pair<candidate, int>> ranked_candidates() const{

}