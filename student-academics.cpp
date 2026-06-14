#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
    string courseName;
    double mark;
};

struct Student {
    string fullName;
    string studentID;
    string gender;
    int numCourses;
    vector<Course> courses;
    double totalMark;
    double averageMark;
    string performance;
};

int main() {
    int numStudents;

    cout << "===========================================" << endl;
    cout << " STUDENT SEMESTER RESULT MANAGMENT SYSTEM  " << endl;
    cout << "===========================================" << endl;
    cout << "Enter number of students: ";
    cin >> numStudents;

    cout << endl;

    vector<Student> students(numStudents);

    for (int i = 0; i < numStudents; i++) {
        cin.ignore();

        cout << "-------------------------------------------" << endl;
        cout << "Enter Information for Student #" << (i + 1) << endl;
        cout << "-------------------------------------------" << endl;

        cout << "Full Name: ";
        getline(cin, students[i].fullName);
        
        cout << "Student ID: ";
        getline(cin, students[i].studentID);
        
        cout << "Gender: ";
        cin >> students[i].gender;

        courseInput:
        
        cout << "Number of Courses (6 - 7): ";
        cin >> students[i].numCourses;

        if (students[i].numCourses < 6 || students[i].numCourses > 7) {
            cout << "Invalid! Enter between 6 and 7 courses." << endl << endl;
            goto courseInput;
        }

        students[i].totalMark = 0;

        cout << endl;

        for (int j = 0; j < students[i].numCourses; j++) {
            Course c;
            cin.ignore();

            cout << "Course " << (j + 1) << endl;

            cout << "Course Name: ";
            getline(cin, c.courseName);
            
            cout << "Course Mark (0 - 100): ";
            cin >> c.mark;
            
            students[i].courses.push_back(c);
            students[i].totalMark += c.mark;

            cout << endl;
        }

        if (students[i].numCourses > 0) {
            students[i].averageMark = students[i].totalMark / students[i].numCourses;
        } else {
            students[i].averageMark = 0;
        }

        if (students[i].averageMark >= 85) {
            students[i].performance = "Excellent";
        } else if (students[i].averageMark >= 70) {
            students[i].performance = "Very Good";
        } else if (students[i].averageMark >= 60) {
            students[i].performance = "Good";
        } else if (students[i].averageMark >= 50) {
            students[i].performance = "Pass";
        } else {
            students[i].performance = "Fail";
        }
    }

    cout << "\n==============================================" << endl;
    cout << "             STUDENT RESULT REPORTS           " << endl;
    cout << "==============================================" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << "-------------------------------------------" << endl;
        cout << " Student " << (i + 1) << endl;
        cout << "-------------------------------------------" << endl;

        cout << "Full Name:   " << students[i].fullName << endl;
        cout << "Student ID:  " << students[i].studentID << endl;
        cout << "Gender:      " << students[i].gender << endl;

        cout << endl;

        cout << "Course Details" << endl;
        cout << "Course Name             Mark" << endl;
        for (int j = 0; j < students[i].numCourses; j++) {
            cout << students[i].courses[j].courseName;
            
            int nameLength = students[i].courses[j].courseName.length();
            for (int space = 0; space < (24 - nameLength); space++) {
                cout << " ";
            }
            
            cout << students[i].courses[j].mark << endl;
        }

        cout << endl;

        cout << "Total Mark:   " << students[i].totalMark << endl;
        cout << "Average:      " << students[i].averageMark << endl;
        cout << "Status:       " << students[i].performance << endl;

        cout << endl;
    }

    return 0;
}