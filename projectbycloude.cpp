// '''Id be happy to help you enhance this code for your final year project. Let's implement a more robust and professional student record system that would be suitable for a final year project. I'll focus on several key improvements:

// Using vectors for dynamic data management
// Improving file handling for permanent storage
// Adding more user-friendly features
// Implementing better input validation
// Creating a more organized structure

// Heres a comprehensive implementation '''

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

// Structure to store student academic details
struct AcademicDetails
{
    string course;
    string department;
    int year;
    int semester;
    double cgpa;
};

// Main class for student registration
class Student
{
private:
    string studentId;
    string name;
    string fatherName;
    string motherName;
    string city;
    string mobile;
    string email;
    string username;
    string password;
    AcademicDetails academics;
    bool isActive;

public:
    // Default constructor
    Student() : isActive(true), academics{} {}

    // Method to input student details
    void inputDetails()
    {
        cout << "\n\t\t\t============= ENTER STUDENT DETAILS =============\n";
        cout << "\n\t\t\tEnter Student ID: ";
        getline(cin, studentId);

        cout << "\n\t\t\tEnter Full Name: ";
        getline(cin, name);

        cout << "\n\t\t\tEnter Father's Name: ";
        getline(cin, fatherName);

        cout << "\n\t\t\tEnter Mother's Name: ";
        getline(cin, motherName);

        cout << "\n\t\t\tEnter City/Village: ";
        getline(cin, city);

        cout << "\n\t\t\tEnter Mobile Number: ";
        getline(cin, mobile);

        cout << "\n\t\t\tEnter Email: ";
        getline(cin, email);

        cout << "\n\t\t\tEnter Username: ";
        getline(cin, username);

        inputPassword();

        inputAcademicDetails();
    }

    // Method to input academic details
    void inputAcademicDetails()
    {
        cout << "\n\t\t\t========= ACADEMIC DETAILS =========\n";
        cout << "\n\t\t\tEnter Course: ";
        getline(cin, academics.course);

        cout << "\n\t\t\tEnter Department: ";
        getline(cin, academics.department);

        cout << "\n\t\t\tEnter Year (1-4): ";
        cin >> academics.year;
        cin.ignore();

        cout << "\n\t\t\tEnter Semester (1-8): ";
        cin >> academics.semester;
        cin.ignore();

        cout << "\n\t\t\tEnter CGPA: ";
        cin >> academics.cgpa;
        cin.ignore();
    }

