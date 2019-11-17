//
// Created by Aqib on 15/11/2019.
//

#ifndef COURSEWORK_AQIB_HUSSAIN_ELECTION_H
#define COURSEWORK_AQIB_HUSSAIN_ELECTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "Vote.h"

typedef int numberOfVotes;

class Election {

    std::vector<numberOfVotes> voteNums; //create a vector to store the number of votes

public:
    void add_vote(const Vote &v);

    int vote_count() const;

    void eliminate(candidate c);

    std::vector<std::pair<candidate, int>> ranked_candidates() const;

    Election read_votes(std::istream &in);

};


#endif //COURSEWORK_AQIB_HUSSAIN_ELECTION_H
