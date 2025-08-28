#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h> // For password input
#include <iomanip>
#include <algorithm> // For lowercase conversion
using namespace std;

// Student data structure
struct StudentData {
    string id;
    string name;
    string fatherName;
    string motherName;
    string address;
    string phone;
    string email;
    string username;
    string password;
    string course;
    string department;
    int year;
    int semester;
    float gpa;
    bool active;
};

// Main student class
class Student {
private:
    StudentData data;

public:
    // Create new student
    void create() {
        cout << "\n--- Enter Student Details ---\n";
        
        cout << "ID: ";
        getline(cin, data.id);
        
        cout << "Full Name: ";
        getline(cin, data.name);
        
        cout << "Father's Name: ";
        getline(cin, data.fatherName);
        
        cout << "Mother's Name: ";
        getline(cin, data.motherName);
        
        cout << "Address: ";
        getline(cin, data.address);
        
        cout << "Phone: ";
        getline(cin, data.phone);
        
        cout << "Email: ";
        getline(cin, data.email);
        
        cout << "Username: ";
        getline(cin, data.username);
        
        setPassword();
        
        cout << "\n--- Academic Details ---\n";
        cout << "Course: ";
        getline(cin, data.course);
        
        cout << "Department: ";
        getline(cin, data.department);
        
        cout << "Year (1-4): ";
        cin >> data.year;
        cin.ignore();
        
        cout << "Semester (1-8): ";
        cin >> data.semester;
        cin.ignore();
        
        cout << "GPA: ";
        cin >> data.gpa;
        cin.ignore();
        
        data.active = true;
    }

    // Set password with hidden input
    void setPassword() {
        char ch;
        data.password = "";
        cout << "Password: ";
        
        while ((ch = _getch()) != 13) { // 13 is Enter key
            if (ch == 8) { // Backspace
                if (!data.password.empty()) {
                    data.password.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                data.password += ch;
                cout << '*';
            }
        }
        cout << endl;
    }

    // Show student info
    void show() {
        cout << "\n--- Student Information ---\n";
        cout << "ID: " << data.id << endl;
        cout << "Name: " << data.name << endl;
        cout << "Father: " << data.fatherName << endl;
        cout << "Mother: " << data.motherName << endl;
        cout << "Address: " << data.address << endl;
        cout << "Phone: " << data.phone << endl;
        cout << "Email: " << data.email << endl;
        cout << "Username: " << data.username << endl;
        
        cout << "\nAcademic Details:\n";
        cout << "Course: " << data.course << endl;
        cout << "Department: " << data.department << endl;
        cout << "Year: " << data.year << endl;
        cout << "Semester: " << data.semester << endl;
        cout << "GPA: " << fixed << setprecision(2) << data.gpa << endl;
        cout << "Status: " << (data.active ? "Active" : "Inactive") << endl;
    }

    // Check if student matches search term
    bool match(string search, int type) {
        string compare;
        switch (type) {
            case 1: compare = data.id; break;          // Search by ID
            case 2: compare = data.name; break;        // Search by name
            case 3: compare = data.phone; break;        // Search by phone
            case 4: compare = data.username; break;     // Search by username
        }
        
        // Convert to lowercase for case-insensitive search
        transform(compare.begin(), compare.end(), compare.begin(), ::tolower);
        transform(search.begin(), search.end(), search.begin(), ::tolower);
        
        return compare.find(search) != string::npos;
    }

    // Login check
    bool login(string user, string pass) {
        return (data.username == user && data.password == pass && data.active);
    }

    // Getters
    string getID() { return data.id; }
    string getName() { return data.name; }
    string getUsername() { return data.username; }
    bool isActive() { return data.active; }
    
    // Activate/deactivate
    void deactivate() { data.active = false; }
    void activate() { data.active = true; }
};

// Database class to manage students
class Database {
private:
    vector<Student> students;
    string filename = "students.dat";
    string adminUser = "admin";
    string adminPass = "admin123";

public:
    // Load data from file
    void load() {
        ifstream file(filename);
        if (!file) return;

        while (!file.eof()) {
            Student s;
            StudentData d;
            
            getline(file, d.id);
            if (d.id.empty()) continue;
            
            getline(file, d.name);
            getline(file, d.fatherName);
            getline(file, d.motherName);
            getline(file, d.address);
            getline(file, d.phone);
            getline(file, d.email);
            getline(file, d.username);
            getline(file, d.password);
            getline(file, d.course);
            getline(file, d.department);
            file >> d.year >> d.semester >> d.gpa >> d.active;
            file.ignore();
            
            s = Student(); // Create new student
            s.create();   // This needs adjustment - better to add a constructor
            students.push_back(s);
        }
        file.close();
    }

