//
// Created by DELL on 4/29/2024.
//

#include "Candidate.h"


void Candidate::enterCandidateDetails(unordered_set<string>& registeredCnic) {
    cout<<"                                      Press XX at any time to return to main menu                "<<endl;
    cout<<"                -----------------------------------------------------------"<<endl;
    cout << "                                      Enter Candidate CNIC No (13 digits): ";

    while (true) {
        cin >> cnic;
        if (cnic == "XX" || cnic == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        bool valid = true;
        for (char c : cnic) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (cnic.length() != 13 || !valid) {
            cout << "                                      CNIC must be exactly 13 digits and contain only numbers. Please re-enter: ";
        } else if (registeredCnic.find(cnic) != registeredCnic.end()) {
            cout << "                                      This CNIC is already registered. Please enter a different CNIC: ";
        } else {
            registeredCnic.insert(cnic); // Add CNIC to set
            break;
        }
    }

    string assemblyInput;
    while (true) {
        cout << "                                      Enter Candidate Assembly No: ";
        cin >> assemblyInput;
        if (assemblyInput == "XX" || assemblyInput == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        stringstream ss(assemblyInput);
        if (ss >> assemblyNo && ss.eof()) {
            break; // Valid input, exit the loop
        } else {
            cout << "                                      Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
    cin.ignore();

    // Prompt for name
    do {
        cout << "                                      Enter Candidate Name: ";
        getline(cin, name);
        if (name.empty()) {
            cout << "                                      Name cannot be empty. Please re-enter." << endl;
        }
    } while (name.empty());

    // Prompt for constituency
    do {
        cout << "                                      Enter Candidate Constituency: ";
        getline(cin, constituency);
        if (constituency.empty()) {
            cout << "                                      Constituency cannot be empty. Please re-enter." << endl;
        }
    } while (constituency.empty());

    // Prompt for party
    do {
        cout << "                                      Enter Candidate Party: ";
        getline(cin, party);
        if (party.empty()) {
            cout << "                                      Party cannot be empty. Please re-enter." << endl;
        }
    } while (party.empty());

    // Prompt for electoral symbol
    do {
        cout << "                                      Enter Candidate Electoral Symbol: ";
        getline(cin, electoralSymbol);
        if (electoralSymbol.empty()) {
            cout << "                                      Electoral Symbol cannot be empty. Please re-enter." << endl;
        }
    } while (electoralSymbol.empty());

    // Prompt for local address
    do {
        cout << "                                      Enter Candidate Local Address: ";
        getline(cin, localAddress);
        if (localAddress.empty()) {
            cout << "                                      Local Address cannot be empty. Please re-enter." << endl;
        }
    } while (localAddress.empty());

    bool validGender = false;
    while (!validGender) {
        cout << "                                      Enter Candidate Gender (male/female or m/f): ";
        getline(cin, gender);
        if (gender.empty()) {
            cout << "                                      Gender cannot be empty. Please re-enter." << endl;
        } else {
            // Convert gender to lowercase manually
            transform(gender.begin(), gender.end(), gender.begin(), ::tolower);
            if (gender == "male" || gender == "m" || gender == "female" || gender == "f") {
                validGender = true;
            } else {
                cout << "                                      Invalid input. Gender must be male, female, m, or f. Please re-enter." << endl;
            }
        }
    }

    string phoneInput;
    while (true) {
        cout << "                                      Enter Candidate Phone No: ";
        cin >> phoneInput;
        if (phoneInput == "XX" || phoneInput == "xx") {
            cout << "                                      Returning to the main menu..." << endl;
            return;
        }
        stringstream ss(phoneInput);
        if (ss >> phoneNo && to_string(phoneNo).length() == 10 && ss.eof()) {
            break; // Valid input, exit the loop
        } else {
            cout << "                                      Invalid input. Please enter a valid 11-digit phone number: ";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    }
    cin.ignore();

}

void Candidate::displayCandidateDetails() {
    cout << "                   CNIC: " << cnic << endl << endl;
    cout << "                   Assembly No: " << assemblyNo << endl << endl;
    cout << "                   Name: " << name << endl << endl;
    cout << "                   Constituency: " << constituency << endl << endl;
    cout << "                   Party: " << party << endl << endl;
    cout << "                   Electoral Symbol: " << electoralSymbol << endl << endl;
    cout << "                   Local Address: " << localAddress << endl << endl;
    cout << "                   Gender: " << gender << endl << endl;
    cout << "                   Phone No: " << phoneNo << endl << endl;
    cout << "                   Votes: " << votes << endl << endl; // Display votes

}

string Candidate::getName() const {
    return name;
}
