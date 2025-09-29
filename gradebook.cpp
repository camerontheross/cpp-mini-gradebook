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

void showMenu()
{
    cout << "Choose action from the following: \n"
         << "1. Enter a known number of students. (counter)" << "\n"
         << "2. Enter an unknown number of students. (sentinel)" << "\n"
         << "3. Print information about your students."
         << "4. Quit the program" << "\n"
         << "Enter your choice(1 - 4): ";
}

Student createStudent()
{
    double studentGrade; // double to store the student grade
    string studentName;  // string to store the student's name
    Student newStudent;  // student struct that will be returned

    cout << "To add a student, Please enter a name and grade.\n"; // Prompt user
                                                                  // for name
    cin >> studentName; // store student name

    newStudent.name = studentName; // assign user inputted name to new student
    newStudent.classGrade =
        studentGrade; // assign user inputted grade to new student

    return newStudent;
}

int main()
{
    const int COUNTER_CONTROL_CHOICE = 1, SENTINEL_CONTROL_CHOICE = 2,
              PRINT_CHOICE = 3, QUIT_CHOICE = 4;

    int userChoice; // declare variable for user choice

    vector<Student> userClass; // vector to store students

    do
    {
        showMenu();
        cin >> userChoice;

        switch (userChoice)
        {
        case COUNTER_CONTROL_CHOICE:
        case SENTINEL_CONTROL_CHOICE:
        case PRINT_CHOICE:
        case QUIT_CHOICE:
        default:
            cout << "placeholder";
        }

    } while (userChoice != QUIT_CHOICE);

    return 0;
}
