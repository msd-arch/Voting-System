//
// Created by DELL on 4/29/2024.
//

#include "Voters.h"

void Voter::enterVoterDetails(unordered_set<string> &registeredCnic) {
    cout<<"                                      Press XX at any time to return to main menu                "<<endl;
    cout<<"                -----------------------------------------------------------"<<endl;
    cout << "                                      Enter Voter CNIC No (13 digits): ";
    while (true) {
        cin >> voterCnic;
        if (voterCnic == "XX" || voterCnic == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        bool valid = true;
        for (char c : voterCnic) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (voterCnic.length() != 13 || !valid) {
            cout << "                                      CNIC must be exactly 13 digits and contain only numbers. Please re-enter: ";
        } else if (registeredCnic.find(voterCnic) != registeredCnic.end()) {
            cout << "                                      This CNIC is already registered. Please enter a different CNIC: ";
        } else {
            registeredCnic.insert(voterCnic); // Add CNIC to set
            break;
        }
    }

    cin.ignore(); // Clear input buffer

    // Prompt for name
    do {
        cout << "                                      Enter your Name: ";
        getline(cin, voterName);
        if (voterName.empty()) {
            cout << "                                      Name cannot be empty. Please re-enter." << endl;
        }
    } while (voterName.empty());

    // Prompt for father's name
    do {
        cout << "                                      Enter your Father's Name: ";
        getline(cin, voterFatherName);
        if (voterFatherName.empty()) {
            cout << "                                      Father's Name cannot be empty. Please re-enter." << endl;
        }
    } while (voterFatherName.empty());

    // Prompt for address
    do {
        cout << "                                      Enter your Address: ";
        getline(cin, voterAddress);
        if (voterAddress.empty()) {
            cout << "                                      Address cannot be empty. Please re-enter." << endl;
        }
    } while (voterAddress.empty());

    string phoneInput;
    while (true) {
        cout << "                                      Enter your Phone No: ";
        cin >> phoneInput;
        if (phoneInput == "XX" || phoneInput == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        stringstream ss(phoneInput);
        if (ss >> voterPhoneNo && to_string(voterPhoneNo).length() == 10 && ss.eof()) {
            break; // Valid input, exit the loop
        } else {
            cout << "                                      Invalid input. Please enter a valid 11-digit phone number: ";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
    cin.ignore(); // Clear input buffer

    bool validGender = false;
    string inputGender;
    do {
        cout << "                                      Enter your Gender (male/female or m/f): ";
        cin >> inputGender;
        if (inputGender == "XX" || inputGender == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        // Convert input gender to lowercase for case-insensitive comparison
        transform(inputGender.begin(), inputGender.end(), inputGender.begin(), ::tolower);
        if (inputGender == "male" || inputGender == "female" || inputGender == "m" || inputGender == "f") {
            validGender = true;
        } else {
            cout << "                                      Invalid input. Gender must be male, female, m, or f. Please re-enter." << endl;
            // Clear input buffer before re-entering the loop
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    } while (!validGender);
    cin.ignore(numeric_limits<int>::max(), '\n'); // Clear input buffer

    // Prompt for email
    do {
        cout << "                                      Enter your Email: ";
        getline(cin, voterEmail);
        if (voterEmail.empty()) {
            cout << "                                      Email cannot be empty. Please re-enter." << endl;
        }
    } while (voterEmail.empty());

}

void Voter::showVoterDetails() {
    cout << "                   CNIC NO: " << voterCnic << endl << endl;
    cout << "                   Name: " << voterName << endl << endl;
    cout << "                   Father Name: " << voterFatherName << endl << endl;
    cout << "                   Address: " << voterAddress << endl << endl;
    cout << "                   Phone No: " << voterPhoneNo << endl << endl;
    cout << "                   Gender: " << voterGender << endl << endl;
    cout << "                   Email: " << voterEmail << endl << endl;

}

int Voter::getVotedCandidateIndex(int numCandidates) {
    int choice;
    cout << "Choose a candidate to vote for (1-" << numCandidates << "): ";
    cin >> choice;
    cin.ignore();
    return choice - 1;
}
