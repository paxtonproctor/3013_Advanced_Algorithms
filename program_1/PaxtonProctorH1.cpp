/****************************************************
*
* Student: Paxton Proctor
* Instructor: Dr. Colmeneras
* Class: CMPS 3013 Advance Algorithms
* Assignment: Program 1 STL Container Linked list
*
* Purpose: Create a link list container
*
****************************************************/
#include<iostream>
#include<fstream>
#include<list>// List header
#include<iomanip>
// With STL List we can insert elements within the list more quickly than the
// vectors can because the lists do not have to shift the other elements. List
// are also efficient at adding elements at their back because they have a
// a buit-in pointer to the last element in the list(no traversal required).

using namespace std;

// Structure for creating a student
struct Student {
	string Firstname, Lastname;
	char Gender;
	int Age, Id;
};

// function prototypes
void Addstudent();
void populateList();
void Menu(ofstream& outfile);
void displayListfiles(ofstream& outfile);
void RemoveHead(ofstream& outfile);
void RemoveTail(ofstream& outfile);
void displayListnames(ofstream& outfile);



// Creates a new linked list and is a container for students
list<Student> newStudent;

// main
int main() {

	ofstream outfile;
	// opens files
	cout << "filename must be text.txt\n";
	outfile.open("text.txt");

	outfile << fixed << setprecision(2) << "Student: Paxton Proctor\n";
	outfile << "-------------------------\n";
	// calls menu
	Menu(outfile);
	// closes files
	outfile.close();
	return 0;
}
/************************************************************************
* Purpose: A menu to call functions by user input                       *
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void Menu(ofstream& outfile) {
	char choice = 'z';
	while (choice != 'Q' && choice != 'q') {
		cout << "Type W to populateList\n" <<
			"Type S to show student information\n" <<
			"Type R to remove head\n" <<
			"Type T to remove tail\n" <<
			"Type Y to show student names only\n" <<
			"Type U to Add another student\n"
			"Type Q to exit the menu\n";
		cin >> choice;
		//to populate list
		if (choice == 'W' || choice == 'w') {
			populateList();
		}
		//Shows student information
		else if (choice == 'S' || choice == 's') {
			displayListfiles(outfile);
		}
		//remove head
		else if (choice == 'R' || choice == 'r') {
			RemoveHead(outfile);
		}
		//remove tail
		else if (choice == 'T' || choice == 't') {
			RemoveTail(outfile);
		}
		//Shows student name only 
		else if (choice == 'Y' || choice == 'y') {
			displayListnames(outfile);
		}
		//add student
		else if (choice == 'U' || choice == 'u') {
			Addstudent();
		}
		else {
			cout << "This is not a valid character" <<
				"please try again\n";
		}
	}
}
/************************************************************************
* Purpose: To fill the container with students                          *
* Recieves: nothing                                                     *
* Returns: nothing                                                      *
************************************************************************/
void populateList() {
	// bool to make sure we can break the while loop
	bool working = true;

	// loop for populating list by asking users questions about info
	while (working) {
		// initializing variables
		string firstName, lastName;
		char Gender;
		int Age, Id;

		// asking users questions about info
		cout << "Enter Students First and last name\n";
		cin >> firstName;
		cin >> lastName;
		cout << "for gender type M for male or F for female\n";
		cin >> Gender;
		cout << "Enter Student age\n";
		cin >> Age;
		cout << "Enter the Student Id number\n";
		cin >> Id;

		// pass student into list
		newStudent.push_back({ firstName,lastName,Gender,Age,Id });

		// ask user to see if they want more students
		cout << "do you want to add another student?\n";
		cout << "Y for Yes or N for No\n";
		char Answer;
		cin >> Answer;
		// exits the function
		if (Answer != 'Y' && Answer != 'y') {
			break;
		}
	}
}
/************************************************************************
* Purpose: prints the nodes of students first,last and Id               *
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void displayListfiles(ofstream& outfile) {
	// stl container allows us to start from the beginning and go to the
	// end or tail.
	list<Student>::iterator Node;
	Node = newStudent.begin();

	// if empty print container empty else loop through list and 
	// print the first, last and Id of the student.
	if (newStudent.empty()) {
		cout << "The container has no students currently.\n";
		outfile << "The container has no students currently.\n";
	}
	else {
		while (Node != newStudent.end()) {
			cout << Node->Firstname << " "
				<< Node->Lastname << "- id:" << Node->Id << '\n';
			outfile << Node->Firstname << " "
				<< Node->Lastname << "- id:" << Node->Id << '\n';
			Node++;
		}// end of while
		outfile << "------------------------------\n";
	}
}// end of function
/************************************************************************
* Purpose: removes the head                                             *
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void RemoveHead(ofstream& outfile)
{
	//removing the node at the head
	if (newStudent.empty())
		outfile << "The List Container is Currently Empty" << "\n";
	else
	{
		// stl container operator
		newStudent.pop_front();
		outfile << "After Removing from the Head \n";
	}

}// end of function
/************************************************************************
* Purpose: removes the tail                                             *
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void RemoveTail(ofstream& outfile)
{
	//removing the node at the tail
	if (newStudent.empty())
		outfile << "The List Container is Currently Empty" << "\n";
	else
	{
		// stl container operator
		newStudent.pop_back();
		outfile << "After Removing from the tail \n";
	}

}// end of function
/************************************************************************
* Purpose: adds a student to the tail                                   *
* Recieves: nothing                                                     *
* Returns: nothing                                                      *
************************************************************************/
void Addstudent() {
	// input the number students
	int num;
	cout << "how many students do you want to add?\n";
	cin >> num;

	// start of while loop
	while (num > 0) {
		// initializing variables
		string firstName, lastName;
		char Gender;
		int Age, Id;

		// asking user for info
		cout << "Enter Students First and last name\n";
		cin >> firstName;
		cin >> lastName;
		cout << "for gender type M for male or F for female\n";
		cin >> Gender;
		cout << "Enter Student age\n";
		cin >> Age;
		cout << "Enter the Student Id number\n";
		cin >> Id;

		// pass student into list
		newStudent.push_back({ firstName,lastName,Gender,Age,Id });
		num--;
	}// end of while
}// end of function
/************************************************************************
* Purpose: prints only the names of each student in container           *
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void displayListnames(ofstream& outfile) {
	// stl container allows us to start from the beginning and go to the
	// end or tail.
	list<Student>::iterator Node;
	Node = newStudent.begin();

	// if empty print container empty else loop through list and print name
	if (newStudent.empty()) {
		cout << "The container has no students currently.\n";
		outfile << "The container has no students currently.\n";
	}
	else {
		while (Node != newStudent.end()) {
			cout << Node->Firstname << '\n';
			outfile << Node->Firstname << '\n';
			Node++;
		}// end of while
		outfile << "------------------------------\n";
	}
}// end of function