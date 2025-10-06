/*
 * gradebook.cpp
 * Written By: Cameron Ross
 * Last Edit : 6 October 2025
 */

#include "Student.h"
#include <iomanip>
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
 *  Process :   Clear cin and ignore anything until enter key was pressed
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
		    (studentGrade >= MIN_GRADE &&
		     studentGrade <= MAX_GRADE); // checks if student grade is in range

		clearInput(); // clears input after numeric read

		if (!valueInRange)
		{
			// inform user value is out of range
			cout << "\nERROR: Invalid value,"
			     << "please enter a number between (0 - 100).\n";
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

	cout << "\n\nChoose action from the following: \n"
	     << "1. Enter a known number of students. (counter)" << "\n"
	     << "2. Enter an unknown number of students. (sentinel)" << "\n"
	     << "3. Print information about your students.\n"
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
		cout << "Enter the number of student(s) you would like to add (at least "
		        "1): ";
		// store how many students user wants to enter
		cin >> numberOfStudents;
		clearInput(); // clear input after numeric value entered

		isValidNumberOfStudents = (numberOfStudents >= 1);

		if (!isValidNumberOfStudents)
			cout << "\nERROR: invalid number of student(s) entered, please ensure "
			        "value of at least 1 is entered.\n";

	} while (!isValidNumberOfStudents);

	// output how many students are being entered for feedback
	cout << "Entering " << numberOfStudents << " student(s).\n";

	for (int i = 1; i <= numberOfStudents; i++)
	{
		newStudent = createStudent();       // use create student function
		studentClass.push_back(newStudent); // push new student to back of vector
	}
	// provide user feedback
	// indicate that program will return to the main menu
	cout << numberOfStudents
	     << " student(s) successfuly entered. Returning to main menu.";
}
/*
 *  Purpose :   Enter an unknown number of students into a class
 *  Input   :   vector reference as an argument
 *  Process :   Using a while loop, createStudent() and vector.push_back()
 *  Output  :   None
 */

void sentinelConrolledInput(vector<Student> &studentClass)
{
	const string TERMINATOR = "STOP"; // value the sentinel watches for
	bool terminate = false;           // flag for when terminator is entered
	string
	    userInuput; // stores user input to compare against the terminator string
	Student newStudent; // Student struct to store the user's new student

	while (!terminate)
	{
		cout << "\nPress ENTER to continue, or enter 'STOP' to exit. "; // prompt
		                                                                // user to
		                                                                // continue
		getline(cin, userInuput); // store user input

		if (userInuput == TERMINATOR) // check if the input is the terminator string
		{
			terminate = true; // set flag to true
			break;            // break out of the loop
		}
		newStudent = createStudent();
		studentClass.push_back(newStudent);
	}
}

/*
 *  Purpose :  Allow the user to print info about the gradebook
 *  Input   :  student vector as an argument
 *  Process :  Check if the student gradebook has more than one student,
 *              parse vector for high, low and average grades
 *  Output  :  prints error if vector is empty, or calculated high, low and
 *              average grades. Also lists of who passed and who failed
 */
void printGradebook(vector<Student> &gradebook)
{
	// use the size of the gradebook to calculate how many students are in a class
	int numberOfStudents = gradebook.size();

	// prevents division by zero
	// also prevents printing anything about an empty gradebook
	if (numberOfStudents < 1)
	{
		cout << "\nGradebook needs at least one student to print high, low and "
		        "average grades.\n"
		     << "Please populate gradebook with at least one student and try again."
		     << endl;
		return; // return early to prevent the rest of the code from executing
	}

	double averageGrade = 0; // double to store the average class grade
	// student structs to store the current, highest scoring and lowest scorers
	Student currentStudent, highestScoring, lowestScoring;
	// student vectors to track who passed and who failed
	vector<Student> passed, failed;

	// initialize high and low scores to outside of bounds
	// this ensures they will be reassigned properly
	highestScoring.classGrade = -1;
	lowestScoring.classGrade = 101;

	for (int i = 0; i < numberOfStudents; i++)
	{
		currentStudent = gradebook[i];

		// if current student has the highest score
		if (currentStudent.classGrade > highestScoring.classGrade)
		{
			highestScoring = currentStudent; // update the highest scoring student
		}

		// if current student has the lowest score
		if (currentStudent.classGrade < lowestScoring.classGrade)
		{
			lowestScoring = currentStudent; // update the lowest scoring student
		}

		// if the student's grade is 60 or less, add them to the failed vector
		if (currentStudent.classGrade <= 60)
		{
			failed.push_back(currentStudent);
		}
		else // otherwise add them to the passed vector
		{
			passed.push_back(currentStudent);
		}

		// running total for averageGrade
		averageGrade += currentStudent.classGrade;
	}
	// divide total grades by number of students to calculate average
	averageGrade /= numberOfStudents;

	// print info to user
	cout << showpoint << setprecision(2) << fixed; // format output
	cout << "\nThe class grade average is: " << averageGrade
	     << "\nThe highest scoring student in the class was: "
	     << highestScoring.name
	     << " with a grade of: " << highestScoring.classGrade
	     << "\nThe lowest scoring student in the class was: "
	     << lowestScoring.name
	     << " with a grade of: " << lowestScoring.classGrade;

	// output passing students
	cout << "\nThe following students passed the class (scored at least 61%): \n";
	for (int i = 0; i < passed.size(); i++)
	{
		currentStudent = passed[i];
		cout << "\n\t" << currentStudent.name << "\t\t" << currentStudent.classGrade
		     << "%";
	}

	// output failing students
	cout << "\nThe following students failed the class (scored 60% or lower): \n";
	for (int i = 0; i < failed.size(); i++)
	{
		currentStudent = failed[i];
		cout << "\n\t" << currentStudent.name << "\t\t" << currentStudent.classGrade
		     << "%";
	}
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

		cout << "\n---------------------------------------------\n";
		showMenu(); // call the method to print the menu
		cin >> userChoice;
		clearInput(); // clear input

		cout << "\n---------------------------------------------\n";
		switch (userChoice)
		{
		case COUNTER_CONTROL_CHOICE: // case for input = 1
			counterControlledInput(userClass);
			break;
		case SENTINEL_CONTROL_CHOICE: // case for input = 2
			sentinelConrolledInput(userClass);
			break;
		case PRINT_CHOICE: // case for input = 3
			printGradebook(userClass);
			break;
		case QUIT_CHOICE: // case for input = 4
			mainLoopActive = false;
			break;
		default:                                   // case for unhandled inputs
			cout << "ERROR: Invalid choice entered." // output to user that
			                                         // input is invalid
			     << "Please enter a valid selection within range (1 - 4)\n";
		}

	} while (mainLoopActive);

	return 0;
}
