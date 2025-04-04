//
// Created by DELL on 4/29/2024.
//

#ifndef FINALVER_VOTING_H
#define FINALVER_VOTING_H
#include<string>
#include<unordered_set>
#include<fstream>
#include "Candidate.h"
#include "Voters.h"
#include<windows.h>

using namespace std;

class Voting {
private:
    unordered_set<string> registeredCnic; // Store registered CNICs

    unordered_set<string> votedCnic;
public:
    // Function to write candidate information to file
    void writeCandidateInfoToFile(Candidate* candidates, int numCandidates);
    // Function to write voter information to file
    void writeVoterInfoToFile(Voter* voters, int numVoters);

    unordered_set<string>& getRegisteredCnic();

    void startVoting(Candidate* candidates, int numCandidates, Voter* voters, int numVoters);

    void displayCandidates(Candidate* candidates, int numCandidates) ;
    void displayVoters(Voter* voters, int numVoters) ;

    // Function to store the total votes awarded to each candidate in a separate file called "result"
    void storeResult(Candidate* candidates, int numCandidates) ;

};


#endif //FINALVER_VOTING_H
