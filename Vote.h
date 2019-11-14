

#ifndef COURSEWORK_AQIB_HUSSAIN_VOTE_H
#define COURSEWORK_AQIB_HUSSAIN_VOTE_H

#include <string>
#include <vector>
#include <algorithm>

typedef unsigned int candidate;

class Vote {

    std::vector<candidate> prefs;

public:
    Vote(const std::vector<candidate> &prefs);

    bool spent() const;

    candidate first_preference() const;

    void discard(candidate c);
};




#endif //COURSEWORK_AQIB_HUSSAIN_VOTE_H
