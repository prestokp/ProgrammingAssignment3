/******************************
   Name
   Date
   PA3_Starter.cpp
   Write a description of the program
********************************/

// Headers
#include <iostream>		// cout, cin
#include <cstdlib>		// exit()
#include <string>		// strings
#include <fstream>		// file processing
#include <iomanip>      // stream manipulation
#include <stdio.h>
using namespace std;

// Global variables
const int MAX_STUDENTS = 25;	// We will not process more than 25 students even if the file contains more
const int MAX_GRADES = 5;		// Each student has exactly 5 grades
const string FILENAME = "NamesGrades.txt";	// The name of the file that you will read

// Function declarations
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents);
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount);
char getLetterGrade(double grade);
int getLongestNameLength(string students[], int studentCount);

int main()
{
    // You will need some variables here
    int numberOfStudents;                           //Variable to hold actual number of students
    string studentNames[MAX_STUDENTS];              //Array variable to hold student names
    int studentGrades[MAX_STUDENTS][MAX_GRADES];    //Array to hold the grades for each student
    int menuChoice;                                 //Variable to hold the integer menu choice

    // Get students and grades

    fstream dataFile; //Creating a file object in an attempt to open the file
    dataFile.open(FILENAME);

    // Loop until user says to quit

    do {

        cout << "Grade Report Program " << endl;
        cout << endl;
        cout << "1: " << "Display Average Grade " << endl;
        cout << "2: " << "Display Maximum Grade " << endl;
        cout << "3: " << "Display Minimum Grade " << endl;
        cout << "4: " << "Exit Program " << endl;
        cout << "Enter your choice (1-4): " << endl;
        cin >> menuChoice;

        while (getchar() != '\n'); //empties the buffer

    // Process the choice
    switch (menuChoice){
        case 1: if (menuChoice == 1){
            displayAverages(studentNames, studentGrades, numberOfStudents);
            break;
        }

        case 2: if (menuChoice == 2){
            //displayMax(studentNames, studentGrades, studentNames);
            break;
        }

        case 3: if (menuChoice == 3){
            displayMin(studentNames, studentGrades, numberOfStudents);
            break;
        }

        case 4: if (menuChoice == 4){
            exit(0);
        }

        default:
            cout << menuChoice << " is not a valid choice. " << endl;
            cout << "Please enter a number 1-4";
            break;

    }//Switch statement delimiter

    //Pause to read the screen and then clear the screen
    if (menuChoice != 4){
        cout << endl;
        system("PAUSE");
        system("CLS");
    }

} while (menuChoice != 4); //Might have to reorder the code here to get a menu choice initialization

    // End of program

    //	Make sure we place the end message on a new line
    cout << "The program has ended" << endl;
    cout << endl;

    return 0;
}

/***********************************************************

loadStudentNameGrades opens and read fileName. It will read in two strings, concatenate them, and then save
to the students array. It then reads five integers and save each to the grades array. The function will return
the actual number of student/grade combinations read
PARAM:	students is an array of strings that can hold up to maxStudents values
		grades is a two dimensional array for holding the grades of each student
		fileName is the name of the file that will be opened and read
		maxStudents is the maximum number of students that we will read from the file
PRE:	students[] is large enough to contain up to maxStudents elements
		grades[] is large enough ot contain up to maxStudents elements
POST:	students[] contains the names of up to maxStudents
		grades[][] contains the grades for up to maxStudents
		The number of student/grade combinations actually read from the file is returned. This value can range
		between 0 <= numStudents <= maxStudents
NOTE:	students[] and grades[] are meant to be parralel arrays. students[0] and grades[0] are the same student

 ************************************************************/

int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents)
{

    return 0;	// for stub out purposes, change this in your code
}

/***********************************************************

displayAverages calculates the average of each student and displays the
students name, average, and letter grade of the average in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, averages, and letter grades is displayed
************************************************************/