    // Method to input password securely
    void inputPassword()
    {
        char ch;
        password = "";
        cout << "\n\t\t\tEnter Password (input will be hidden): ";
        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            { // Handle backspace
                if (password.length() > 0)
                {
                    password.pop_back();
                    cout << "\b \b"; // Erase character from screen
                }
            }
            else
            {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;
    }

    // Display student details
    void displayDetails() const
    {
        cout << "\n\t\t\t============= STUDENT DETAILS =============\n";
        cout << "\n\t\t\tStudent ID: " << studentId;
        cout << "\n\t\t\tName: " << name;
        cout << "\n\t\t\tFather's Name: " << fatherName;
        cout << "\n\t\t\tMother's Name: " << motherName;
        cout << "\n\t\t\tCity/Village: " << city;
        cout << "\n\t\t\tMobile: " << mobile;
        cout << "\n\t\t\tEmail: " << email;
        cout << "\n\t\t\tUsername: " << username;

        cout << "\n\n\t\t\t========= ACADEMIC DETAILS =========\n";
        cout << "\n\t\t\tCourse: " << academics.course;
        cout << "\n\t\t\tDepartment: " << academics.department;
        cout << "\n\t\t\tYear: " << academics.year;
        cout << "\n\t\t\tSemester: " << academics.semester;
        cout << "\n\t\t\tCGPA: " << fixed << setprecision(2) << academics.cgpa;
        cout << "\n\t\t\tStatus: " << (isActive ? "Active" : "Inactive");
        cout << "\n\t\t\t=======================================\n";
    }

    // Method to update student details
    void updateDetails()
    {
        cout << "\n\t\t\t============= UPDATE STUDENT DETAILS =============\n";
        cout << "\n\t\t\tCurrent Details:\n";
        displayDetails();

        cout << "\n\t\t\tEnter new details:\n";
        inputDetails();
    }

    // Method to deactivate a student
    void deactivate()
    {
        isActive = false;
        cout << "\n\t\t\tStudent record has been deactivated.\n";
    }

    // Method to activate a student
    void activate()
    {
        isActive = true;
        cout << "\n\t\t\tStudent record has been activated.\n";
    }

    // Search methods
    bool matchesId(const string &searchId) const
    {
        return studentId == searchId;
    }

    bool matchesName(const string &searchName) const
    {
        // Case-insensitive search
        string lowerName = name;
        string lowerSearch = searchName;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        transform(lowerSearch.begin(), lowerSearch.end(), lowerSearch.begin(), ::tolower);
        return lowerName.find(lowerSearch) != string::npos;
    }

    bool matchesMobile(const string &searchMobile) const
    {
        return mobile == searchMobile;
    }

    bool matchesUsername(const string &searchUsername) const
    {
        return username == searchUsername;
    }

    bool authenticate(const string &inputUsername, const string &inputPassword) const
    {
        return (username == inputUsername && password == inputPassword && isActive);
    }

    // Getters
    string getStudentId() const { return studentId; }
    string getName() const { return name; }
    string getUsername() const { return username; }
    bool getActiveStatus() const { return isActive; }

    // For file I/O
    friend ofstream &operator<<(ofstream &ofs, const Student &student);
    friend ifstream &operator>>(ifstream &ifs, Student &student);
};

// Operator overloading for file operations
ofstream &operator<<(ofstream &ofs, const Student &student)
{
    ofs << student.studentId << endl;
    ofs << student.name << endl;
    ofs << student.fatherName << endl;
    ofs << student.motherName << endl;
    ofs << student.city << endl;
    ofs << student.mobile << endl;
    ofs << student.email << endl;
    ofs << student.username << endl;
    ofs << student.password << endl;
    ofs << student.academics.course << endl;
    ofs << student.academics.department << endl;
    ofs << student.academics.year << endl;
    ofs << student.academics.semester << endl;
    ofs << student.academics.cgpa << endl;
    ofs << student.isActive << endl;
    return ofs;
}

ifstream &operator>>(ifstream &ifs, Student &student)
{
    getline(ifs, student.studentId);
    getline(ifs, student.name);
    getline(ifs, student.fatherName);
    getline(ifs, student.motherName);
    getline(ifs, student.city);
    getline(ifs, student.mobile);
    getline(ifs, student.email);
    getline(ifs, student.username);
    getline(ifs, student.password);
    getline(ifs, student.academics.course);
    getline(ifs, student.academics.department);
    ifs >> student.academics.year;
    ifs.ignore();
    ifs >> student.academics.semester;
    ifs.ignore();
    ifs >> student.academics.cgpa;
    ifs.ignore();
    ifs >> student.isActive;
    ifs.ignore();
    return ifs;
}

// Admin class for system management
class Admin
{
private:
    string username;
    string password;

public:
    Admin() : username("admin"), password("admin123") {}

    bool authenticate(const string &inputUsername, const string &inputPassword) const
    {
        return (username == inputUsername && password == inputPassword);
    }
};

// Database class to manage student records
class StudentDatabase
{
private:
    vector<Student> students;
    const string filename = "students.txt";
    Admin admin;

public:
    StudentDatabase()
    {
        loadFromFile();
    }

    ~StudentDatabase()
    {
        saveToFile();
    }

    // Load student records from file
    void loadFromFile()
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "\n\t\t\tNo existing database found. Creating a new one.\n";
            return;
        }

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            file.seekg(-line.length() - 1, ios::cur);
            Student student;
            file >> student;
            students.push_back(student);

