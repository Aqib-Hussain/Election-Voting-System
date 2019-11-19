//
// Created by Aqib on 14/11/2019.
//

#include "vote.h"

vote::vote(const std::vector <candidate> &prefs) {
    this->prefs = prefs;
}

void vote::discard(candidate c){
    prefs.erase(remove(prefs.begin(), prefs.end(), c), prefs.end());
}

bool vote::spent() const {
    return prefs.empty();
}

candidate vote::first_preference() const {
    return prefs[0];
}


