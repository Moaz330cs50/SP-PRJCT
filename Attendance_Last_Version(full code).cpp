#include <iostream>
using namespace std;
struct Employee {
    int EmployeeId;
    string name;
} employees[100];
struct Attendance {
    int EmployeeId;
    int month;
    int Dayspresent;
    int DaysAbsent;
} attendanceRecords[200];
int empcount = 5;
int attCount = 0;
void recordAttendance();
void editAttendance();
void showAttendance();
void startAttendance();
int main() {
    employees[0] = {1, "Ahmed"};
    employees[1] = {2, "Sara"};
    employees[2] = {3, "Omar"};
    empcount = 3;
startAttendance();
    return 0;
}
void startAttendance() {
     int choice;
    do {
        cout << "\n=== Attendance Menu ===\n";
        cout << "1. Record Attendance\n";
        cout << "2. Edit Attendance\n";
        cout << "3. Show Attendance\n";
        cout << "4. Back To Main MENU\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        if (choice == 1) recordAttendance();
        else if (choice == 2) editAttendance();
        else if (choice == 3) showAttendance();
        else if (choice == 4) ;
        else if (choice != 0) cout << "Invalid choice.\n";
    } while (choice != 0);
    
}
void recordAttendance() {
    if (attCount >= 200) { 
        cout << "attendance record are full\n";
        return;
    }
    int id;
    cout << "Enter employee ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < empcount; i++) {
        if (employees[i].EmployeeId == id) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee ID isn't found!\n";
        return;
    }
    Attendance a;
    a.EmployeeId = id;
    cout << "Enter month (1-12): ";
    cin >> a.month;
    for (int i = 0; i < attCount; i++) {
        if (attendanceRecords[i].EmployeeId == id &&
            attendanceRecords[i].month == a.month) {
            cout << "Record already exists\n";
            return;
        }
    }
    cout << "Enter days present: ";
    cin >> a.Dayspresent;
    cout << "Enter days absent: ";
    cin >> a.DaysAbsent;
    attendanceRecords[attCount] = a; 
    /* same type of struct,so that's fine to intialize one of em to the other, even if it's array to variable */
    attCount++;
    cout << "Done.\n";
}
void editAttendance() {
    int id, month;
    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter month: ";
    cin >> month;
    for (int i = 0; i < attCount; i++) {
        if (attendanceRecords[i].EmployeeId == id &&
            attendanceRecords[i].month == month) {
            cout << "Found."<<endl;
            cout<<"Enter new days present: ";
            cin >> attendanceRecords[i].Dayspresent;
            cout << "Enter new days absent: ";
            cin >> attendanceRecords[i].DaysAbsent;
            cout << "Updated.\n";
            return;
        }
    }
    cout << "Not found!,entered ID/month is wrong!\n";
    return;
}
void showAttendance() {
    int id;
    cout << "Enter employee ID: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < attCount; i++) {
        if (attendanceRecords[i].EmployeeId == id) {
            found = true;
            cout << "---------------------------\n";
            cout << "Employee ID: " << attendanceRecords[i].EmployeeId << "\n";
            cout << "Month      : " << attendanceRecords[i].month << "\n";
            cout << "Present    : " << attendanceRecords[i].Dayspresent << " days\n";
            cout << "Absent     : " << attendanceRecords[i].DaysAbsent << " days\n";
        }
    }
    if (!found) {
    cout << "Not found!,ID entered is wrong!\n";
    return;}
    
}
