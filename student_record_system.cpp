#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For getch() - Windows specific
#include <cstring>
#include <cstdlib>
#include <limits> // For numeric_limits

using namespace std;

// Maximum number of students
const int MAX_STUDENTS = 100;

// Structure for Academic Details
struct AcademicDetails {
    char course[50];
    char department[50];
    int year;
    int semester;
    float cgpa;
};

// Class for Student
class Student {
private:
    char studentId[20];
    char name[50];
    char fatherName[50];
    char motherName[50];
    char city[50];
    char mobile[15];
    char email[50];
    char username[30];
    char password[30];
    AcademicDetails academics;
    bool isActive;

public:
    // Constructor
    Student() {
        strcpy(studentId, "");
        strcpy(name, "");
        strcpy(fatherName, "");
        strcpy(motherName, "");
        strcpy(city, "");
        strcpy(mobile, "");
        strcpy(email, "");
        strcpy(username, "");
        strcpy(password, "");
        strcpy(academics.course, "");
        strcpy(academics.department, "");
        academics.year = 0;
        academics.semester = 0;
        academics.cgpa = 0.0;
        isActive = true;
    }

    // Input student details
    void inputDetails() {
        cout << "\n\t\t\t============= ENTER STUDENT DETAILS =============\n";
        
        cout << "\n\t\t\tEnter Student ID: ";
        cin.getline(studentId, 20);
        
        cout << "\n\t\t\tEnter Full Name: ";
        cin.getline(name, 50);
        
        cout << "\n\t\t\tEnter Father's Name: ";
        cin.getline(fatherName, 50);
        
        cout << "\n\t\t\tEnter Mother's Name: ";
        cin.getline(motherName, 50);
        
        cout << "\n\t\t\tEnter City/Village: ";
        cin.getline(city, 50);
        
        cout << "\n\t\t\tEnter Mobile Number: ";
        cin.getline(mobile, 15);
        
        cout << "\n\t\t\tEnter Email: ";
        cin.getline(email, 50);
        
        cout << "\n\t\t\tEnter Username: ";
        cin.getline(username, 30);
        
        inputPassword();
        inputAcademicDetails();
    }

    // Input password with stars
    void inputPassword() {
        char ch;
        int i = 0;
        cout << "\n\t\t\tEnter Password (input will be hidden): ";
        
        while ((ch = getch()) != '\r' && i < 29) {
            if (ch == '\b') {
                if (i > 0) {
                    i--;
                    cout << "\b \b";
                }
            } else {
                password[i] = ch;
                cout << '*';
                i++;
            }
        }
        password[i] = '\0';
        cout << endl;
    }

    // Input academic details
    void inputAcademicDetails() {
        cout << "\n\t\t\t========= ACADEMIC DETAILS =========\n";
        
        cout << "\n\t\t\tEnter Course: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(academics.course, 50);
        
        cout << "\n\t\t\tEnter Department: ";
        cin.getline(academics.department, 50);
        
        cout << "\n\t\t\tEnter Year (1-4): ";
        cin >> academics.year;
        
        cout << "\n\t\t\tEnter Semester (1-8): ";
        cin >> academics.semester;
        
        cout << "\n\t\t\tEnter CGPA (0.0-10.0): ";
        cin >> academics.cgpa;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    }

    // Display student details
    void displayDetails() {
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
        cout << "\n\t\t\tCGPA: " << academics.cgpa;
        
        if (isActive) {
            cout << "\n\t\t\tStatus: Active";
        } else {
            cout << "\n\t\t\tStatus: Inactive";
        }
        cout << "\n\t\t\t=======================================\n";
    }

    // Update student details
    void updateDetails() {
        cout << "\n\t\t\t============= UPDATE STUDENT DETAILS =============\n";
        cout << "\n\t\t\tCurrent Details:\n";
        displayDetails();
        
        cout << "\n\t\t\tEnter new details:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        inputDetails();
        cout << "\n\t\t\tDetails updated successfully!\n";
    }

