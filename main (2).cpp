#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;

    void addStudent() {
        ofstream file("students.txt", ios::app);

        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        file << rollNo << " " << name << " " << age << endl;
        file.close();

        cout << "\nStudent Added Successfully!\n";
    }

    void displayStudents() {
        ifstream file("students.txt");

        int r, a;
        string n;

        cout << "\nStudent Records\n";
        cout << "-----------------\n";

        while (file >> r >> n >> a) {
            cout << "Roll No: " << r
                 << "\nName: " << n
                 << "\nAge: " << a << "\n\n";
        }

        file.close();
    }

    void searchStudent() {
        ifstream file("students.txt");

        int searchRoll;
        cout << "Enter Roll No to Search: ";
        cin >> searchRoll;

        int r, a;
        string n;
        bool found = false;

        while (file >> r >> n >> a) {
            if (r == searchRoll) {
                cout << "\nRecord Found\n";
                cout << "Roll No: " << r << endl;
                cout << "Name: " << n << endl;
                cout << "Age: " << a << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Student Not Found!\n";

        file.close();
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.addStudent();
                break;
            case 2:
                s.displayStudents();
                break;
            case 3:
                s.searchStudent();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}