#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// Registration Class
class Registration {
public:
    string name, fname, mname, vname, uname,pass,mno;
    

    void getdata() {
        cout << "\n\tEnter your name: ";
        getline(cin,name);
        cout << "\tEnter your father's name: ";
        getline(cin,fname);
        cout << "\tEnter your mother's name: ";
        getline(cin,mname);
        cout << "\tEnter your village/city name: ";
        getline(cin,vname);
        cout << "\tEnter your mobile number: ";
        getline(cin,mno);
        cout << "\tEnter your username: ";
        getline(cin,uname);
        cout << "\tEnter a strong password: ";
       getline(cin,pass);
    }

    void putdata() const {
        cout << "\n\tName: " << name << endl;
        cout << "\tFather's Name: " << fname << endl;
        cout << "\tMother's Name: " << mname << endl;
        cout << "\tVillage/City: " << vname << endl;
        cout << "\tMobile Number: " << mno << endl;
        cout << "\tUsername: " << uname << endl;
        cout << "\tPassword: ********" << endl; // Hide password
    }

    void del() {
        cout << "\n\tAll data deleted!" << endl;
    }

    bool search(string searchElement) const {
        return (searchElement == mno || searchElement == pass);
    }
};

// Login Class
class Login {
public:
    string sname,password;
    

    void getdata() {
        cout << "\n\tEnter your username: ";
        cin >> sname;
        cout << "\tEnter your password: ";
        cin >> password;
    }

    void putdata() const {
        cout << "\n\tUsername: " << sname << endl;
        cout << "\tPassword: ********" << endl; // Hide password
    }

    bool search(string searchElement) const {
        return (searchElement == password);
    }

    void del() {
        cout << "\n\tAll data deleted!" << endl;
    }
};

// Help Class
class Help {
public:
    static void showRegistrationHelp() {
        cout << "\n\tHelp - Registration Process:\n";
        cout << "\t1. Enter your name, father's name, mother's name, etc.\n";
        cout << "\t2. Choose a strong password.\n";
        cout << "\t3. You will be registered after entering details.\n";
    }

    static void showLoginHelp() {
        cout << "\n\tHelp - Login Process:\n";
        cout << "\t1. Enter your username and password to log in.\n";
        cout << "\t2. If successful, you will be logged in.\n";
    }
};

// File Handling Functionality
void saveRegistrationData(const vector<Registration>& registrations) {
    ofstream outFile("registration_data.txt", ios::binary);
    for (const auto& reg : registrations) {
        outFile.write(reinterpret_cast<const char*>(&reg), sizeof(reg));
    }
    outFile.close();
}

void loadRegistrationData(vector<Registration>& registrations) {
    ifstream inFile("registration_data.txt", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&registrations.emplace_back()), sizeof(Registration))) {}
    inFile.close();
}

void saveLoginData(const vector<Login>& logins) {
    ofstream outFile("login_data.txt", ios::binary);
    for (const auto& login : logins) {
        outFile.write(reinterpret_cast<const char*>(&login), sizeof(login));
    }
    outFile.close();
}

void loadLoginData(vector<Login>& logins) {
    ifstream inFile("login_data.txt", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&logins.emplace_back()), sizeof(Login))) {}
    inFile.close();
}