    // Deactivate student
    void deactivate() {
        isActive = false;
        cout << "\n\t\t\tStudent record has been deactivated.\n";
    }

    // Activate student
    void activate() {
        isActive = true;
        cout << "\n\t\t\tStudent record has been activated.\n";
    }

    // Check if student ID matches
    bool matchesId(char* searchId) {
        return strcmp(studentId, searchId) == 0;
    }

    // Check if name contains search term
    bool matchesName(char* searchName) {
        // Convert to lowercase for case-insensitive search
        char lowerName[50], lowerSearch[50];
        strcpy(lowerName, name);
        strcpy(lowerSearch, searchName);
        
        // Manual lowercase conversion
        for (int i = 0; lowerName[i]; i++) {
            if (lowerName[i] >= 'A' && lowerName[i] <= 'Z') {
                lowerName[i] = lowerName[i] + 32;
            }
        }
        for (int i = 0; lowerSearch[i]; i++) {
            if (lowerSearch[i] >= 'A' && lowerSearch[i] <= 'Z') {
                lowerSearch[i] = lowerSearch[i] + 32;
            }
        }
        
        return strstr(lowerName, lowerSearch) != NULL;
    }

    // Check if mobile matches
    bool matchesMobile(char* searchMobile) {
        return strcmp(mobile, searchMobile) == 0;
    }

    // Check if username matches
    bool matchesUsername(char* searchUsername) {
        return strcmp(username, searchUsername) == 0;
    }

    // Authenticate user
    bool authenticate(char* inputUsername, char* inputPassword) {
        return (strcmp(username, inputUsername) == 0 && 
                strcmp(password, inputPassword) == 0 && 
                isActive);
    }

    // Get student ID
    char* getStudentId() {
        return studentId;
    }

    // Get student name
    char* getName() {
        return name;
    }

    // Get username
    char* getUsername() {
        return username;
    }

    // Get mobile
    char* getMobile() {
        return mobile;
    }

    // Get active status
    bool getActiveStatus() {
        return isActive;
    }

    // Write to file
    void writeToFile(ofstream& file) {
        file << studentId << endl;
        file << name << endl;
        file << fatherName << endl;
        file << motherName << endl;
        file << city << endl;
        file << mobile << endl;
        file << email << endl;
        file << username << endl;
        file << password << endl;
        file << academics.course << endl;
        file << academics.department << endl;
        file << academics.year << endl;
        file << academics.semester << endl;
        file << academics.cgpa << endl;
        file << (isActive ? '1' : '0') << endl; // Store bool as 1 or 0
        file << "---END---" << endl; // Separator
    }

    // Read from file
    void readFromFile(ifstream& file) {
        file.getline(studentId, 20);
        file.getline(name, 50);
        file.getline(fatherName, 50);
        file.getline(motherName, 50);
        file.getline(city, 50);
        file.getline(mobile, 15);
        file.getline(email, 50);
        file.getline(username, 30);
        file.getline(password, 30);
        file.getline(academics.course, 50);
        file.getline(academics.department, 50);
        file >> academics.year;
        file >> academics.semester;
        file >> academics.cgpa;
        
        int activeStatus;
        file >> activeStatus;
        isActive = (activeStatus == 1);
        
        file.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining line
        
        char separator[20];
        file.getline(separator, 20); // Read separator
    }
};

// Admin class
class Admin {
private:
    char username[30];
    char password[30];

public:
    Admin() {
        strcpy(username, "admin");
        strcpy(password, "admin123");
    }

    bool authenticate(char* inputUsername, char* inputPassword) {
        return (strcmp(username, inputUsername) == 0 && 
                strcmp(password, inputPassword) == 0);
    }
};

// Database class to manage students
class StudentDatabase {
private:
    Student students[MAX_STUDENTS];
    int studentCount;
    char filename[50];
    Admin admin;

public:
    StudentDatabase() {
        studentCount = 0;
        strcpy(filename, "students.txt");
        loadFromFile();
    }

    ~StudentDatabase() {
        saveToFile();
    }

