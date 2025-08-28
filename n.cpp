#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class registration {
    char name[20], fname[20], mname[20], vname[30], uname[30];
    int pass, mno;

public:
    void getdata() {
        cout << "\n\t\t\tenter your name = ";
        cin >> name;
        cout << "\n\t\t\tenter your father name = ";
        cin >> fname;
        cout << "\n\t\t\tenter your mother name = ";
        cin >> mname;
        cout << "\n\t\t\tenter your village/city name = ";
        cin >> vname;
        cout << "\n\t\t\tenter your mobile no. = ";
        cin >> mno;
        cout << "\n\t\t\tenter your username = ";
        cin >> uname;
        cout << "\n\t\t\tenter a strong password = ";
        cin >> pass;
    }

    void putdata() {
        cout << "\n\t\t\tyour name = " << name << endl;
        cout << "\n\t\t\tfather name = " << fname << endl;
        cout << "\n\t\t\tmother name = " << mname << endl;
        cout << "\n\t\t\tvillage/city name = " << vname << endl;
        cout << "\n\t\t\tmobile no. = " << mno << endl;
        cout << "\n\t\t\tusername name = " << uname << endl;
        cout << "\n\t\t\tpassword = ********" << endl;  // Hide password
    }

    void del() {
        cout << "\n\t\t\tALL DATA DELETED";
    }

    void ser() {
        int d;
        cout << "\t\t\tYOU CAN ONLY SEARCH MOBILE NO. OR PASSWORD";
        cout << "\n\t\t\tENTER THE SEARCHING ELEMENT = ";
        cin >> d;
        if (d == mno || d == pass) {
            cout << "\n\t\t\t---element is found---";
        } else {
            cout << "\n\t\t\t---element is not found---";
        }
    }
};

class login {
    char sname[20];
    int password;

public:
    void getdata() {
        cout << "\n\t\t\tenter your user name = ";
        cin >> sname;
        cout << "\n\t\t\tenter your password = ";
        cin >> password;
    }

    void putdata() {
        cout << "\n\t\t\tname = " << sname;
        cout << "\n\t\t\tpassword = ********"; // Hide password
    }

    void ser() {
        int g;
        cout << "\t\t\tYOU CAN ONLY SEARCH PASSWORD";
        cout << "\n\t\t\tENTER THE SEARCHING ELEMENT = ";
        cin >> g;
        if (g == password) {
            cout << "\n\t\t\t---element is found---";
        } else {
            cout << "\n\t\t\t---element is not found---";
        }
    }

    void del() {
        cout << "\n\t\t\tALL DATA DELETED";
    }
};

class help {
public:
    void regi() {
        cout << "\n\t\t\t**YOU HERE FOR TROUBLE IN REGISTRATION** \n";
        cout << "\n\t\t\t       it is very simple process";
        cout << "\n\t\t\t    you insert your personal details";
        cout << "\n\t\t\t     you face with this interface\n";
        cout << "\n\t\t\t  ! enter your name = ";
        cout << "\n\t\t\t  ! enter your father name = ";
        cout << "\n\t\t\t  ! enter your mother name = ";
        cout << "\n\t\t\t  ! enter your village/city name = ";
        cout << "\n\t\t\t  ! enter your mobile no. = ";
        cout << "\n\t\t\t  ! enter your username = ";
        cout << "\n\t\t\t  ! enter a strong password = \n";
        cout << "\n\t\t\t   **AFTER INSERTING THE DETAILS";
        cout << "\n\t\t\t---congrats you complete your registration---";
    }
    void log() {
        cout << "\n\t\t\t**YOU HERE FOR TROUBLE IN LOGIN** \n";
        cout << "\n\t\t\t       it is very simple process";
        cout << "\n\t\t\t    you insert your personal details";
        cout << "\n\t\t\t     you face with this interface\n";
        cout << "\n\t\t\t  ! enter your username = ";
        cout << "\n\t\t\t  ! enter a strong password = \n";
        cout << "\n\t\t\t   **AFTER INSERTING THE DETAILS";
        cout << "\n\t\t\t---congrats you complete your login---";
    }
};

