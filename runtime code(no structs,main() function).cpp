//BEFORE MAIN
int attCount = 0;
void recordAttendance();
void editAttendance();
void showAttendance();
//AFTER MAIN
void recordAttendance() {
    if (attCount >= 200) {
        cout << "Records are full\n";
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
        cout << "Employee not found\n";
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
            cout << "Found. Enter new days present: ";
            cin >> attendanceRecords[i].Dayspresent;
            cout << "Enter new days absent: ";
            cin >> attendanceRecords[i].DaysAbsent;
            cout << "Updated.\n";
            return;
        }
    }
    cout << "No record found!\n";
}
void showAttendance() {
    int id;
    cout << "Enter employee ID (0 for all): ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < attCount; i++) {
        if (id == 0 || attendanceRecords[i].EmployeeId == id) {
            cout << "---------------------------\n";
            cout << "Employee ID: " << attendanceRecords[i].EmployeeId << "\n";
            cout << "Month      : " << attendanceRecords[i].month << "\n";
            cout << "Present    : " << attendanceRecords[i].Dayspresent << " days\n";
            cout << "Absent     : " << attendanceRecords[i].DaysAbsent << " days\n";
            found = true;
        }
    }
    if (!found) cout << "No records found!\n";
}