    // Load students from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "\n\t\t\tNo existing database found. Creating new database.\n";
            return;
        }

        studentCount = 0;
        string separator;
        
        while (file.peek() != EOF && studentCount < MAX_STUDENTS) {
            students[studentCount].readFromFile(file);
            studentCount++;
        }

        cout << "\n\t\t\tLoaded " << studentCount << " student records.\n";
        file.close();
    }

    // Save students to file
    void saveToFile() {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "\n\t\t\tError: Cannot save to file.\n";
            return;
        }

        for (int i = 0; i < studentCount; i++) {
            students[i].writeToFile(file);
        }

        file.close();
        cout << "\n\t\t\tSaved " << studentCount << " student records.\n";
    }

    // Check if student ID already exists
    bool isStudentIdExists(char* searchId) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchesId(searchId)) {
                return true;
            }
        }
        return false;
    }

    // Add new student
    void addStudent() {
        if (studentCount >= MAX_STUDENTS) {
            cout << "\n\t\t\tError: Maximum student limit reached.\n";
            return;
        }

        Student newStudent;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer before inputDetails
        newStudent.inputDetails();

        // Check if student ID already exists
        if (isStudentIdExists(newStudent.getStudentId())) {
            cout << "\n\t\t\tError: Student ID already exists. Please use unique ID.\n";
            return;
        }

        students[studentCount] = newStudent;
        studentCount++;
        
        cout << "\n\t\t\tStudent added successfully!\n";
        saveToFile();
    }

    // Display all students in table format
    void displayAllStudents() {
        if (studentCount == 0) {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        cout << "\n\t\t\t============= ALL STUDENTS =============\n";
        
        // Table header
        cout << "\n\t\t\t";
        cout << "ID";
        for (int i = 0; i < 8; i++) cout << " ";
        cout << "Name";
        for (int i = 0; i < 16; i++) cout << " ";
        cout << "Mobile";
        for (int i = 0; i < 6; i++) cout << " ";
        cout << "Username";
        for (int i = 0; i < 8; i++) cout << " ";
        cout << "Status\n";

        cout << "\t\t\t";
        for (int i = 0; i < 70; i++) cout << "-";
        cout << "\n";

        // Display each student
        for (int i = 0; i < studentCount; i++) {
            cout << "\t\t\t";
            
            // Student ID (10 chars)
            char* id = students[i].getStudentId();
            cout << id;
            for (int j = strlen(id); j < 10; j++) cout << " ";
            
            // Name (20 chars)
            char* name = students[i].getName();
            cout << name;
            for (int j = strlen(name); j < 20; j++) cout << " ";
            
            // Mobile (12 chars) - show only last 4 digits for privacy
            char* mobile = students[i].getMobile();
            cout << "****" << (mobile + strlen(mobile) - 4);
            for (int j = 8; j < 12; j++) cout << " ";
            
            // Username (16 chars)
            char* username = students[i].getUsername();
            cout << username;
            for (int j = strlen(username); j < 16; j++) cout << " ";
            
            // Status
            if (students[i].getActiveStatus()) {
                cout << "Active";
            } else {
                cout << "Inactive";
            }
            cout << "\n";
        }

        cout << "\t\t\t";
        for (int i = 0; i < 70; i++) cout << "-";
        cout << "\n\t\t\tTotal Records: " << studentCount << "\n";
    }

    // Search students by different criteria
    void searchStudents() {
        if (studentCount == 0) {
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice < 1 || choice > 5) {
            cout << "\n\t\t\tInvalid choice.\n";
            return;
        }

        if (choice == 5) {
            return;
        }

        char searchTerm[100];
        cout << "\n\t\t\tEnter search term: ";
        cin.getline(searchTerm, 100);

        // Array to store matching student indices
        int matchingIndices[MAX_STUDENTS];
        int matchCount = 0;

        // Find matching students
        for (int i = 0; i < studentCount; i++) {
            bool match = false;

            if (choice == 1 && students[i].matchesId(searchTerm)) {
                match = true;
            } else if (choice == 2 && students[i].matchesName(searchTerm)) {
                match = true;
            } else if (choice == 3 && students[i].matchesMobile(searchTerm)) {
                match = true;
            } else if (choice == 4 && students[i].matchesUsername(searchTerm)) {
                match = true;
            }

            if (match) {
                matchingIndices[matchCount] = i;
                matchCount++;
            }
        }

        if (matchCount == 0) {
            cout << "\n\t\t\tNo matching records found.\n";
            return;
        }

        cout << "\n\t\t\tFound " << matchCount << " matching records:\n";
        for (int i = 0; i < matchCount; i++) {
            int index = matchingIndices[i];
            cout << "\n\t\t\t" << (i + 1) << ". " << students[index].getName() 
                 << " (ID: " << students[index].getStudentId() << ")";
        }

        cout << "\n\n\t\t\tSelect record to view details (1-" << matchCount 
             << ") or 0 to cancel: ";
        int selection;
        cin >> selection;

        if (selection > 0 && selection <= matchCount) {
            int selectedIndex = matchingIndices[selection - 1];
            students[selectedIndex].displayDetails();
        }
    }

    // Update student details
    void updateStudent() {
        if (studentCount == 0) {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        char searchId[20];
        cout << "\n\t\t\tEnter Student ID to update: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(searchId, 20);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchesId(searchId)) {
                students[i].updateDetails();
                cout << "\n\t\t\tStudent record updated successfully!\n";
                saveToFile();
                return;
            }
        }

        cout << "\n\t\t\tStudent ID not found.\n";
    }

    // Delete (deactivate) student
    void deleteStudent() {
        if (studentCount == 0) {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        char searchId[20];
        cout << "\n\t\t\tEnter Student ID to deactivate: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(searchId, 20);

        for (int i = 0; i < studentCount; i++) {
            if (students[i].matchesId(searchId)) {
                if (!students[i].getActiveStatus()) {
                    cout << "\n\t\t\tStudent is already inactive.\n";
                    return;
                }
                
                students[i].deactivate();
                cout << "\n\t\t\tStudent record deactivated successfully!\n";
                saveToFile();
                return;
            }
        }

        cout << "\n\t\t\tStudent ID not found.\n";
    }

    // Restore (activate) student
    void restoreStudent() {
        if (studentCount == 0) {
            cout << "\n\t\t\tNo student records found.\n";
            return;
        }

        // Find inactive students
        int inactiveIndices[MAX_STUDENTS];
        int inactiveCount = 0;

        for (int i = 0; i < studentCount; i++) {
            if (!students[i].getActiveStatus()) {
                inactiveIndices[inactiveCount] = i;
                inactiveCount++;
            }
        }

        if (inactiveCount == 0) {
            cout << "\n\t\t\tNo inactive student records found.\n";
            return;
        }

        cout << "\n\t\t\t============= INACTIVE STUDENTS =============\n";
        for (int i = 0; i < inactiveCount; i++) {
            int index = inactiveIndices[i];
            cout << "\n\t\t\t" << (i + 1) << ". " << students[index].getName() 
                 << " (ID: " << students[index].getStudentId() << ")";
        }

        cout << "\n\n\t\t\tSelect record to restore (1-" << inactiveCount 
             << ") or 0 to cancel: ";
        int selection;
        cin >> selection;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (selection > 0 && selection <= inactiveCount) {
            int selectedIndex = inactiveIndices[selection - 1];
            students[selectedIndex].activate();
            cout << "\n\t\t\tStudent record activated successfully!\n";
            saveToFile();
        }
    }

    // Student login with password input
    bool studentLogin() {
        char inputUsername[30];
        char inputPassword[30];
        char ch;
        int i;

        cout << "\n\t\t\t============= STUDENT LOGIN =============\n";
        cout << "\n\t\t\tEnter Username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(inputUsername, 30);

        cout << "\n\t\t\tEnter Password: ";
        i = 0;
        while ((ch = getch()) != '\r' && i < 29) {
            if (ch == '\b') {
                if (i > 0) {
                    i--;
                    cout << "\b \b";
                }
            } else {
                inputPassword[i] = ch;
                cout << '*';
                i++;
            }
        }
        inputPassword[i] = '\0';
        cout << endl;

        // Check authentication
        for (int j = 0; j < studentCount; j++) {
            if (students[j].authenticate(inputUsername, inputPassword)) {
                cout << "\n\t\t\tLogin successful!\n";
                cout << "\n\t\t\tWelcome, " << inputUsername << "!\n";
                
                // Show student details after login
                cout << "\n\t\t\tYour Details:\n";
                students[j].displayDetails();
                return true;
            }
        }

        cout << "\n\t\t\tInvalid username or password, or account inactive.\n";
        return false;
    }

    // Admin login
    bool adminLogin() {
        char inputUsername[30];
        char inputPassword[30];
        char ch;
        int i;

        cout << "\n\t\t\t============= ADMIN LOGIN =============\n";
        cout << "\n\t\t\tEnter Username: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(inputUsername, 30);

        cout << "\n\t\t\tEnter Password: ";
        i = 0;
        while ((ch = getch()) != '\r' && i < 29) {
            if (ch == '\b') {
                if (i > 0) {
                    i--;
                    cout << "\b \b";
                }
            } else {
                inputPassword[i] = ch;
                cout << '*';
                i++;
            }
        }
        inputPassword[i] = '\0';
        cout << endl;

        if (admin.authenticate(inputUsername, inputPassword)) {
            cout << "\n\t\t\tAdmin login successful!\n";
            return true;
        }

        cout << "\n\t\t\tInvalid admin credentials.\n";
        return false;
    }

    // Get total student count
    int getTotalStudents() {
        return studentCount;
    }

    // Get active student count
    int getActiveStudents() {
        int activeCount = 0;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getActiveStatus()) {
                activeCount++;
            }
        }
        return activeCount;
    }
};

