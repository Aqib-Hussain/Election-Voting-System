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
    votes.erase(std::remove_if(votes.begin(),votes.end(),
            [] (vote &vote) {
                return vote.spent();
    }), votes.end());
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
    //sort the pairs by number of votes
    std::sort(pairs.begin(),pairs.end(),
            [](std::pair<candidate,int> pair1,std::pair<candidate,int> pair2) { return pair2.second < pair1.second;} );
    return pairs;
}

election read_votes(std::istream &in){
    std::string line;
    candidate cand;
    election elec;

    //read in the input of first line into line
    while (std::getline(in, line)) {
        std::stringstream storedLine(line);
        std::vector<candidate> prefs;
        //while the candidate is the same as stored line
            while(storedLine >> cand){
                prefs.push_back(cand);
            }
            //add preference to vote and then add vote to election making sure the line is not empty
            if(!prefs.empty()) {
                vote vot(prefs);
                elec.add_vote(vot);
            }
    }
    return elec;
}


