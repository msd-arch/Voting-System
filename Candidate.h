//
// Created by DELL on 4/29/2024.
//

#ifndef FINALVER_CANDIDATE_H
#define FINALVER_CANDIDATE_H
#include<string>
#include<iostream>
#include<limits>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<windows.h>

using namespace std;

class Candidate {
public:
    string cnic;
    int assemblyNo;
    string name;
    string constituency;
    string party;
    string electoralSymbol;
    string localAddress;
    string gender;
    long long phoneNo;
    int votes;

    Candidate() : assemblyNo(0), phoneNo(0), votes(0) {}
    void enterCandidateDetails(unordered_set<string>& registeredCnic);
    void displayCandidateDetails();
    string getName() const;
};


#endif //FINALVER_CANDIDATE_H