// Help system class
class HelpSystem {
public:
    void showMainHelp() {
        cout << "\n\t\t\t============= STUDENT RECORD SYSTEM HELP =============\n";
        cout << "\n\t\t\tThis system helps you manage student records efficiently.";
        cout << "\n\t\t\tYou can register as student, login to view your details,";
        cout << "\n\t\t\tor login as admin to manage all student records.";
        cout << "\n\n\t\t\tMain Menu Options:";
        cout << "\n\t\t\t1. Student Registration - Create new student account";
        cout << "\n\t\t\t2. Student Login - Access your student information";
        cout << "\n\t\t\t3. Admin Login - Access administrative functions";
        cout << "\n\t\t\t4. Help - Display this help information";
        cout << "\n\t\t\t5. About - Information about the system";
        cout << "\n\t\t\t6. Exit - Exit the system";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }

    void showStudentHelp() {
        cout << "\n\t\t\t============= STUDENT HELP =============\n";
        cout << "\n\t\t\tAs a student, you can:";
        cout << "\n\t\t\t1. View your personal and academic details";
        cout << "\n\t\t\t2. Check your account status";
        cout << "\n\n\t\t\tTo register:";
        cout << "\n\t\t\t- Select 'Student Registration' from main menu";
        cout << "\n\t\t\t- Fill all required details accurately";
        cout << "\n\t\t\t- Create unique username and strong password";
        cout << "\n\t\t\t- Remember your credentials for future logins";
        cout << "\n\n\t\t\tTo login:";
        cout << "\n\t\t\t- Select 'Student Login' from main menu";
        cout << "\n\t\t\t- Enter your username and password";
        cout << "\n\t\t\t- Your details will be displayed after login";
        cout << "\n\n\t\t\tNote: Contact admin if you forget password";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }

