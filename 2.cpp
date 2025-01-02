#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string level;
};
vector<Student> students;

void addStudent() {
    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student level: ";
    cin.ignore();
    getline(cin, student.level);

    students.push_back(student);
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty())
	 {
        cout << "No students found.\n";
        return;
    }

    cout << "List of Students:\n";
    for (const auto& student : students) 
	{
        cout << "ID: " << student.id << ", Name: " << student.name
             << ", Age: " << student.age << ", Grade: " << student.level << endl;
    }
}

void updateStudent() {
    int id;
    cout << "Enter the ID of the student to update: ";
    cin >> id;

    for (auto& student : students)
	 {
        if (student.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new age: ";
            cin >> student.age;
            cout << "Enter new level: ";
            cin.ignore();
            getline(cin, student.level);

            cout << "Student details updated successfully!\n";
            return;
        }
    }
    cout << "Student with the given ID not found.\n";
}

void deleteStudent()
 {
    int id;
    cout << "Enter  ID of the student to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) 
	{
        if (it->id == id) {
            students.erase(it);
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student with the given ID not found.\n";
}


int main() {
    int choice;

    do {
        cout << "\n=== School Management System ===\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice, please try it again.\n";
        }
    } while (choice != 5);

    return 0;
}
