//
// Created by Aqib on 15/11/2019.
//

#include "Election.h"
#include "Vote.h"

void add_vote(candidate prefs){
    //voteNums.pushback
}

int Election::vote_count() const {
    return voteNums[voteNums.cbegin(), voteNums.cend()];
}