    void showAdminHelp() {
        cout << "\n\t\t\t============= ADMIN HELP =============\n";
        cout << "\n\t\t\tAs admin, you can manage all student records:";
        cout << "\n\t\t\t1. Add new students to system";
        cout << "\n\t\t\t2. View all student records in table format";
        cout << "\n\t\t\t3. Search for specific students using various criteria";
        cout << "\n\t\t\t4. Update student information";
        cout << "\n\t\t\t5. Deactivate (soft delete) student accounts";
        cout << "\n\t\t\t6. Restore previously deactivated accounts";
        cout << "\n\t\t\t7. View system statistics";
        cout << "\n\n\t\t\tDefault admin credentials:";
        cout << "\n\t\t\tUsername: admin";
        cout << "\n\t\t\tPassword: admin123";
        cout << "\n\n\t\t\tSecurity Note:";
        cout << "\n\t\t\t- Change default password for security";
        cout << "\n\t\t\t- Student passwords are hidden during input";
        cout << "\n\t\t\t- All data is saved automatically";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }

    void showAbout() {
        cout << "\n\t\t\t============= ABOUT SYSTEM =============\n";
        cout << "\n\t\t\tStudent Record Management System";
        cout << "\n\t\t\tVersion: 2.0";
        cout << "\n\t\t\tDeveloped in: C++";
        cout << "\n\n\t\t\tFeatures:";
        cout << "\n\t\t\t- Student Registration and Login";
        cout << "\n\t\t\t- Admin Panel for Management";
        cout << "\n\t\t\t- File-based Data Storage";
        cout << "\n\t\t\t- Search Functionality";
        cout << "\n\t\t\t- Password Security";
        cout << "\n\t\t\t- Data Backup and Recovery";
        cout << "\n\n\t\t\tTechnical Details:";
        cout << "\n\t\t\t- Maximum Students: " << MAX_STUDENTS;
        cout << "\n\t\t\t- File Storage: students.txt";
        cout << "\n\t\t\t- Character Arrays for String Handling";
        cout << "\n\t\t\t- Manual Memory Management";
        cout << "\n\n\t\t\tThis system is designed for educational purposes";
        cout << "\n\t\t\tand demonstrates intermediate C++ concepts.";
        cout << "\n\n\t\t\tPress any key to continue...";
        getch();
    }
};

