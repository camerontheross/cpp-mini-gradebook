/*
 * gradebook.cpp
 *  Written By: Cameron Ross
 *  Last Edit : 26 September 2025
 */

#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 *  Purpose :   output the main menu options
 *  Input   :   none
 *  Process :   cout menu options
 *  Output  :   menu options
 */
void showMenu()
{
    // output the menu options to terminal
    cout << "Choose action from the following: \n"
         << "1. Enter a known number of students. (counter)" << "\n"
         << "2. Enter an unknown number of students. (sentinel)" << "\n"
         << "3. Print information about your students."
         << "4. Quit the program" << "\n"
         << "Enter your choice(1 - 4): ";
}
/*
 *  Purpose :   Create and return a new student struct
 *  Input   :   none
 *  Process :   take input, validate and pass values to Student struct
 *  Output  :   returns a student onbject
 */
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
              PRINT_CHOICE = 3,
              QUIT_CHOICE = 4; // integers to represent menu selections

    bool mainLoopActive = true; // declare sentinel for main loop
    int userChoice;             // declare variable for user choice

    vector<Student> userClass; // vector to store students

    do
    {
        showMenu(); // call the method to print the menu
        cin >> userChoice;

        switch (userChoice)
        {
        case COUNTER_CONTROL_CHOICE: // case for input = 1
            break;
        case SENTINEL_CONTROL_CHOICE: // case for input = 2
            break;
        case PRINT_CHOICE: // case for input = 3
            break;
        case QUIT_CHOICE: // case for input = 4
            mainLoopActive = false;
            break;
        default:                              // case for unhandled inputs
            cout << "Invalid choice entered." // output to user that input is
                                              // invalid
                 << "Please enter a valid selection within range (1 - 3)";
        }

    } while (mainLoopActive);

    return 0;
}
