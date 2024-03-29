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
using namespace std;

// Global variables
const int MAX_STUDENTS = 25;	            // We will not process more than 25 students even if the file contains more
const int MAX_GRADES = 5;		            // Each student has exactly 5 grades
const string FILENAME = "NamesGrades.txt";	// The name of the file that you will read

// Function declarations
int loadStudentNamesGrades(string students[], int grades[][MAX_GRADES], string fileName, int maxStudents);
void displayAverages(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMax(string students[], int grades[][MAX_GRADES], int studentCount);
void displayMin(string students[], int grades[][MAX_GRADES], int studentCount);
char getLetterGrade(double grade);
int getLongestNameLength(string students[], int studentCount);
int displayHeading(string reportTitle, string secondColumnName, int secondColumnwidth, int thirdColumnWidth, string students[], int studentCount);

int main()
{
    // You will need some variables here
    int numberOfStudents;                           //Variable to hold actual number of students
    string studentNames[MAX_STUDENTS];              //Array variable to hold student names
    int studentGrades[MAX_STUDENTS][MAX_GRADES];    //Array to hold the grades for each student
    int menuChoice;                                 //Variable to hold the integer menu choice

    // Get students and grades
    try{
        numberOfStudents = loadStudentNamesGrades(studentNames, studentGrades, FILENAME, MAX_STUDENTS);
    }
    catch(const char* errorMessage){
        cout << errorMessage << endl;
        system("PAUSE");
        exit(EXIT_FAILURE);
    }

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
        case 1: //Displays the averages
            displayAverages(studentNames, studentGrades, numberOfStudents);
            break;


        case 2: //Displays the maximum student grade
            displayMax(studentNames, studentGrades, numberOfStudents);
            break;


        case 3: //Displays the minimum student grade
            displayMin(studentNames, studentGrades, numberOfStudents);
            break;


        case 4: //Quits the program
            exit(0);

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

} while (menuChoice != 4);

    //	Make sure we place the end message on a new line
    cout << "The program has ended" << endl;
    cout << endl;

    //system("PAUSE");

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
    ifstream inFile;        //Establishes the input file stream
    string studentNames;    //contains the student names
    string studentGrades;   //contains the student grades
    int numStudents = 0;    //Number of students read in

    //Opening the file
    inFile.open(fileName);

    //Throws an exception if the file cannot be opened
    if(!inFile){
        throw "File failed to open";
    }

    //Looping throw each row to process the data in the file
    for (int i = 0; i < maxStudents && (inFile >> studentNames >> studentGrades); i++, numStudents ++){

        //Linking the student names with their respective grades
        students[i] = studentNames + " " + studentGrades;

        //Loop through all of the student grades in each row
        for (int j = 0; j < MAX_GRADES; j++){
            inFile >> grades[i][j];
        }

    }//Outer for loop delimiter

    //Closing the file
    inFile.close();

    //Testing the output
    /*for (int i = 0; i < numStudents; i++){
        cout << students[i] << " ";

        for (int j = 0; j < MAX_GRADES; j++){
            cout << grades[i][j] << " ";

        }
        cout << endl;
    }*/

    return numStudents;	// for stub out purposes, change this in your code
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
    double average, sum = 0;                                            //Initializes average variable, zeroes inner loop accumulator
    //int maxNameLength = getLongestNameLength(students, studentCount); //Gets the longest name for formatting purposes

    //Setup header table
    int maxLength = displayHeading("Grade Averages", "Average", 4, 10, students, studentCount);

    cout << setprecision(1) << fixed << showpoint;

    //Must be a nested for loop because the array from file is a two dimensional array
    for (int Count = 0; Count < studentCount; Count++){

        //Outputting the student name in each row
        cout << setw(maxLength + 1) << left << students[Count];

        //Inner loop definition to average out the score per student
        for (int count = 0; count < MAX_GRADES; count++){
            sum = sum + grades[Count][count];

        } //Inner For loop delimiter

        average = static_cast<double>(sum)/MAX_GRADES; //Contains the average grade as a double
        char gradeLetter = getLetterGrade(average);     //Passes the average into the LetterGrade function, assigned to a
                                                        //character variable

        cout << setw(8) << right << ": "  << average
            << setw(10) <<  gradeLetter << endl; //formatted display

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
    double highest; //Contains the highest grade per student
    //int maxNameLength = getLongestNameLength(students, studentCount); //Gets the longest name for formatting purposes

    //Setup header table
    int maxLength = displayHeading("Maximum Grade", "Max", 4, 10, students, studentCount);


    for (int Count = 0; Count < studentCount; Count++) {

        //Output the name of the month in the first column
        cout << setw(maxLength + 1) << left << students[Count];
        highest = grades[Count][0];
        for (int count = 1; count < MAX_GRADES; count++) {

            if (grades[Count][count] > highest) {
                highest = grades[Count][count];
            }//Conditional Delimiter

        }//Inner for loop delimiter
        char gradeLetter = getLetterGrade(highest); //Passes the highest grade into the LetterGrade function, assigned to a
                                                    //character variable

        cout << setw(8) << right << ": "  << highest
             << setw(10) <<  gradeLetter << endl; //formatted display

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
    double lowest;                                                    //Holds the lowest grade
    //int maxNameLength = getLongestNameLength(students, studentCount); //Gets the longest name for formatting purposes

    //Setup header table
    int maxLength = displayHeading("Minimum Grade", "Min", 4, 10, students, studentCount);

    for (int Count = 0; Count < studentCount; Count++) {

        //Output name of the month in the first column
        cout << setw(maxLength + 1) << left << students[Count];
        lowest = grades[Count][0];
        for (int count = 1; count < MAX_GRADES; count++) {

            if (grades[Count][count] < lowest) {
                lowest = grades[Count][count];
            }//Conditional Delimiter

        }//Inner for loop delimiter
        char gradeLetter = getLetterGrade(lowest); //Passes the highest grade into the LetterGrade function, assigned to a
                                                    //character variable

        cout << setw(8) << right << ": "  << lowest
             << setw(10) <<  gradeLetter << endl; //formatted display

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
    int maxNameLength = 0; //Holds the longest name count

    for (int i = 0; i < studentCount; i++){
        //Testing to see which names are longer
        if (students[i].length() > maxNameLength){
            maxNameLength = students[i].length();
        }
    }
    return maxNameLength;
}

//This function creates the display header
int displayHeading(string reportTitle, string secondColumnName, int secondColumnwidth, int thirdColumnWidth, string students[], int studentCount){

    int maxNameLength = getLongestNameLength(students, studentCount);
    if (thirdColumnWidth < 10) thirdColumnWidth = 10;

    cout << "\n\n" << reportTitle << "\n";
    cout << setw(maxNameLength + 1) << left << "Student Name"
        << setw(secondColumnwidth) << right << secondColumnName
        << setw(thirdColumnWidth) << "Condition" << endl;

    return maxNameLength;
}