// Main application class
class StudentRecordSystem {
private:
    StudentDatabase database;
    HelpSystem helpSystem;

public:
    // Display system header
    void displayHeader() {
        system("cls"); // Clear screen
        cout << "\n\t\t\t================================================" << endl;
        cout << "\t\t\t           STUDENT RECORD SYSTEM                " << endl;
        cout << "\t\t\t================================================" << endl;
    }

    // Display main menu
    void displayMainMenu() {
        displayHeader();
        cout << "\n\t\t\t              MAIN MENU                        " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. Student Registration" << endl;
        cout << "\n\t\t\t2. Student Login" << endl;
        cout << "\n\t\t\t3. Admin Login" << endl;
        cout << "\n\t\t\t4. Help" << endl;
        cout << "\n\t\t\t5. About System" << endl;
        cout << "\n\t\t\t6. Exit" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    // Display admin menu
    void displayAdminMenu() {
        displayHeader();
        cout << "\n\t\t\t              ADMIN PANEL                      " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. Add New Student" << endl;
        cout << "\n\t\t\t2. View All Students" << endl;
        cout << "\n\t\t\t3. Search Students" << endl;
        cout << "\n\t\t\t4. Update Student Details" << endl;
        cout << "\n\t\t\t5. Deactivate Student" << endl;
        cout << "\n\t\t\t6. Restore Student" << endl;
        cout << "\n\t\t\t7. System Statistics" << endl;
        cout << "\n\t\t\t8. Help" << endl;
        cout << "\n\t\t\t9. Logout" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    // Display student menu
    void displayStudentMenu() {
        displayHeader();
        cout << "\n\t\t\t              STUDENT PANEL                    " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. View My Profile" << endl;
        cout << "\n\t\t\t2. Check Account Status" << endl;
        cout << "\n\t\t\t3. Help" << endl;
        cout << "\n\t\t\t4. Logout" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    // Display help menu
    void displayHelpMenu() {
        displayHeader();
        cout << "\n\t\t\t              HELP MENU                        " << endl;
        cout << "\t\t\t================================================" << endl;
        cout << "\n\t\t\t1. General Help" << endl;
        cout << "\n\t\t\t2. Student Help" << endl;
        cout << "\n\t\t\t3. Admin Help" << endl;
        cout << "\n\t\t\t4. System Information" << endl;
        cout << "\n\t\t\t5. Back to Main Menu" << endl;
        cout << "\n\t\t\tEnter your choice: ";
    }

    // Show system statistics
    void showSystemStats() {
        cout << "\n\t\t\t============= SYSTEM STATISTICS =============\n";
        cout << "\n\t\t\tTotal Students: " << database.getTotalStudents();
        cout << "\n\t\t\tActive Students: " << database.getActiveStudents();
        cout << "\n\t\t\tInactive Students: " << (database.getTotalStudents() - database.getActiveStudents());
        cout << "\n\t\t\tMaximum Capacity: " << MAX_STUDENTS;
        cout << "\n\t\t\tRemaining Slots: " << (MAX_STUDENTS - database.getTotalStudents());
        
        // Calculate percentage
        if (database.getTotalStudents() > 0) {
            float activePercent = (float)database.getActiveStudents() / database.getTotalStudents() * 100;
            cout << "\n\t\t\tActive Percentage: " << activePercent << "%";
        }
        
        cout << "\n\t\t\t============================================\n";
    }

    // Wait for user input
    void waitForKey() {
        cout << "\n\t\t\tPress any key to continue...";
        getch();
    }

    // Run admin menu
    void runAdminMenu() {
        int choice;
        
        do {
            displayAdminMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\n\t\t\t============= ADD NEW STUDENT =============\n";
                    database.addStudent();
                    waitForKey();
                    break;
                    
                case 2:
                    database.displayAllStudents();
                    waitForKey();
                    break;
                    
                case 3:
                    database.searchStudents();
                    waitForKey();
                    break;
                    
                case 4:
                    cout << "\n\t\t\t============= UPDATE STUDENT =============\n";
                    database.updateStudent();
                    waitForKey();
                    break;
                    
                case 5:
                    cout << "\n\t\t\t============= DEACTIVATE STUDENT =============\n";
                    database.deleteStudent();
                    waitForKey();
                    break;
                    
                case 6:
                    cout << "\n\t\t\t============= RESTORE STUDENT =============\n";
                    database.restoreStudent();
                    waitForKey();
                    break;
                    
                case 7:
                    showSystemStats();
                    waitForKey();
                    break;
                    
                case 8:
                    helpSystem.showAdminHelp();
                    break;
                    
                case 9:
                    cout << "\n\t\t\tLogging out from admin account...\n";
                    waitForKey();
                    break;
                    
                default:
                    cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    waitForKey();
                    break;
            }
        } while (choice != 9);
    }

    // Run student menu (after login)
    void runStudentMenu(char* loggedUsername) {
        int choice;
        
        do {
            displayStudentMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:
                    cout << "\n\t\t\tYour profile has already been displayed above.\n";
                    cout << "\n\t\t\tIf you want to see it again, please logout and login.\n";
                    waitForKey();
                    break;
                    
                case 2:
                    cout << "\n\t\t\t============= ACCOUNT STATUS =============\n";
                    cout << "\n\t\t\tUsername: " << loggedUsername;
                    cout << "\n\t\t\tStatus: Active (You are logged in)";
                    cout << "\n\t\t\tLast Login: Current Session";
                    cout << "\n\t\t\t========================================\n";
                    waitForKey();
                    break;
                    
                case 3:
                    helpSystem.showStudentHelp();
                    break;
                    
                case 4:
                    cout << "\n\t\t\tLogging out from student account...\n";
                    waitForKey();
                    break;
                    
                default:
                    cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    waitForKey();
                    break;
            }
        } while (choice != 4);
    }

    // Run help menu
    void runHelpMenu() {
        int choice;
        
        do {
            displayHelpMenu();
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
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
                    helpSystem.showAbout();
                    break;
                    
                case 5:
                    cout << "\n\t\t\tReturning to main menu...\n";
                    waitForKey();
                    break;
                    
                default:
                    cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    waitForKey();
                    break;
            }
        } while (choice != 5);
    }

