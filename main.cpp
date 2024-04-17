#include <iostream>
#include "roster.h"
#include "student.h"
#include <string>
#include <vector>
using namespace std;

//int STUDENT_SIZE = 5;

int main() {

	cout << "Scripting and Programing: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 011367017" << endl;
	cout << "Name: Maxim Kutepov" << endl << endl;
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Maxim,Kutepov,mkutepo@wgu.edu,18,17,27,37,SOFTWARE" };

	;
	
	Student* classRosterArray[5];
	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	cout << "Displaying all Students:" << endl;

	classRoster.printAll();

	cout << endl;

	cout << "Displaying Invalid Emails:" << endl;
	cout << endl;

	classRoster.printInvalidEmails();

	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;

	for (int i = 0; i < 5; i++) {
		string id = classRoster.getClassRosterArrayElement(i)->GetStudentID();
		classRoster.printAverageDaysInCourse(id);
	}

	cout << endl << "Removing 'A3'" << endl;

	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();

	cout << endl;

	cout << "Removing A3 again." << endl;

	classRoster.remove("A3");

	cout << endl;



	cout << "DONE";
	for (int i = 0; i < 5; i++) {
		delete classRoster.getClassRosterArrayElement(i);
	}
	



	return 0;
}

    

  