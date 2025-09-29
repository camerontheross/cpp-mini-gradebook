/*  gradebook.cpp
 *  Written By: Cameron Ross
 *  Last Edit : 26 September 2025
 *
 *  Purpose :
 *  Input   :
 *  Process :
 *  Output  :
 */

#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Student createStudent()
{
    double studentGrade; // double to store the student grade
    string studentName;  // string to store the student's name
    Student newStudent;  // student struct that will be returned

    cout << "To add a student, Please enter a name and grade.\n"; // Prompt user
                                                                  // for name
    cin >> studentName; // store student name

    newStudent.name = studentName; // assign user inputted name to new student
    newStudent.classGrade = studentGrade; // assing user inputted grade to new student

    return newStudent;
}

int main()
{
    vector<Student> userClass; // vector to store students

    return 0;
}
