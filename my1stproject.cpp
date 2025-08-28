
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
class registration
{
    string name, fname, mname, vname, uname, pass, mno;

public:
    void getdata()
    {
        cout<<"\n\t\t\tenter your name : ";
        getline(cin,name);
        cout << "\n\t\t\tenter your father name = ";
        getline(cin, fname);
        cout << "\n\t\t\tenter your mother name = ";
        getline(cin, mname);
        cout << "\n\t\t\tenter your village/city name = ";
        getline(cin, vname);
        cout << "\n\t\t\tenter your mobile no. = ";
        getline(cin, mno);
        cout << "\n\t\t\tenter your username = ";
        getline(cin, uname);
    }
    void getPassword()
    {
        char ch;
        pass = "";
        cout << "\n\t\t\tEnter Password: ";
        while ((ch = getch()) != '\r')
        {
            pass += ch;
            cout << '*'; // Masking password input
        }
        cout << endl;
    }

    void putdata()
    {
        cout << "\n\t\t\tyour name = " << name << endl;
        cout << "\n\t\t\tfather name = " << fname << endl;
        cout << "\n\t\t\tmother name = " << mname << endl;
        cout << "\n\t\t\tvillage/city name = " << vname << endl;
        cout << "\n\t\t\tmobile no. = " << mno << endl;
        cout << "\n\t\t\tusername name = " << uname << endl;
        cout << "\n\t\t\tpasword = " << pass << endl;
    }

    void del()
    {
        cout << "\n\t\t\tALL DATA DELETED";
    }

    void ser()
    {
        string d;
        cout << "\t\t\tYOU CAN ONLY SEARCH MOBILE NO. OR PASSWORD";
        cout << "\n\t\t\tENTER THE SEARCHING ELEMENT = ";
        cin >> d;
        if (d == mno || d == pass)
        {
            cout << "\n\t\t\t---element is found---";
        }
        else
        {
            cout << "\n\t\t\t---element is not found---";
        }
    }
};
class login
{
    string sname;
    string password;

public:
    void getdata()
    {
        cout << "\n\t\t\tenter your user name = ";
        getline(cin, sname);
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

    void putdata()
    {
        cout << "\n\t\t\tname = " << sname;
        cout << "\n\t\t\tpassword = " << password;
    }

    bool search(string query)
    {
        if (query == password || query == sname)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void del()
    {
        cout << "\n\t\t\tALL DATA DELETED";
    }
};
class help
{
public:
    void regi()
    {
        cout << "\n\t\t\t**YOU HERE FOR TROUBLE IN REGISTRAION** \n";
        ;
        cout << "\n\t\t\t       it is very simple process";
        cout << "\n\t\t\t    you insert your personal details";
        cout << "\n\t\t\t     you face with this interface\n";
        cout << "\n\t\t\t  ! enter your name = ";
        cout << "\n\t\t\t  ! enter your father name = ";
        cout << "\n\t\t\t  ! enter your father name = ";
        cout << "\n\t\t\t  ! enter your mother name = ";
        cout << "\n\t\t\t  ! enter your village/city name = ";
        cout << "\n\t\t\t  ! enter your mobile no. = ";
        cout << "\n\t\t\t  ! nenter your username = ";
        cout << "\n\t\t\t  ! enter a strong password = \n";
        cout << "\n\t\t\t   **AFTER INSERTING THE DETAILS";
        cout << "\n\t\t\t---congrats you complete your registration---";
    }
    void log()
    {
        cout << "\n\t\t\t**YOU HERE FOR TROUBLE IN LOGIN** \n";
        ;
        cout << "\n\t\t\t       it is very simple process";
        cout << "\n\t\t\t    you insert your personal details";
        cout << "\n\t\t\t     you face with this interface\n";
        cout << "\n\t\t\t  ! nenter your username = ";
        cout << "\n\t\t\t  ! enter a strong password = \n";
        cout << "\n\t\t\t   **AFTER INSERTING THE DETAILS";
        cout << "\n\t\t\t---congrats you complete your login---";
    }
};
int main()
{
    fstream f1;
    registration r1[1];
    login l1[1], l2;
    help h1[1];
    int x;
    char ans;
    do
    {
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
        switch (x)
        {

            {
            case 1:
                char s;

                do
                {

                    f1.open("res.txt", ios::out);
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
                    cin.ignore();

                    if (a == 1)
                    {
                        cout << "\n\t\t\tINSERT YOUR DATA\n";
                        for (int i = 0; i < 1; i++)
                        {
                            r1[i].getdata();
                            r1[i].getPassword();
                            f1.write((char *)&r1[i], sizeof(r1[i]));
                        }
                    }

                    else if (a == 2)
                    {
                        for (int k = 0; k < 1; k++)
                        {
                            f1.read((char *)&r1[k], sizeof(r1[k]));
                            r1[k].putdata();
                        }
                    }

                    else if (a == 3)
                    {
                        cout << "\n\t\t\tINSERT YOUR DATA\n";
                        for (int i = 0; i < 1; i++)
                        {
                            cout << "\n\t\t\tprevious data : \n";
                            f1.read((char *)&r1[i], sizeof(r1[i]));
                            r1[i].putdata();
                            cout << "\n\t\t\tknow update your data : \n";
                            r1[i].getdata();
                            r1[i].getPassword();
                            f1.write((char *)&r1[i], sizeof(r1[i]));
                        }
                    }

                    else if (a == 4)
                    {
                        for (int i = 0; i < 1; i++)
                        {
                            r1[i].ser();
                            f1.write((char *)&r1[i], sizeof(r1[i]));
                        }
                    }

                    else if (a == 5)
                    {
                        for (int i = 0; i < 1; i++)
                        {
                            r1[i].del();
                            f1.write((char *)&r1[i], sizeof(r1[i]));
                        }
                    }

                    else
                        cout << "\n\t\t\tTHANK U \n\t\t\tYOU EXIT THIS PAGE";
                    cout << "\n\t\t\tDO U WANT TO CONTINUE REGISTRESTION(Y/N) = ";
                    cin >> s;
                } while (s == 'y' || s == 'Y');
            }

            f1.close();
            break;

        case 2:
        {
            char f;

            f1.open("lod.txt", ios::out);
            int b;
            do
            {
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

                if (b == 1)
                {

                    cout << "\n\t\t\tINSERT YOUR DATA";
                    for (int i = 0; i < 1; i++)
                    {
                        l1[i].getdata();
                        f1.write((char *)&l1[i], sizeof(l1[i]));
                    }
                }

                else if (b == 2)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        f1.read((char *)&l1[i], sizeof(l1[i]));
                        l1[i].putdata();
                    }
                }

                else if (b == 3)
                {
                    cout << "\n\t\t\tINSERT YOUR DATA ";
                    for (int i = 0; i < 1; i++)
                    {
                        l1[i].getdata();
                        f1.write((char *)&l1[i], sizeof(l1[i]));
                    }
                }

                else if (b == 4)
                {

                    string query;

                   
                    cout << "\n\t\t\tENTER THE SEARCHING ELEMENT = ";
                    getline(cin, query);
                    for (int i = 0; i < 1; i++)
                    {
                       bool r = l1[i].search(query);
                        f1.read((char *)&l1[i], sizeof(l1[i]));
                         if(r == true){
                            cout<<"founded!";
                        }
                        else{
                            cout<<"not found!";
                        }
                        
                    }
                   
                }

                else if (b == 5)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        l1[i].del();
                        f1.read((char *)&l1[i], sizeof(l1[i]));
                    }
                }

                else

                    cout << "\n\t\t\tTHANK U \n\t\t\tYOU EXIT THIS PAGE";
                cout << "\n\t\t\tDO U WANT TO CONTINUE LOGIN PAGE(Y/N) = ";
                cin >> f;
            } while (f == 'y' || f == 'Y');
        }
            f1.close();
            break;

