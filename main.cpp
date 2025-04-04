#include <iostream>
#include "Candidate.h"
#include "Voters.h"
#include "Voting.h"
#include<windows.h>

void printLogo() {
    cout << "                                      ======================================" << endl;
    cout << "                                              Welcome to Election System     " << endl;
    cout << "                                      ======================================" << endl;
    cout<<"             _____  .__          ____ ___      .__                          .__  __          \n"
          "            /  _  \\ |__|______  |    |   \\____ |__|__  __ ___________  _____|__|/  |_ ___.__.\n"
          "           /  /_\\  \\|  \\_  __ \\ |    |   /    \\|  \\  \\/ // __ \\_  __ \\/  ___/  \\   __<   |  |\n"
          "          /    |    \\  ||  | \\/ |    |  /   |  \\  |\\   /\\  ___/|  | \\/\\___ \\|  ||  |  \\___  |\n"
          "          \\____|__  /__||__|    |______/|___|  /__| \\_/  \\___  >__|  /____  >__||__|  / ____|\n"
          "                  \\/                         \\/              \\/           \\/          \\/     "<<endl<<endl<<endl<<endl;
    cout << "\n\n\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
    cout << "\n\n\t\t\t\t\t\t--------------------"; Sleep(500);
    cout << "\n\n\t\t\t\t     QASIM TARIQ       "; Sleep(1000);
    cout << "\n\n\t\t\t\t     MUHAMMAD ANNAS             "; Sleep(2000);
    cout << "\n\n\t\t\t\t     MUHAMMAD SAAD       "; Sleep(2000);
    cout << endl;
    system("cls");
}

int main() {
    long long choice;
    int numCandidates = 0, numVoters = 0;
    Candidate* candidateArray = nullptr;
    Voter* voterArray = nullptr;
    Voting election;

    printLogo();
    do {
        cout << "-----------------------------------------------------------" << endl;
        cout << "Election Management System Menu:" << endl;
        cout << "1. Add Candidate" << endl;
        cout << "2. Add Voter" << endl;
        cout << "3. Start Voting" << endl;
        cout << "4. Display Candidates" << endl; // New option
        cout << "5. Display Voters" << endl; // New option
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<long long>::max(), '\n');
        }
        //cin.ignore();
        cout << "-----------------------------------------------------------" << endl;

        switch (choice) {
            case 1:
                cout << "Enter the number of candidates (should be more than 1): ";
                while (!(cin >> numCandidates) || numCandidates < 2) {
                    cout << "Invalid input. Please enter a valid integer greater than 1: ";
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                }
                cout << "-----------------------------------------------------------" << endl;
                candidateArray = new Candidate[numCandidates];
                for (int j = 0; j < numCandidates; j++) {
                    cout << "          Candidate No " << j + 1 << ", Enter your details:" << endl;
                    candidateArray[j].enterCandidateDetails(election.getRegisteredCnic());
                    cout << "-----------------------------------------------------------" << endl;
                    system("cls");
                }
                election.writeCandidateInfoToFile(candidateArray, numCandidates);
                break;


            case 2:
                cout << "Enter the number of voters: ";
                while (!(cin >> numVoters)) {
                    cout << "Invalid input. Please enter a valid integer: ";
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                }
                cout << "-----------------------------------------------------------" << endl;
                voterArray = new Voter[numVoters];
                for (int j = 0; j < numVoters; j++) {
                    cout << "          Voter No " << j + 1 << ", Enter your details:" << endl;
                    voterArray[j].enterVoterDetails(election.getRegisteredCnic());
                    cout << "-----------------------------------------------------------" << endl;
                    system("cls");
                }
                election.writeVoterInfoToFile(voterArray, numVoters);
                break;

            case 3:
                if (numCandidates == 0 || numVoters == 0) {
                    cout << "Please add candidates and voters first!" << endl;
                } else {
                    election.startVoting(candidateArray, numCandidates, voterArray, numVoters);
                }
                break;

            case 4:
                if (numCandidates == 0) {
                    cout << "No candidates added yet!" << endl;
                } else {
                    election.displayCandidates(candidateArray, numCandidates);
                }
                break;

            case 5:
                if (numVoters == 0) {
                    cout << "No voters added yet!" << endl;
                } else {
                    election.displayVoters(voterArray, numVoters);
                }
                break;

            case 6:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }
    } while (choice != 6);

    // Call the storeResult function before exiting
    election.storeResult(candidateArray, numCandidates);

    if (candidateArray) {
        delete[] candidateArray;
    }
    if (voterArray) {
        delete[] voterArray;
    }

    return 0;
}
