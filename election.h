//
// Created by Aqib on 15/11/2019.
//

#ifndef COURSEWORK_AQIB_HUSSAIN_ELECTION_H
#define COURSEWORK_AQIB_HUSSAIN_ELECTION_H

#include <string>
#include <vector>
#include <algorithm>
#include "vote.h"


class election {

    std::vector<vote> votes; //a list of the total votes from ALL voters

public:

    void add_vote(const vote &v);

    int vote_count() const;

    void eliminate(candidate c);

    std::vector<std::pair<candidate, int>> ranked_candidates() const; //

    election read_votes(std::istream &in);

};


#endif //COURSEWORK_AQIB_HUSSAIN_ELECTION_H
