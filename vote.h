

#ifndef COURSEWORK_AQIB_HUSSAIN_VOTE_H
#define COURSEWORK_AQIB_HUSSAIN_VOTE_H

#include <string>
#include <vector>
#include <algorithm>

typedef unsigned int candidate;

class vote {

    std::vector<candidate> prefs; //the total votes from EACH voter to EACH candidate

public:
    vote(const std::vector<candidate> &prefs);

    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);
};




#endif //COURSEWORK_AQIB_HUSSAIN_VOTE_H
