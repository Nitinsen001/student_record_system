#include <iostream>
#include <conio.h>  // For getch()
#include <unordered_map> // For storing user credentials securely

using namespace std;

class Registration {
    string name, fname, mname, vname, uname, password;
    long long mno;

public:
    void getData() {
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "\nEnter Father's Name: ";
        cin >> fname;
        cout << "\nEnter Mother's Name: ";
        cin >> mname;
        cout << "\nEnter Village/City Name: ";
        cin >> vname;
        cout << "\nEnter Mobile No.: ";
        getline (cin, mno);
        cout << "\nEnter Username: ";
        cin >> uname;
        getPassword(password);
    }

    void putData() {
        cout << "\nName: " << name;
        cout << "\nFather's Name: " << fname;
        cout << "\nMother's Name: " << mname;
        cout << "\nVillage/City: " << vname;
        cout << "\nMobile No.: " << mno;
        cout << "\nUsername: " << uname;
        cout << "\nPassword: [Hidden]" << endl;
    }

    bool search(string query) {
        return (uname == query || to_string(mno) == query || password == query);
    }

    static void getPassword(string &password) {
        char ch;
        password = "";
        cout << "Enter Password: ";
        
        while (true) {
            ch = getch();
            if (ch == '\r') { // Enter key
                break;
            } else if (ch == '\b' && !password.empty()) { // Handle Backspace
                cout << "\b \b";
                password.pop_back();
            } else if (ch != '\b') {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;
    }
};

class Login {
    string username, password;

public:
    void getData() {
        cout << "\nEnter Username: ";
        cin >> username;
        Registration::getPassword(password);
    }

    bool authenticate(const unordered_map<string, string> &users) {
        auto it = users.find(username);
        return (it != users.end() && it->second == password);
    }
};

int main() {
    unordered_map<string, string> users = {
        {"admin", "secure123"},
        {"user1", "password1"},
        {"nitin", "aiml2025"}
    };
    
    int choice;
    Registration reg;
    Login log;
    
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                reg.getData();
                cout << "\nRegistration Successful!" << endl;
                break;
            case 2:
                log.getData();
                if (log.authenticate(users)) {
                    cout << "\nLogin Successful! Welcome, " << endl;
                } else {
                    cout << "\nInvalid Username or Password!" << endl;
                }
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);
    
    return 0;
}