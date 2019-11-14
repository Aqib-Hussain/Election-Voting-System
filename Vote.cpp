//
// Created by Aqib on 14/11/2019.
//

#include "Vote.h"


void Vote::discard(candidate c){
    prefs.erase(remove(prefs.begin(), prefs.end(), c), prefs.end());
}

bool Vote::spent() const {
    return true;
}

candidate Vote::first_preference() const {
    return prefs[0];
}