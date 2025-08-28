#include <iostream>
#include <string.h>
// #include <conio> // For getch() using namespace std;

class Registration
{
private:
    string name, fname, mname, vname, uname, password;
    long long mno;

public:
    void getData()
    {
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "Enter Father's Name: ";
        cin >> fname;
        cout << "Enter Mother's Name: ";
        cin >> mname;
        cout << "Enter Village/City Name: ";
        cin >> vname;
        cout << "Enter Mobile Number: ";
        cin >> mno;
        cout << "Enter Username: ";
        cin >> uname;
        getPassword();
    }

    void getPassword()
    {
        char ch;
        password = "";
        cout << "Enter Password: ";
        while ((ch = getch()) != '\r')
        {
            password += ch;
            cout << '*'; // Masking password input
        }
        cout << endl;
    }

    void displayData()
    {
        cout << "\nName: " << name;
        cout << "\nFather's Name: " << fname;
        cout << "\nMother's Name: " << mname;
        cout << "\nVillage/City: " << vname;
        cout << "\nMobile No: " << mno;
        cout << "\nUsername: " << uname << endl;
    }

    bool search(string query)
    {
        return (uname == query || to_string(mno) == query || password == query);
    }
};

class Login
{
private:
    string username, password;

public:
    void getData()
    {
        cout << "\nEnter Username: ";
        cin >> username;
        getPassword();
    }

    void getPassword()
    {
        char ch;
        password = "";
        cout << "Enter Password: ";
        while ((ch = getch()) != '\r')
        {
            password += ch;
            cout << '*'; // Masking password input
        }
        cout << endl;
    }

    bool authenticate(const string &uname, const string &pass)
    {
        return (username == uname && password == pass);
    }
};

class HelpCenter
{
public:
    void showHelp()
    {
        int choice;
        cout << "\n** HELP CENTER **";
        cout << "\n1. Registration Help";
        cout << "\n2. Login Help";
        cout << "\nChoose an option: ";
        cin >> choice;
        showLanguageOptions(choice);
    }

    void showLanguageOptions(int choice)
    {
        int lang;
        cout << "\nSelect Language:";
        cout << "\n1. English";
        cout << "\n2. Hindi";
        cout << "\nChoice: ";
        cin >> lang;

        if (choice == 1)
        {
            if (lang == 1)
                registrationHelpEnglish();
            else
                registrationHelpHindi();
        }
        else if (choice == 2)
        {
            if (lang == 1)
                loginHelpEnglish();
            else
                loginHelpHindi();
        }
    }

    void registrationHelpEnglish()
    {
        cout << "\nTo register, enter your personal details, create a username, and set a strong password.";
    }

    void registrationHelpHindi()
    {
        cout << "\n\"Panjikaran ke liye, apni vyaktigat jankari bharein, ek username banayein, aur ek mazboot password set karein.\"";
    }

    void loginHelpEnglish()
    {
        cout << "\nTo log in, enter your username and password correctly.";
    }

    void loginHelpHindi()
    {
        cout << "\n\"Login karne ke liye, apna username aur password sahi se daalein.\"";
    }
};
int main()
{
    Registration reg;
    Login log;
    HelpCenter help;
    int choice;

    do
    {
        cout << "\n** STUDENT RECORD SYSTEM **";
        cout << "\n1. Registration";
        cout << "\n2. Login";
        cout << "\n3. Help Center";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            reg.getData();
            break;
        case 2:
            log.getData();
            break;
        case 3:
            help.showHelp();
            break;
        case 4:
            cout << "\nExiting...";
            break;
        default:
            cout << "\nInvalid choice!";
        }
    } while (choice != 4);

    return 0;
}