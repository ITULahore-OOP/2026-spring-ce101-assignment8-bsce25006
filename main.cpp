#include <iostream>
using namespace std;

#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

int main() {

    string deptName;
    cout << "Enter Department Name: ";
    cin >> deptName;

    Department dept(deptName);

    // Store sessions
    TutoringSession* sessions[10];
    int sessionCount = 0;

    int choice;

    do {
        cout << endl;
        cout << "University System Menu " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Staff" << endl;
        cout << "3. Add Teaching Assistant" << endl;
        cout << "4. Display All Roles" << endl;
        cout << "5. Grade Assignment (TA)" << endl;
        cout << "6. Create Tutoring Session" << endl;
        cout << "7. Merge Two Sessions (+)" << endl;
        cout << "8. Compare Two Sessions (>)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            double cgpa;

            cout << "Enter Student Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;

            Student* s = new Student(name, id, cgpa);
            dept.addMember(s);

            cout << "Student added successfully." << endl;
        }

        else if (choice == 2) {
            string name, cardID;
            int id, accessLevel;
            double salary;

            cout << "Enter Staff Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> accessLevel;

            AccessCard card(cardID, accessLevel);

            Staff* st = new Staff(name, id, salary, card);
            dept.addMember(st);

            cout << "Staff added successfully." << endl;
        }

        else if (choice == 3) {
            string name, cardID;
            int id, accessLevel, hours;
            double cgpa, salary;

            cout << "Enter TA Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> accessLevel;

            cout << "Enter Working Hours: ";
            cin >> hours;

            AccessCard card(cardID, accessLevel);

            TeachingAssistant* ta =
                new TeachingAssistant(name, id, cgpa, salary, card, hours);

            dept.addMember(ta);

            cout << "Teaching Assistant added successfully." << endl;
        }

        else if (choice == 4) {
            cout << endl;
            cout << "Displaying All Roles:" << endl;
            dept.displayAllRoles();
        }

        else if (choice == 5) {
            string name, cardID;
            int id, accessLevel, hours;
            double cgpa, salary;

            cout << "Enter TA Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> accessLevel;

            cout << "Enter Working Hours: ";
            cin >> hours;

            AccessCard card(cardID, accessLevel);

            TeachingAssistant ta(name, id, cgpa, salary, card, hours);

            int type;
            cout << "Enter 1 for numeric grading, 2 for letter grading: ";
            cin >> type;

            if (type == 1) {
                int score;
                cout << "Enter score: ";
                cin >> score;
                ta.gradeAssignment(score);
            }
            else {
                string grade;
                cout << "Enter letter grade: ";
                cin >> grade;
                ta.gradeAssignment(grade);
            }
        }

        else if (choice == 6) {
            if (sessionCount >= 10) {
                cout << "Session limit reached." << endl;
                continue;
            }

            string taName, stName, cardID;
            int taID, stID, accessLevel, hours;
            double cgpaTA, salary, cgpaStudent, duration;

            cout << "Enter TA Name: ";
            cin >> taName;
            cout << "Enter TA ID: ";
            cin >> taID;
            cout << "Enter TA CGPA: ";
            cin >> cgpaTA;
            cout << "Enter TA Salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level: ";
            cin >> accessLevel;

            cout << "Enter Working Hours: ";
            cin >> hours;

            AccessCard card(cardID, accessLevel);
            TeachingAssistant* ta =
                new TeachingAssistant(taName, taID, cgpaTA, salary, card, hours);

            cout << "Enter Student Name: ";
            cin >> stName;
            cout << "Enter Student ID: ";
            cin >> stID;
            cout << "Enter Student CGPA: ";
            cin >> cgpaStudent;

            Student* s = new Student(stName, stID, cgpaStudent);

            int sessionID;
            cout << "Enter Session ID: ";
            cin >> sessionID;
            cout << "Enter Duration (minutes): ";
            cin >> duration;

            sessions[sessionCount] =
                new TutoringSession(sessionID, duration, ta, s);

            sessionCount++;

            cout << "Session created successfully." << endl;
        }

        else if (choice == 7) {
            if (sessionCount < 2) {
                cout << "Not enough sessions to merge." << endl;
                continue;
            }

            int i, j;
            cout << "Enter index of first session: ";
            cin >> i;
            cout << "Enter index of second session: ";
            cin >> j;

            TutoringSession merged = *sessions[i] + *sessions[j];

            cout << "Merged Session Duration: "
                 << merged.getDuration() << endl;
        }

        else if (choice == 8) {
            if (sessionCount < 2) {
                cout << "Not enough sessions to compare." << endl;
                continue;
            }

            int i, j;
            cout << "Enter index of first session: ";
            cin >> i;
            cout << "Enter index of second session: ";
            cin >> j;

            if (*sessions[i] > *sessions[j]) {
                cout << "First session is longer." << endl;
            }
            else {
                cout << "Second session is longer." << endl;
            }
        }

    } while (choice != 0);

    cout << "Exiting program." << endl;

    return 0;
}