        case 3:
        {
            char v;

            f1.open("help.txt", ios::out);

            int y;

            do
            {
                cout << "\n\t\t\t**";
                cout << "\n\t\t\t***       WELCOME TO HELP PAGE         ***";
                cout << "\n\t\t\t***  IN WHICH CASE DO YOU NEED HELP?   ***";
                cout << "\n\t\t\t***           1.REGISTRATION           ***";
                cout << "\n\t\t\t***                                    ***";
                cout << "\n\t\t\t***           2.LOGIN                  ***";
                cout << "\n\t\t\t***                                    ***";
                cout << "\n\t\t\t***           3.EXIT                   ***";
                cout << "\n\t\t\t**";
                cout << "\n\t\t\t  CHOICE = ";
                cin >> y;
                if (y == 1)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        h1[i].regi();
                        f1.read((char *)&h1[i], sizeof(h1[i]));
                    }
                }
                else if (y == 2)
                {
                    for (int i = 0; i < 1; i++)
                    {
                        h1[i].log();
                        f1.read((char *)&h1[i], sizeof(h1[i]));
                    }
                }
                else
                    cout << "\n\t\t\tTHANKS FOR COME HERE ";
                cout << "\n\t\t\tI HOPE THAT I CAN CLEAR ALL YOUR QUIRIES";
                cout << "\n\t\t\tDO U WANT HELP AGAIN(Y/N)  = ";
                cin >> v;
            } while (v == 'y' || v == 'Y');
        }
            f1.close();
            break;

        default:
            cout << "\n\t\t\tTHANK U \n\t\t\tYOU EXIT THE PROGRAM";
        }

        cout << "\n\t\t\tDO U WANT TO CONT THAT PROJECT(Y/N) = ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}
