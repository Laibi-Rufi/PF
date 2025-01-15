#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Patient {
    string patientId;
    string name;
    int age;
    string disease;
    string roomNumber;
};

Patient patients[100];
int patientCount = 0;

void saveToFile() {
    ofstream file("patients.txt", ios::out);
    if (!file) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        file << patients[i].patientId << endl
             << patients[i].name << endl
             << patients[i].age << endl
             << patients[i].disease << endl
             << patients[i].roomNumber << endl;
    }

    file.close();
    cout << "Patient data saved successfully." << endl;
}

void loadFromFile() {
    ifstream file("patients.txt", ios::in);
    if (!file) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    while (file >> patients[patientCount].patientId) {
        file.ignore();
        getline(file, patients[patientCount].name);
        file >> patients[patientCount].age;
        file.ignore();
        getline(file, patients[patientCount].disease);
        getline(file, patients[patientCount].roomNumber);
        patientCount++;
    }

    file.close();
    cout << "Patient data loaded successfully." << endl;
}

void addPatient() {
    if (patientCount < 100) {
        cout << "Enter Patient ID: ";
        cin >> patients[patientCount].patientId;
        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, patients[patientCount].name);

        cout << "Enter Patient Age: ";
        cin >> patients[patientCount].age;
        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, patients[patientCount].disease);

        cout << "Enter Room Number: ";
        getline(cin, patients[patientCount].roomNumber);

        patientCount++;
        cout << "Patient added successfully!" << endl;
    } else {
        cout << "Cannot add more patients. The system is full." << endl;
    }
}

void searchPatient() {
    string searchId;
    cout << "Enter Patient ID to search: ";
    cin >> searchId;

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].patientId == searchId) {
            cout << "Patient ID: " << patients[i].patientId << endl;
            cout << "Name: " << patients[i].name << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Disease: " << patients[i].disease << endl;
            cout << "Room Number: " << patients[i].roomNumber << endl;
            return;
        }
    }
    cout << "Patient with ID " << searchId << " not found!" << endl;
}

void displayAllPatients() {
    if (patientCount == 0) {
        cout << "No patients available." << endl;
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        cout << "Patient ID: " << patients[i].patientId << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Disease: " << patients[i].disease << endl;
        cout << "Room Number: " << patients[i].roomNumber << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {
    int choice;
    loadFromFile();

    while (true) {
        cout << "\nHospital Patient Management System" << endl;
        cout << "1. Add new patient" << endl;
        cout << "2. Search for a patient by Patient ID" << endl;
        cout << "3. Display all patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPatient();
            break;
        case 2:
            searchPatient();
            break;
        case 3:
            displayAllPatients();
            break;
        case 4:
            saveToFile();
            cout << "Exiting the system." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