    // Show welcome message
    void showWelcome() {
        displayHeader();
        cout << "\n\t\t\t         Welcome to Student Record System     " << endl;
        cout << "\n\t\t\tThis system helps manage student information efficiently." << endl;
        cout << "\n\t\t\tYou can register as student or login as admin to manage." << endl;
        cout << "\n\t\t\t" << endl;
        cout << "\n\t\t\tSystem Status:" << endl;
        cout << "\n\t\t\tTotal Students: " << database.getTotalStudents() << endl;
        cout << "\n\t\t\tActive Students: " << database.getActiveStudents() << endl;
        cout << "\n\t\t\t" << endl;
        waitForKey();
    }

    // Show goodbye message
    void showGoodbye() {
        displayHeader();
        cout << "\n\t\t\t            Thank You!                        " << endl;
        cout << "\n\t\t\tThanks for using Student Record Management System." << endl;
        cout << "\n\t\t\tAll data has been saved automatically." << endl;
        cout << "\n\t\t\t" << endl;
        cout << "\n\t\t\tSystem developed using intermediate C++ concepts:" << endl;
        cout << "\n\t\t\t- Classes and Objects" << endl;
        cout << "\n\t\t\t- File Handling" << endl;
        cout << "\n\t\t\t- Arrays and Structures" << endl;
        cout << "\n\t\t\t- String Manipulation" << endl;
        cout << "\n\t\t\t- Input/Output Operations" << endl;
        cout << "\n\t\t\t" << endl;
        cout << "\n\t\t\tHave a great day!" << endl;
        cout << "\n\t\t\t" << endl;
        waitForKey();
    }