    // Save data to file
    void save() {
        ofstream file(filename);
        for (auto &s : students) {
            // Need to implement getData() in Student class
            // file << s.getData().id << endl;
            // ... etc ...
        }
        file.close();
    }

    // Add new student
    void add() {
        Student s;
        s.create();
        students.push_back(s);
        save();
        cout << "Student added successfully!\n";
    }

    // Show all students
    void showAll() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }

        cout << "\nID\tName\t\tUsername\tStatus\n";
        cout << "----------------------------------------\n";
        for (auto &s : students) {
            cout << s.getID() << "\t" 
                 << s.getName() << "\t"
                 << s.getUsername() << "\t"
                 << (s.isActive() ? "Active" : "Inactive") << endl;
        }
    }

    // Search students
    void search() {
        cout << "\nSearch by:\n1. ID\n2. Name\n3. Phone\n4. Username\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        cout << "Enter search term: ";
        string term;
        getline(cin, term);

        vector<Student*> results;
        for (auto &s : students) {
            if (s.match(term, choice)) {
                results.push_back(&s);
            }
        }

        if (results.empty()) {
            cout << "No matches found.\n";
            return;
        }

        cout << "\nFound " << results.size() << " matches:\n";
        for (size_t i = 0; i < results.size(); i++) {
            cout << i+1 << ". " << results[i]->getName() << " (" << results[i]->getID() << ")\n";
        }

        cout << "Enter number to view details (0 to cancel): ";
        int pick;
        cin >> pick;
        cin.ignore();

        if (pick > 0 && pick <= results.size()) 
        {
            results[pick-1]->show();
        }
    }

    // Admin login
    bool adminLogin() {
        cout << "Admin Username: ";
        string user;
        getline(cin, user);
        
        cout << "Password: ";
        string pass;
        char ch;
        while ((ch = _getch()) != 13) {
            if (ch == 8) {
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                pass += ch;
                cout << '*';
            }
        }
        cout << endl;

        return (user == adminUser && pass == adminPass);
    }

    // Student login
    bool studentLogin() {
        cout << "Username: ";
        string user;
        getline(cin, user);
        
        cout << "Password: ";
        string pass;
        char ch;
        while ((ch = _getch()) != 13) {
            if (ch == 8) {
                if (!pass.empty()) {
                    pass.pop_back();
                    cout << "\b \b";
                }
            }
            else {
                pass += ch;
                cout << '*';
            }
        }
        cout << endl;

        for (auto &s : students) {
            if (s.login(user, pass)) {
                cout << "Login successful!\n";
                s.show();
                return true;
            }
        }
        
        cout << "Invalid login.\n";
        return false;
    }
};

// Main menu system
class Menu {
private:
    Database db;

public:
    void mainMenu() {
        db.load();
        
        while (true) {
            system("cls");
            cout << "\nSTUDENT MANAGEMENT SYSTEM\n";
            cout << "1. Student Registration\n";
            cout << "2. Student Login\n";
            cout << "3. Admin Login\n";
            cout << "4. Exit\n";
            cout << "Choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1: db.add(); break;
                case 2: db.studentLogin(); break;
                case 3: 
                    if (db.adminLogin()) adminMenu(); 
                    break;
                case 4: 
                    db.save();
                    cout << "Goodbye!\n";
                    return;
                default: 
                    cout << "Invalid choice.\n";
            }
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }

    void adminMenu() {
        while (true) {
            system("cls");
            cout << "\nADMIN MENU\n";
            cout << "1. Add Student\n";
            cout << "2. View All Students\n";
            cout << "3. Search Students\n";
            cout << "4. Logout\n";
            cout << "Choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore();
            
            switch (choice) {
                case 1: db.add(); break;
                case 2: db.showAll(); break;
                case 3: db.search(); break;
                case 4: return;
                default: cout << "Invalid choice.\n";
            }
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
};

int main() {
    Menu menu;
    menu.mainMenu();
    return 0;
}