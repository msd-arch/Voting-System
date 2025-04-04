//
// Created by DELL on 4/29/2024.
//

#ifndef FINALVER_VOTERS_H
#define FINALVER_VOTERS_H
#include<string>
#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<limits>
#include<sstream>
#include<windows.h>

using namespace std;

class Voter {
public:
    string voterCnic;
    string voterName;
    string voterFatherName;
    string voterAddress;
    long long voterPhoneNo;
    char voterGender;
    string voterEmail;

    Voter() : voterPhoneNo(0), voterGender('M') {}
    void enterVoterDetails(unordered_set<string>& registeredCnic);
    void showVoterDetails() ;

    int getVotedCandidateIndex(int numCandidates);

};


#endif //FINALVER_VOTERS_H