int main() {
    fstream f1;
    registration r1[1];
    login l1[1];
    help h1[1];
    int x;
    char ans;
    do {
        cout << "\t\t\t*** WELCOME TO STUDENT RECORD SYSTEM  ***" << endl;
        cout << "\t\t\t***                                   ***" << endl;
        cout << "\t\t\t***      1.REGISTRATION               ***" << endl;
        cout << "\t\t\t***                                   ***" << endl;
        cout << "\t\t\t***      2.LOGIN                      ***" << endl;
        cout << "\t\t\t***                                   ***" << endl;
        cout << "\t\t\t***      3.HELP                       ***" << endl;
        cout << "\t\t\t***                                   ***" << endl;
        cout << "\t\t\t***      4.EXIT                       ***" << endl;
        cout << "\t\t\t***                                   ***" << endl;
        cout << "\t\t\t***      SELECT YOUR CHOICE           ***" << endl;
        cout << "\t\t\t\tCHOICE = ";
        cin >> x;
        switch (x) {
        case 1:
            {
                char s;
                do {
                    f1.open("res.txt", ios::in | ios::out | ios::app);
                    int a;
                    cout << "\n\t\t\t**";
                    cout << "\n\t\t\t***  WELCOME TO REGISTRATION PAGE  ***";
                    cout << "\n\t\t\t***          1.INSERT              ***";
                    cout << "\n\t\t\t***          2.DISPLAY             ***";
                    cout << "\n\t\t\t***          3.UPDATE              ***";
                    cout << "\n\t\t\t***          4.SEARCHING           ***";
                    cout << "\n\t\t\t***          5.DELETE              ***";
                    cout << "\n\t\t\t***          6.EXIT                ***";
                    cout << "\n\t\t\t**";
                    cout << "\n\t\t\t\tCHOICE = ";
                    cin >> a;

                    if (a == 1) {
                        cout << "\n\t\t\tINSERT YOUR DATA";
                        r1[0].getdata();
                        f1.write((char *)&r1[0], sizeof(r1[0]));
                    }
                    else if (a == 2) {
                        f1.read((char *)&r1[0], sizeof(r1[0]));
                        r1[0].putdata();
                    }
                    else if (a == 3) {
                        cout << "\n\t\t\tINSERT YOUR DATA";
                        r1[0].getdata();
                        f1.seekp(0);  // Move to the start of the file
                        f1.write((char *)&r1[0], sizeof(r1[0]));
                    }
                    else if (a == 4) {
                        r1[0].ser();
                    }
                    else if (a == 5) {
                        r1[0].del();
                    }
                    else
                        cout << "\n\t\t\tTHANK U \n\t\t\tYOU EXIT THIS PAGE";
                    cout << "\n\t\t\tDO YOU WANT TO CONTINUE (Y/N)? ";
                    cin >> s;
                } while (s == 'y' || s == 'Y');
                f1.close();
            }
            break;
        case 2:
            {
                char f;
                f1.open("lod.txt", ios::in | ios::out | ios::app);
                int b;
                do {
                    cout << "\n\t\t\t*";
                    cout << "\n\t\t\t***  WELCOME TO LOGIN PAGE  ***";
                    cout << "\n\t\t\t***        1.INSERT         ***";
                    cout << "\n\t\t\t***        2.DISPLAY        ***";
                    cout << "\n\t\t\t***        3.UPDATE         ***";
                    cout << "\n\t\t\t***        4.SEARCHING      ***";
                    cout << "\n\t\t\t***        5.DELETE         ***";
                    cout << "\n\t\t\t***        6.EXIT           ***";
                    cout << "\n\t\t\t*";
                    cout << "\n\t\t\tCHOICE = ";
                    cin >> b;

                    if (b == 1) {
                        l1[0].getdata();
                        f1.write((char *)&l1[0], sizeof(l1[0]));
                    }
                    else if (b == 2) {
                        f1.read((char *)&l1[0], sizeof(l1[0]));
                        l1[0].putdata();
                    }
                    else if (b == 3) {
                        l1[0].getdata();
                        f1.seekp(0);
                        f1.write((char *)&l1[0], sizeof(l1[0]));
                    }
                    else if (b == 4) {
                        l1[0].ser();
                    }
                    else if (b == 5) {
                        l1[0].del();
                    }
                    else
                        cout << "\n\t\t\tTHANK U \n\t\t\tYOU EXIT THIS PAGE";
                    cout << "\n\t\t\tDO YOU WANT TO CONTINUE (Y/N)? ";
                    cin >> f;
                } while (f == 'y' || f == 'Y');
                f1.close();
            }
            break;
        case 3:
            {
                char v;
                f1.open("help.txt", ios::out | ios::app);
                int y;
                do {
                    cout << "\n\t\t\t**";
                    cout << "\n\t\t\t***       WELCOME TO HELP PAGE         ***";
                    cout << "\n\t\t\t***  IN WHICH CASE DO YOU NEED HELP?   ***";
                    cout << "\n\t\t\t***           1.REGISTRATION           ***";
                    cout << "\n\t\t\t***           2.LOGIN                  ***";
                    cout << "\n\t\t\t***           3.EXIT                   ***";
                    cout << "\n\t\t\t**";
                    cout << "\n\t\t\t  CHOICE = ";
                    cin >> y;

                    if (y == 1) {
                        h1[0].regi();
                    } else if (y == 2) {
                        h1[0].log();
                    } else
                        cout << "\n\t\t\tTHANKS FOR COMING HERE ";
                    cout << "\n\t\t\tI HOPE THAT I CAN CLEAR ALL YOUR QUESTIONS";
                    cout << "\n\t\t\tDO YOU WANT TO CONTINUE (Y/N)? ";
                    cin >> v;
                } while (v == 'y' || v == 'Y');
                f1.close();
            }
            break;

        default:
            cout << "\n\t\t\tTHANK YOU \n\t\t\tYOU EXIT THE PROGRAM";
        }

        cout << "\n\t\t\tDO YOU WANT TO CONTINUE (Y/N)? ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
