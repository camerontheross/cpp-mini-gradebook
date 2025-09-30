/*
 * gradebook.cpp
 *  Written By: Cameron Ross
 *  Last Edit : 30 September 2025
 */

#include "Student.h"
#include <ios>
#include <iostream>
#include <limits> // used to clear max input buffer
#include <string>
#include <vector>
using namespace std;

// constants for max and min grades
const double MAX_GRADE = 100, MIN_GRADE = 0;

/*
 *  Purpose :   Clear input
 *  Input   :   None
 *  Process :   Clear cin and ignore anything until enter key was hit
 *  Output  :   None
 */
void clearInput()
{
    cin.clear(); // clears bad input

    // discard characters from buffer
    // uses largest possible number for input buffer
    // stops when it reaches newline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*
 *  Purpose :   take input and validate that it is within range
 *  Input   :   double from cin
 *  Process :   do while loop to take input until a valid value is given
 *  Output  :   returns a double representing the students grade
 */
double getValidGradeFromInput()
{
    double studentGrade; // variable to store user grade
    bool valueInRange;   // flag to check if user has input a valid value

    do
    {
        cout << "Please enter a valid student grade (0 - 100): "; // Prompt for
                                                                  // grade
        cin >> studentGrade; // take input and store
        valueInRange =
            (studentGrade > MIN_GRADE &&
             studentGrade < MAX_GRADE); // checks if student grade is in range

        clearInput(); // clears input after numeric read

        if (!valueInRange)
        {
            // inform user value is out of range
            cout << "ERROR: Invalid value, please enter a number between (0 - "
                    "100).\n";
            cin.clear();
        }
    } while (!valueInRange);
    return studentGrade;
}
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
    string studentName; // string to store the student's name
    Student newStudent; // student struct that will be returned

    cout << "To add a student, Please enter a name and grade.\n";
    cout << "Enter the student's name: "; // Prompt user for name
    getline(cin, studentName);            // get and store student name

    newStudent.name = studentName; // assign user inputted name to new student
    newStudent.classGrade =
        getValidGradeFromInput(); // validate and assign user
                                  // inputted grade to new student

    return newStudent;
}

/*
 *  Purpose :   Enter a fixed number of students into a class
 *  Input   :   vector reference as an argument
 *  Process :   Using a for loop and vector.push_back()
 *  Output  :   None
 */

void counterControlledInput(vector<Student> &studentClass)
{
    Student newStudent;   // a student struct to store user created students
    int numberOfStudents; // stores how many students the user wants to enter
    bool isValidNumberOfStudents; // flag for input validation

    // use a do-while loop to validate input
    do
    {
        // prompt user for to enter a number of students greater than 1
        cout
            << "Enter the number of student(s) you would like to add (at least "
               "1): ";
        // store how many students user wants to enter
        cin >> numberOfStudents;
        clearInput(); // clear input after numeric value entered

        isValidNumberOfStudents = (numberOfStudents >= 1);

        if (!isValidNumberOfStudents)
            cout
                << "ERROR: invalid number of student(s) entered, please ensure "
                   "value of at least 1 is entered.\n";

    } while (!isValidNumberOfStudents);

    // output how many students are being entered for feedback
    cout << "Entering " << numberOfStudents << " student(s).\n";

    for (int i = 1; i <= numberOfStudents; i++)
    {
        newStudent = createStudent(); // use create student function
        studentClass.push_back(
            newStudent); // push new student to back of vector
    }
    // provide user feedback
    // indicate that program will return to the main menu
    cout << numberOfStudents
         << " student(s) successfuly entered. Returning to main menu." << endl;
}

//********************************************************************
//
//  main function
//
//
//
//********************************************************************

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
            counterControlledInput(userClass);
            break;
        case SENTINEL_CONTROL_CHOICE: // case for input = 2
            break;
        case PRINT_CHOICE: // case for input = 3
            break;
        case QUIT_CHOICE: // case for input = 4
            mainLoopActive = false;
            break;
        default: // case for unhandled inputs
            cout << "ERROR: Invalid choice entered." // output to user that
                                                     // input is invalid
                 << "Please enter a valid selection within range (1 - 4)\n";
        }

    } while (mainLoopActive);

    return 0;
}