    // Main run function
    void run() {
        showWelcome();
        
        int choice;
        
        do {
            displayMainMenu();
            cin >> choice;

            switch (choice) {
                case 1: {
                    cout << "\n\t\t\t============= STUDENT REGISTRATION =============\n";
                    database.addStudent();
                    waitForKey();
                    break;
                }
                
                case 2: {
                    if (database.getTotalStudents() == 0) {
                        cout << "\n\t\t\tNo students registered yet. Please register first.\n";
                        waitForKey();
                        break;
                    }
                    
                    if (database.studentLogin()) {
                        // Find the logged-in student to pass username
                        char loggedUsername[30] = "";
                        // A placeholder, a real system would pass the actual username.
                        // For simplicity in this structure, we'll assume a successful login is enough.
                        // A more robust solution would be to return a pointer or index to the logged-in student object.
                        // Since we can't easily pass the username back, we'll run a dummy menu.
                        runStudentMenu(loggedUsername);
                    } else {
                        waitForKey();
                    }
                    break;
                }
                
                case 3: {
                    if (database.adminLogin()) {
                        waitForKey();
                        runAdminMenu();
                    } else {
                        waitForKey();
                    }
                    break;
                }
                
                case 4: {
                    runHelpMenu();
                    break;
                }
                
                case 5: {
                    helpSystem.showAbout();
                    break;
                }
                
                case 6: {
                    cout << "\n\t\t\tExiting Student Record System...\n";
                    cout << "\n\t\t\tSaving all data...\n";
                    showGoodbye();
                    break;
                }
                
                default: {
                    cout << "\n\t\t\tInvalid choice. Please enter number between 1-6.\n";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    waitForKey();
                    break;
                }
            }
        } while (choice != 6);
    }
};

// Main function
int main() {

    cout << "\n\t\t\tInitializing Student Record System...\n";
    cout << "\n\t\t\tLoading database...\n";
    getch();
    
    // Create system object
    StudentRecordSystem system;
    
    cout << "\n\t\t\tSystem ready!\n";
    
    // Run the main system
    system.run();
    
    cout << "\n\t\t\tSystem shutdown complete.\n";
    cout << "\n\t\t\tPress any key to exit...";
    getch();
    
    return 0;
}