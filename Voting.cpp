//
// Created by DELL on 4/29/2024.
//

#include "Voting.h"

void Voting::writeCandidateInfoToFile(Candidate *candidates, int numCandidates) {
    ofstream candidateFile("candidates.txt");
    if (!candidateFile) {
        cerr << "Error opening candidates file!" << endl;
        return;
    }

    for (int i = 0; i < numCandidates; ++i) {
        candidateFile << candidates[i].cnic << endl;
        candidateFile << candidates[i].assemblyNo << endl;
        candidateFile << candidates[i].name << endl;
        candidateFile << candidates[i].constituency << endl;
        candidateFile << candidates[i].party << endl;
        candidateFile << candidates[i].electoralSymbol << endl;
        candidateFile << candidates[i].localAddress << endl;
        candidateFile << candidates[i].gender << endl;
        candidateFile << candidates[i].phoneNo << endl;
        candidateFile << candidates[i].votes << endl; // Write votes
    }
    candidateFile.close();
}

void Voting::writeVoterInfoToFile(Voter *voters, int numVoters) {
    ofstream voterFile("voters.txt");
    if (!voterFile) {
        cerr << "Error opening voters file!" << endl;
        return;
    }

    for (int i = 0; i < numVoters; ++i) {
        voterFile << voters[i].voterCnic << endl;
        voterFile << voters[i].voterName << endl;
        voterFile << voters[i].voterFatherName << endl;
        voterFile << voters[i].voterAddress << endl;
        voterFile << voters[i].voterPhoneNo << endl;
        voterFile << voters[i].voterGender << endl;
        voterFile << voters[i].voterEmail << endl;
    }
    voterFile.close();

}

unordered_set<string> &Voting::getRegisteredCnic() {
    return registeredCnic;
}

void Voting::startVoting(Candidate *candidates, int numCandidates, Voter *voters, int numVoters) {
    // Get the current date and time
    time_t currentTime = time(0);
    string dateTime = ctime(&currentTime);

    cout << "Candidates:" << endl;
    for (int i = 0; i < numCandidates; ++i) {
        candidates[i].displayCandidateDetails();
        cout << "-----------------------------------------------------------" << endl;
    }

    string voterCnic;
    cout << "Enter your CNIC No (13 digits): ";
    cin >> voterCnic;

    if (votedCnic.find(voterCnic) != votedCnic.end()) {
        cout << "You have already cast your vote. Multiple votes are not allowed !" << endl;
        return;
    }

    bool voterFound = false;
    for (int i = 0; i < numVoters; ++i) {
        if (voters[i].voterCnic == voterCnic) {
            cout << "Voter found. Your details:" << endl;
            voters[i].showVoterDetails();
            voterFound = true;
            int candidateIndex = voters[i].getVotedCandidateIndex(numCandidates);
            if (candidateIndex >= 0 && candidateIndex < numCandidates) {
                cout << "You voted for:" << endl;
                candidates[candidateIndex].displayCandidateDetails();
                cout << "-----------------------------------------------------------" << endl;

                // Increment the vote count for the selected candidate
                candidates[candidateIndex].votes++;
                // Store the updated candidate information back to file
                writeCandidateInfoToFile(candidates, numCandidates);

                // Store the vote details in a separate file
                ofstream voteFile("votes.txt", ios::app); // Open the file in append mode
                if (!voteFile) {
                    cerr << "Error opening votes file!" << endl;
                } else {
                    // Write vote details: CNIC, Name, and Date & Time
                    voteFile << "Voter CNIC: " << voters[i].voterCnic << endl;
                    voteFile << "Voter Name: " << voters[i].voterName << endl;
                    voteFile << "Date & Time Voted: " << dateTime << endl;
                    voteFile << "-----------------------------------------------------------" << endl;
                    voteFile.close();
                }

                votedCnic.insert(voterCnic);
            } else {
                cout << "Invalid candidate choice!" << endl;
            }
            break;
        }
    }

    if (!voterFound) {
        cout << "Voter not found. Register as a voter first." << endl;
    }
}

void Voting::displayCandidates(Candidate *candidates, int numCandidates) {
    cout << "Candidates:" << endl;
    for (int i = 0; i < numCandidates; ++i) {
        candidates[i].displayCandidateDetails();
        cout << "-----------------------------------------------------------" << endl;
    }


}

void Voting::displayVoters(Voter *voters, int numVoters) {
    cout << "Voters:" << endl;
    for (int i = 0; i < numVoters; ++i) {
        voters[i].showVoterDetails();
        cout << "-----------------------------------------------------------" << endl;
    }

}

void Voting::storeResult(Candidate *candidates, int numCandidates) {
    ofstream resultFile("result.txt");
    if (!resultFile) {
        cerr << "                                      Error opening result file!" << endl;
        return;
    }

    for (int i = 0; i < numCandidates; ++i) {
        resultFile << candidates[i].name << ": " << candidates[i].votes << endl;
    }

    resultFile.close();
}


