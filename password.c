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