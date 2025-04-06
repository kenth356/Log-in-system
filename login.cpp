// Log-in C++
// Mariano, Kenth Jarren S.
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct userDC {
    string name, pass;
};

vector<userDC> usersD;
string REGISname;

void REGIS();
void LOGIN();
void HOMESCR();
void EXIT();
void SAVEDFILES();

int main() {
    while (true) {
        int choice;
        cout << endl << endl << right << setw(75) << "================================";
        cout << endl << right << setw(66) << "[   WELCOME   ]";
        cout << endl << right << setw(75) << "================================" << endl;
        cout << endl << right << setw(86) << "1. Registration           2. Log in          3. Exit";
        cout << endl << right << setw(89) << "----------------------------------------------------------";
        cout << endl << endl << right << setw(39) << "Enter: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
            REGIS();
            break;
            case 2:
            LOGIN();
            break;
            case 3:
            EXIT();
            return 0;
            default:
            cout << endl << right << setw(88) << "--------------------------------------------------------";
            cout << endl << endl << right << setw(76) << "[  PLEASE ENTER A CORRECT INPUT  ]";
            cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
        }
    }
    return 0;
}

void REGIS() {
    userDC newUSERS;
    cout << endl << endl << right << setw(75) << "===============================";
    cout << endl << right << setw(68) << "[  REGISTRATION  ]";
    cout << endl << right << setw(75) << "===============================" << endl;
    cout << endl << right << setw(88) << "--------------------------------------------------------";
    cout << endl << endl << right << setw(54) << "Enter your full name: ";
    getline (cin, newUSERS.name);
    cout << endl << right << setw(88) << "--------------------------------------------------------";
    cout << endl << endl << right << setw(54) << "Create your password: ";
    getline (cin, newUSERS.pass);
    usersD.push_back(newUSERS);
    SAVEDFILES();
    cout << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
    cout << endl << right << setw(88) << "--------------------------------------------------------";
    cout << endl << endl << right << setw(74) << "[  REGISTRATION SUCCESSFUL  ]";
    cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
    return;
}

void LOGIN() {
    while (true) {
    string LOGINname, LOGINpass;
    bool USERHANDLING = false, PASSHANDLING = false;
    cout << endl << endl << right << setw(75) << "===============================";
    cout << endl << right << setw(66) << "[  LOG - IN  ]";
    cout << endl << right << setw(75) << "===============================" << endl;
    cout << endl << right << setw(88) << "--------------------------------------------------------";
    cout << endl << endl << right << setw(54) << "Enter your full name: ";
    getline (cin, LOGINname);
    cout << endl << right << setw(88) << "--------------------------------------------------------";
    cout << endl << endl << right << setw(54) << "Enter your password: ";
    getline (cin, LOGINpass);
    cout << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
    for (const auto &users : usersD) {
        if (users.name == LOGINname) {
            USERHANDLING = true;
        if (users.pass == LOGINpass) {
            PASSHANDLING = true;
            cout << endl << right << setw(88) << "--------------------------------------------------------";
            cout << endl << endl << right << setw(72) << "[  LOG - IN SUCCESSFUL  ]";
            cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
            REGISname = users.name;
            HOMESCR();
            return;
        } break;
      }
    } if (!USERHANDLING) {
        cout << endl << right << setw(88) << "--------------------------------------------------------";
        cout << endl << endl << right << setw(70) << "[  USER NOT FOUND  ]";
        cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
    } else if (!PASSHANDLING) {
        for (int i = 0; i < 3; i++) {
            cout << endl << right << setw(88) << "--------------------------------------------------------";
            cout << endl << endl << right << setw(71) << "[  INCORRECT INPUT  ]";
            cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
          }
       }
    }
}

void HOMESCR() {
    while (true) {
        int choice;
        cout << endl << endl << right << setw(82) << "============================================";
        cout << endl << right << setw(58) << "[  WELCOME  " << REGISname << " ]";
        cout << endl << right << setw(82) << "============================================" << endl;
        cout << endl << right << setw(48) << "1. Return";
        cout << endl << right << setw(88) << "--------------------------------------------------------";
        cout << endl << endl << right << setw(39) << "Enter: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
            return;
            default:
            cout << endl << right << setw(88) << "--------------------------------------------------------";
            cout << endl << endl << right << setw(76) << "[  PLEASE ENTER A CORRECT INPUT  ]";
            cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
        }
    }
}

void EXIT() {
    cout << endl << endl << right << setw(88) << "--------------------------------------------------------";
                cout << endl << endl << right << setw(67) << "[  THANK YOU  ]";
                cout << endl << endl << right << setw(88) << "--------------------------------------------------------" << endl << endl;
}

void SAVEDFILES() {
    ofstream file ("users.txt");
    for (const auto &users : usersD) {
        file << "NAME: " << users.name << "\n"
        << "PASSWORD: " << users.pass << "\n";
    }
}