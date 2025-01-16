#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    char grade[5];
};

void addStudent(Student students[], int &count) {
    if (count < 100) {
        cout << "Enter ID: ";
        cin >> students[count].id;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(students[count].name, 50);
        cout << "Enter Age: ";
        cin >> students[count].age;
        cout << "Enter Grade: ";
        cin.ignore();
        cin.getline(students[count].grade, 5);
        count++;
    } else {
        cout << "Student limit reached!\n";
    }
}

void displayStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << "-----------------------------\n";
    }
}

void searchStudent(Student students[], int count) {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Grade: " << students[i].grade << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent(Student students[], int &count) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void saveToFile(Student students[], int count) {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << students[i].id << endl;
            file << students[i].name << endl;
            file << students[i].age << endl;
            file << students[i].grade << endl;
        }
        file.close();
        cout << "Data saved to file successfully!\n";
    } else {
        cout << "Error saving to file!\n";
    }
}

void loadFromFile(Student students[], int &count) {
    ifstream file("students.txt");
    if (file.is_open()) {
        count = 0;
        while (file >> students[count].id) {
            file.ignore();
            file.getline(students[count].name, 50);
            file >> students[count].age;
            file.ignore();
            file.getline(students[count].grade, 5);
            count++;
        }
        file.close();
        cout << "Data loaded from file successfully!\n";
    } else {
        cout << "File not found! Starting with an empty list.\n";
    }
}

void updateStudent(Student students[], int count) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            cin.getline(students[i].name, 50);
            cout << "Enter new Age: ";
            cin >> students[i].age;
            cout << "Enter new Grade: ";
            cin.ignore();
            cin.getline(students[i].grade, 5);
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void displayMenu() {
    cout << "\nMain Menu:\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Search Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Update Student\n";
    cout << "6. Save to File\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void countStudents(int count) {
    cout << "Total number of students: " << count << "\n";
}

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    cout << "Students sorted by name successfully!\n";
}

int main() {
    Student students[100];
    int count = 0;
    int choice;
    loadFromFile(students, count);
    do {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            addStudent(students, count);
        } else if (choice == 2) {
            displayStudents(students, count);
        } else if (choice == 3) {
            searchStudent(students, count);
        } else if (choice == 4) {
            deleteStudent(students, count);
        } else if (choice == 5) {
            updateStudent(students, count);
        } else if (choice == 6) {
            saveToFile(students, count);
        } else if (choice == 7) {
            saveToFile(students, count);
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
        countStudents(count);
        if (choice == 2) {
            sortStudents(students, count);
        }
    } while (choice != 7);
    return 0;
}
