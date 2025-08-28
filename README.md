# Student Record Management System



This is a console-based **Student Record Management System** developed in C++. It provides a robust, file-based solution for managing student data, including registration, login, and administrative functions. The system is designed to be user-friendly and demonstrates key C++ programming concepts like **Object-Oriented Programming (OOP)**, **file handling**, and **data management**.

## ✨ Features

-   **Student Registration & Login**: Students can create a new account and log in to view their personal and academic details.
-   **Admin Panel**: A dedicated administrative interface for managing all student records.
-   **File-based Data Storage**: All student data is persisted to a file (`students.txt`), ensuring that information is not lost when the program closes.
-   **Search Functionality**: Admins can search for students by ID, name, mobile number, or username.
-   **Data Management**: Admins can add, update, deactivate, and reactivate student records.
-   **Password Security**: Passwords are hidden during input for enhanced security.
-   **System Statistics**: View quick statistics like total students, active students, and system capacity.
-   **Help & About Sections**: Built-in help and information sections to guide users and provide details about the system.

## ⚙️ How to Compile and Run

### Prerequisites

You need a C++ compiler installed on your system, such as GCC (g++) or a C++ compiler within an IDE like Visual Studio or Code::Blocks.

The program uses the `<conio.h>` header for `getch()`, which is a non-standard, but common, header on Windows systems. If you're using Linux or macOS, you may need to install a library like `ncurses` or modify the `getch()` function to be compatible with your operating system.

### Compilation

1.  **Save the file**: Save the provided code as a `.cpp` file (e.g., `main.cpp`).
2.  **Open your terminal or command prompt**.
3.  **Navigate to the directory** where you saved the file.
4.  **Compile the code** using your C++ compiler.

    **For Windows (with g++):**
    ```sh
    g++ main.cpp -o StudentSystem.exe
    ```

    **For Linux/macOS (with g++ and ncurses):**
    If you're using Linux, you might need to handle the `getch()` function differently. One way is to replace `<conio.h>` with `<curses.h>` and link the `ncurses` library.
    ```sh
    g++ main.cpp -o StudentSystem -lncurses
    ```
    *Note: You may need to install the `ncurses` library first (`sudo apt-get install libncurses-dev` on Debian/Ubuntu).*

### Execution

After successful compilation, run the executable:

**On Windows:**
```sh
StudentSystem.exe