// Utility function to get user input with validation
int getValidIntInput() {
    int input;
    while (!(cin >> input)) {
        cout << "\tInvalid input, please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

// Menu Display Function
void displayMainMenu() {
    cout << "\n\t*** WELCOME TO STUDENT RECORD SYSTEM ***";
    cout << "\n\t1. Registration";
    cout << "\n\t2. Login";
    cout << "\n\t3. Help";
    cout << "\n\t4. Exit";
    cout << "\n\tSelect your choice: ";
}

void displayRegistrationMenu() {
    cout << "\n\t*** Registration Menu ***";
    cout << "\n\t1. Insert Data";
    cout << "\n\t2. Display Data";
    cout << "\n\t3. Update Data";
    cout << "\n\t4. Search Data";
    cout << "\n\t5. Delete Data";
    cout << "\n\t6. Exit";
    cout << "\n\tSelect your choice: ";
}

void displayLoginMenu() {
    cout << "\n\t*** Login Menu ***";
    cout << "\n\t1. Insert Data";
    cout << "\n\t2. Display Data";
    cout << "\n\t3. Update Data";
    cout << "\n\t4. Search Data";
    cout << "\n\t5. Delete Data";
    cout << "\n\t6. Exit";
    cout << "\n\tSelect your choice: ";
}

void displayHelpMenu() {
    cout << "\n\t*** Help Menu ***";
    cout << "\n\t1. Registration Help";
    cout << "\n\t2. Login Help";
    cout << "\n\t3. Exit";
    cout << "\n\tSelect your choice: ";
}

int main() {
    vector<Registration> registrations;
    vector<Login> logins;

    // Load data from file at the start
    loadRegistrationData(registrations);
    loadLoginData(logins);

    char ans;
    do {
        int mainChoice;
        displayMainMenu();
        mainChoice = getValidIntInput();

        switch (mainChoice) {
            case 1: {
                char regAns;
                do {
                    int regChoice;
                    displayRegistrationMenu();
                    regChoice = getValidIntInput();

                    switch (regChoice) {
                        case 1: {
                            Registration newReg;
                            newReg.getdata();
                            registrations.push_back(newReg);
                            saveRegistrationData(registrations);
                            break;
                        }
                        case 2: {
                            for (const auto& reg : registrations) {
                                reg.putdata();
                            }
                            break;
                        }
                        case 3: {
                            int idx;
                            cout << "\tEnter the index of record to update: ";
                            cin >> idx;
                            if (idx >= 0 && idx < registrations.size()) {
                                registrations[idx].getdata();
                                saveRegistrationData(registrations);
                            } else {
                                cout << "\tInvalid index!" << endl;
                            }
                            break;
                        }
                        case 4: {
                            string searchElement;
                            cout << "\tEnter mobile number or password to search: ";
                            searchElement = getValidIntInput();
                            bool found = false;
                            for (const auto& reg : registrations) {
                                if (reg.search(searchElement)) {
                                    cout << "\tRecord found!" << endl;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                cout << "\tRecord not found!" << endl;
                            }
                            break;
                        }
                        case 5: {
                            int idx;
                            cout << "\tEnter the index of record to delete: ";
                            cin >> idx;
                            if (idx >= 0 && idx < registrations.size()) {
                                registrations[idx].del();
                                registrations.erase(registrations.begin() + idx);
                                saveRegistrationData(registrations);
                            } else {
                                cout << "\tInvalid index!" << endl;
                            }
                            break;
                        }
                        case 6:
                            cout << "\tExiting Registration Menu.\n";
                            break;
                        default:
                            cout << "\tInvalid choice, please try again.\n";
                    }
                    if (regChoice != 6) {
                        cout << "\n\tDo you want to continue? (Y/N): ";
                        cin >> regAns;
                    }
                } while (regAns == 'Y' || regAns == 'y');
                break;
            }
            case 2: {
                // Similarly handle login menu here...
            }
            case 3: {
                char helpAns;
                do {
                    int helpChoice;
                    displayHelpMenu();
                    helpChoice = getValidIntInput();

                    switch (helpChoice) {
                        case 1:
                            Help::showRegistrationHelp();
                            break;
                        case 2:
                            Help::showLoginHelp();
                            break;
                        case 3:
                            cout << "\tExiting Help Menu.\n";
                            break;
                        default:
                            cout << "\tInvalid choice, please try again.\n";
                    }
                    if (helpChoice != 3) {
                        cout << "\n\tDo you want to continue? (Y/N): ";
                        cin >> helpAns;
                    }
                } while (helpAns == 'Y' || helpAns == 'y');
                break;
            }
            case 4:
                cout << "\tExiting the system.\n";
                break;
            default:
                cout << "\tInvalid choice, please try again.\n";
        }

        if (mainChoice != 4) {
            cout << "\n\tDo you want to continue? (Y/N): ";
            cin >> ans;
        }

    } while (ans == 'Y' || ans == 'y');

    return 0;
}