void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount)
{
    //Must be a nested for loop because the array from file is a two dimensional array

    int Count; //Counting variable for the outer for loop
    for (Count = 0; Count <= studentCount; Count++){

        //Inner loop definition to average out the score per student
        int count;
        double average, sum = 0;

        for (count = 0; count < MAX_GRADES; count++){
            sum = sum + grades[studentCount][count];
        } //Inner For loop delimiter

        average = sum/MAX_GRADES;
        cout << average;
        cout << setw(25) << assignmentName[0] << ": " << setw(4) << right << grades[0] << endl;
    }//Outer for loop delimiter



}

/***********************************************************

displayMax calculates the maximum grade of each student and displays the
students name, maximum grade, and letter grade of the maximum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, maximum grades, and letter grades is displayed
************************************************************/

void displayMax(string students[], int grades[][MAX_GRADES], int studentCount)

//Bubble sorting achieves the maximum display
//Must be a nested for loop because the array from file is a two dimensional array
{
    int Count; //Counting variable for the outer for loop
    for (Count = 0; Count <= studentCount; Count++) {

        int count; //counting variable for the inner loop
        int highest;
        highest = grades[Count][0];
        for (count = 1; count < MAX_GRADES; count++) {

            if (grades[Count][count] > highest) {
                highest = grades[Count][count];
            }//Conditional Delimiter

        }//Inner for loop delimiter
        cout << setw(25) << assignmentName[0] << ": " << setw(4) << right << grades[0] << endl;
    }//Outer for loop delimiter
}

/***********************************************************

displayMin calculates the minimum grade of each student and displays the
students name, minimum grade, and letter grade of the minimum grade in a table
PARAM:	students[] is an array of strings that contains the names of studentCount students
		grades[] is an array of integers that contains the grades of studentCount students
		studentCount contains the value of the number of elements in the students[] and grades[] arrays
PRE:	students[] and grades[] contain values for studentCount elements
POST:	table of student names, minimum grades, and letter grades is displayed
************************************************************/

void displayMin(string students[], int grades[][MAX_GRADES], int studentCount)

//Bubble sorting achieves the minimum display
//Must be a nested for loop because the array from file is a two dimensional array

{
    int Count; //Counting variable for the outer for loop
    for (Count = 0; Count <= studentCount; Count++) {

        int count;
        int lowest;
        lowest = grades[Count][0];
        for (count = 1; count < MAX_GRADES; count++) {

            if (grades[Count][count] < lowest) {
                lowest = grades[Count][count];
            }//Conditional Delimiter

        }//Inner for loop delimiter
        cout << setw(25) << assignmentName[0] << ": " << setw(4) << right << grades[0] << endl;
    }//Outer for loop delimiter

}

/***********************************************************
getLetterGrade converts a numerical grade to a letter grade
PARAM:	grade is the numerical grade to convert. Expected range is 0 <= grade <= 100
PRE:	grade contains a value in the correct range
POST:	The corresponding letter grade of the numerical grade is returned
************************************************************/

char getLetterGrade(double grade)
{
    char letterGrade; //declares a character variable to hold the letter grade

    //Letter grades are assigned based off of conditional statements and then returns the
    //variable
    if(grade <= 100 && grade >= 90){
        cout << "Your letter Grade is a A";
        letterGrade = 'A';
    }
    else if(grade <= 89 && grade >= 80){
        cout << "Your letter grade is a B";
        letterGrade = 'B';
    }
    else if (grade <= 79 && grade >= 70){
        cout << "Your letter grade is a C";
        letterGrade = 'C';
    }
    else if (grade <= 69 && grade >= 60){
        cout << "Your letter grade is a D";
        letterGrade = 'D';
    }
    else{
        cout << "Your letter grade is an F";
        letterGrade = 'F';
    }

    return letterGrade;
}

/***********************************************************
getLongestNameLength returns the length of the longest string from a list of strings
PARAM:	students[] is an array of strings that contains the name of students
		studentCount is the size of the students[] array
PRE:	students[] contains studentCount names
POST:	The length of the longest string in students[] is returned
************************************************************/

int getLongestNameLength(string students[], int studentCount)

//Bubble sorting achieves the longest string length display
{

    return 0;
}