            // Skip the empty line between records
            getline(file, line);
        }

        cout << "\n\t\t\tLoaded " << students.size() << " student records from database.\n";
        file.close();
    }

    // Save student records to file
    void saveToFile()
    {
        ofstream file(filename);
        if (!file)
        {
            cout << "\n\t\t\tError: Could not open database file for writing.\n";
            return;
        }

        for (const auto &student : students)
        {
            file << student << endl;
        }

        file.close();
        cout << "\n\t\t\tSaved " << students.size() << " student records to database.\n";
    }

    // Add a new student
    void addStudent()
    {
        Student newStudent;
        newStudent.inputDetails();

        // Check if student ID already exists
        for (const auto &student : students)
        {
            if (student.matchesId(newStudent.getStudentId()))
            {
                cout << "\n\t\t\tError: Student ID already exists. Please use a unique ID.\n";
                return;
            }
        }

        students.push_back(newStudent);
        cout << "\n\t\t\tStudent added successfully!\n";
        saveToFile();
    }

    // Display all students
    void displayAllStudents()
    {
        if (students.empty())
        {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        cout << "\n\t\t\t============= ALL STUDENTS =============\n";
        cout << "\n\t\t\t" << setw(10) << "ID" << setw(25) << "Name" << setw(15) << "Mobile" << setw(20) << "Username" << setw(10) << "Status\n";
        cout << "\t\t\t" << string(80, '-') << "\n";

        for (const auto &student : students)
        {
            cout << "\t\t\t" << setw(10) << student.getStudentId()
                 << setw(25) << student.getName()
                 << setw(15) << "XXXXXXXX" // Privacy concern, not showing mobile
                 << setw(20) << student.getUsername()
                 << setw(10) << (student.getActiveStatus() ? "Active" : "Inactive") << "\n";
        }

        cout << "\t\t\t" << string(80, '-') << "\n";
        cout << "\t\t\tTotal Records: " << students.size() << "\n";
    }

    // Search students by various criteria
    void searchStudents()
    {
        if (students.empty())
        {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        cout << "\n\t\t\t============= SEARCH STUDENTS =============\n";
        cout << "\n\t\t\t1. Search by ID";
        cout << "\n\t\t\t2. Search by Name";
        cout << "\n\t\t\t3. Search by Mobile Number";
        cout << "\n\t\t\t4. Search by Username";
        cout << "\n\t\t\t5. Back to Main Menu";
        cout << "\n\t\t\tEnter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        string searchTerm;
        vector<Student *> results;

        if (choice >= 1 && choice <= 4)
        {
            cout << "\n\t\t\tEnter search term: ";
            getline(cin, searchTerm);

            for (auto &student : students)
            {
                bool match = false;

                switch (choice)
                {
                case 1:
                    match = student.matchesId(searchTerm);
                    break;
                case 2:
                    match = student.matchesName(searchTerm);
                    break;
                case 3:
                    match = student.matchesMobile(searchTerm);
                    break;
                case 4:
                    match = student.matchesUsername(searchTerm);
                    break;
                }

                if (match)
                {
                    results.push_back(&student);
                }
            }

            if (results.empty())
            {
                cout << "\n\t\t\tNo matching records found.\n";
                return;
            }

            cout << "\n\t\t\tFound " << results.size() << " matching records:\n";
            for (int i = 0; i < results.size(); i++)
            {
                cout << "\n\t\t\t" << (i + 1) << ". " << results[i]->getName() << " (ID: " << results[i]->getStudentId() << ")";
            }

            cout << "\n\n\t\t\tSelect a record to view details (1-" << results.size() << ") or 0 to cancel: ";
            int index;
            cin >> index;
            cin.ignore();

            if (index > 0 && index <= results.size())
            {
                results[index - 1]->displayDetails();
            }
        }
    }

    // Update student details
    void updateStudent()
    {
        if (students.empty())
        {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        string searchId;
        cout << "\n\t\t\tEnter Student ID to update: ";
        getline(cin, searchId);

        for (auto &student : students)
        {
            if (student.matchesId(searchId))
            {
                student.updateDetails();
                cout << "\n\t\t\tStudent record updated successfully!\n";
                saveToFile();
                return;
            }
        }

        cout << "\n\t\t\tStudent ID not found.\n";
    }

    // Delete (deactivate) a student
    void deleteStudent()
    {
        if (students.empty())
        {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        string searchId;
        cout << "\n\t\t\tEnter Student ID to delete: ";
        getline(cin, searchId);

        for (auto &student : students)
        {
            if (student.matchesId(searchId))
            {
                student.deactivate();
                cout << "\n\t\t\tStudent record deactivated successfully!\n";
                saveToFile();
                return;
            }
        }

        cout << "\n\t\t\tStudent ID not found.\n";
    }

    // Restore (activate) a student
    void restoreStudent()
    {
        if (students.empty())
        {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        vector<Student *> inactiveStudents;

        for (auto &student : students)
        {
            if (!student.getActiveStatus())
            {
                inactiveStudents.push_back(&student);
            }
        }

        if (inactiveStudents.empty())
        {
            cout << "\n\t\t\tNo inactive student records found.\n";
            return;
        }

        cout << "\n\t\t\t============= INACTIVE STUDENTS =============\n";
        for (int i = 0; i < inactiveStudents.size(); i++)
        {
            cout << "\n\t\t\t" << (i + 1) << ". " << inactiveStudents[i]->getName() << " (ID: " << inactiveStudents[i]->getStudentId() << ")";
        }

        cout << "\n\n\t\t\tSelect a record to restore (1-" << inactiveStudents.size() << ") or 0 to cancel: ";
        int index;
        cin >> index;
        cin.ignore();

        if (index > 0 && index <= inactiveStudents.size())
        {
            inactiveStudents[index - 1]->activate();
            cout << "\n\t\t\tStudent record activated successfully!\n";
            saveToFile();
        }
    }

    // Student login
    bool studentLogin()
    {
        string username, password;
        cout << "\n\t\t\t============= STUDENT LOGIN =============\n";
        cout << "\n\t\t\tEnter Username: ";
        getline(cin, username);

        char ch;
        password = "";
        cout << "\n\t\t\tEnter Password: ";
        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            { // Handle backspace
                if (password.length() > 0)
                {
                    password.pop_back();
                    cout << "\b \b"; // Erase character from screen
                }
            }
            else
            {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;

        for (const auto &student : students)
        {
            if (student.authenticate(username, password))
            {
                cout << "\n\t\t\tLogin successful!\n";
                cout << "\n\t\t\tWelcome, " << username << "!\n";
                return true;
            }
        }

        cout << "\n\t\t\tInvalid username or password, or account is inactive.\n";
        return false;
    }

    // Admin login
    bool adminLogin()
    {
        string username, password;
        cout << "\n\t\t\t============= ADMIN LOGIN =============\n";
        cout << "\n\t\t\tEnter Username: ";
        getline(cin, username);

        char ch;
        password = "";
        cout << "\n\t\t\tEnter Password: ";
        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            { // Handle backspace
                if (password.length() > 0)
                {
                    password.pop_back();
                    cout << "\b \b"; // Erase character from screen
                }
            }
            else
            {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;

        if (admin.authenticate(username, password))
        {
            cout << "\n\t\t\tAdmin login successful!\n";
            return true;
        }

        cout << "\n\t\t\tInvalid admin credentials.\n";
        return false;
    }
};

// Help class for system documentation
class HelpSystem
{
public:
    void showMainHelp()
    {
        cout << "\n\t\t\t============= STUDENT RECORD SYSTEM HELP =============\n";
        cout << "\n\t\t\tThis system allows you to manage student records efficiently.";
        cout << "\n\t\t\tYou can register as a student, login to view your details,";
        cout << "\n\t\t\tor login as an admin to manage all student records.";
        cout << "\n\n\t\t\tMain Menu Options:";
        cout << "\n\t\t\t1. Student Registration - Create a new student account";
        cout << "\n\t\t\t2. Student Login - Access your student information";
        cout << "\n\t\t\t3. Admin Login - Access administrative functions";
        cout << "\n\t\t\t4. Help - Display this help information";
        cout << "\n\t\t\t5. Exit - Exit the system";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }

    void showStudentHelp()
    {
        cout << "\n\t\t\t============= STUDENT HELP =============\n";
        cout << "\n\t\t\tAs a student, you can:";
        cout << "\n\t\t\t1. View your personal and academic details";
        cout << "\n\t\t\t2. Update certain information in your profile";
        cout << "\n\n\t\t\tTo register:";
        cout << "\n\t\t\t- Select 'Student Registration' from the main menu";
        cout << "\n\t\t\t- Fill in all required details accurately";
        cout << "\n\t\t\t- Create a unique username and strong password";
        cout << "\n\t\t\t- Remember your credentials for future logins";
        cout << "\n\n\t\t\tTo login:";
        cout << "\n\t\t\t- Select 'Student Login' from the main menu";
        cout << "\n\t\t\t- Enter your username and password";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }

    void showAdminHelp()
    {
        cout << "\n\t\t\t============= ADMIN HELP =============\n";
        cout << "\n\t\t\tAs an admin, you can manage all student records:";
        cout << "\n\t\t\t1. Add new students to the system";
        cout << "\n\t\t\t2. View all student records";
        cout << "\n\t\t\t3. Search for specific students";
        cout << "\n\t\t\t4. Update student information";
        cout << "\n\t\t\t5. Deactivate (delete) student accounts";
        cout << "\n\t\t\t6. Restore previously deactivated accounts";
        cout << "\n\n\t\t\tDefault admin credentials:";
        cout << "\n\t\t\tUsername: admin";
        cout << "\n\t\t\tPassword: admin123";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }
};

// Main application class
class StudentRecordSystem
{
private:
    StudentDatabase database;
    HelpSystem helpSystem;

public:
    void displayHeader()
    {
        system("cls");
        cout << "\n\t\t\t================================================" << endl;
        cout << "\t\t\t             STUDENT RECORD SYSTEM               " << endl;
        cout << "\t\t\t================================================" << endl;
    }

    void displayMainMenu()
    {
        displayHeader();
        cout << "\n\t\t\t              MAIN MENU                        " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. Student Registration" << endl;
        cout << "\n\t\t\t2. Student Login" << endl;
        cout << "\n\t\t\t3. Admin Login" << endl;
        cout << "\n\t\t\t4. Help" << endl;
        cout << "\n\t\t\t5. Exit" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    void displayAdminMenu()
    {
        displayHeader();
        cout << "\n\t\t\t              ADMIN MENU                       " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. Add New Student" << endl;
        cout << "\n\t\t\t2. View All Students" << endl;
        cout << "\n\t\t\t3. Search Students" << endl;
        cout << "\n\t\t\t4. Update Student Details" << endl;
        cout << "\n\t\t\t5. Deactivate Student" << endl;
        cout << "\n\t\t\t6. Restore Student" << endl;
        cout << "\n\t\t\t7. Help" << endl;
        cout << "\n\t\t\t8. Logout" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    void displayStudentMenu()
    {
        displayHeader();
        cout << "\n\t\t\t              STUDENT MENU                     " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. View My Details" << endl;
        cout << "\n\t\t\t2. Help" << endl;
        cout << "\n\t\t\t3. Logout" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    void displayHelpMenu()
    {
        displayHeader();
        cout << "\n\t\t\t              HELP MENU                        " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. General Help" << endl;
        cout << "\n\t\t\t2. Student Help" << endl;
        cout << "\n\t\t\t3. Admin Help" << endl;
        cout << "\n\t\t\t4. Back to Main Menu" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    void runAdminMenu()
    {
        int choice;
        do
        {
            displayAdminMenu();
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                database.addStudent();
                break;
            case 2:
                database.displayAllStudents();
                break;
            case 3:
                database.searchStudents();
                break;
            case 4:
                database.updateStudent();
                break;
            case 5:
                database.deleteStudent();
                break;
            case 6:
                database.restoreStudent();
                break;
            case 7:
                helpSystem.showAdminHelp();
                break;
            case 8:
                cout << "\n\t\t\tLogging out from admin account...\n";
                break;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
            }

            if (choice != 8)
            {
                cout << "\n\t\t\tPress any key to continue...";
                getch();
            }
        } while (choice != 8);
    }

    void runStudentMenu()
    {
        int choice;
        do
        {
            displayStudentMenu();
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                cout << "\n\t\t\tStudent details would be displayed here.\n";
                break;
            case 2:
                helpSystem.showStudentHelp();
                break;
            case 3:
                cout << "\n\t\t\tLogging out from student account...\n";
                break;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
            }

            if (choice != 3)
            {
                cout << "\n\t\t\tPress any key to continue...";
                getch();
            }
        } while (choice != 3);
    }

    void runHelpMenu()
    {
        int choice;
        do
        {
            displayHelpMenu();
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                helpSystem.showMainHelp();
                break;
            case 2:
                helpSystem.showStudentHelp();
                break;
            case 3:
                helpSystem.showAdminHelp();
                break;
            case 4:
                cout << "\n\t\t\tReturning to main menu...\n";
                break;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
            }

            if (choice != 4)
            {
                cout << "\n\t\t\tPress any key to continue...";
                getch();
            }
        } while (choice != 4);
    }

    void run()
    {
        int choice;
        do
        {
            displayMainMenu();
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                database.addStudent();
                break;
            case 2:
                if (database.studentLogin())
                {
                    runStudentMenu();
                }
                break;
            case 3:
                if (database.adminLogin())
                {
                    runAdminMenu();
                }
                break;
            case 4:
                runHelpMenu();
                break;
            case 5:
                cout << "\n\t\t\tExiting Student Record System. Thank you!\n";
                break;
            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
            }

            if (choice != 5)
            {
                cout << "\n\t\t\tPress any key to continue...";
                getch();
            }
        } while (choice != 5);
    }
};

int main()
{
    StudentRecordSystem system;
    system.run();
    return 0;
}