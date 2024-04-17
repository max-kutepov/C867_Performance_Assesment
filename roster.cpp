#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"
using namespace std;

Roster::Roster()
{
}

Roster::Roster(Student* classArray[5])
{
	classArray = classRosterArray;
}

Roster::~Roster()
{
}

Student* Roster::getClassRosterArrayElement(int index) {
	if (index >= 0 && index < 5) {
		return classRosterArray[index];
	}
	else {
		return nullptr;
	}
}

void Roster::parse(string data){
	size_t commaIndx;
	size_t nextIndx;
	commaIndx = data.find(",");
	string studentID = data.substr(0, commaIndx);
	nextIndx = data.find(",", commaIndx + 1);
	string firstName = data.substr(commaIndx + 1, (nextIndx - commaIndx) - 1);
	commaIndx = data.find(",", nextIndx + 1);
	string lastName = data.substr(nextIndx + 1, (commaIndx - nextIndx) - 1);
	nextIndx = data.find(",", commaIndx + 1);
	string email = data.substr(commaIndx + 1, (nextIndx - commaIndx) - 1);
	commaIndx = data.find(",", nextIndx + 1);
	int age = stoi(data.substr(nextIndx + 1, (commaIndx - nextIndx) - 1));
	nextIndx = data.find(",", commaIndx + 1);
	int daysInCourse1 = stoi(data.substr(commaIndx + 1, (nextIndx - commaIndx) - 1));
	commaIndx = data.find(",", nextIndx + 1);
	int daysInCourse2 = stoi(data.substr(nextIndx + 1, (commaIndx - nextIndx) - 1));
	nextIndx = data.find(",", commaIndx + 1);
	int daysInCourse3 = stoi(data.substr(commaIndx + 1, (nextIndx - commaIndx) - 1));
	commaIndx = data.find(",", nextIndx + 1);
	string strDegree = data.substr(nextIndx + 1, (commaIndx - nextIndx) - 1);
	DegreeProgram degree = DegreeProgram::DEFAULT;
	if (strDegree == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (strDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	else if (strDegree == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}
	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	studentCount++;
	
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeProgram) {
	classRosterArray[++index] = new Student(studentID, firstName, lastName, emailAddress, age,

		daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::remove(string studentID) {
	int i = 0;
	bool foundID = false;
	while (i < studentCount && !foundID) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			foundID = true;
			delete classRosterArray[i]; 
			
			int destIndex = i;
			while (destIndex < studentCount - 1) {
				classRosterArray[destIndex] = classRosterArray[destIndex + 1];
				destIndex++;
			}
			classRosterArray[destIndex] = nullptr;
			studentCount--;
			cout << "Student with ID " << studentID << " removed." << endl;
		}
		i++;
	}
	if (!foundID) {
		cout << "Student with Student ID: " << studentID << ", was not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i ++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int averageDays = 0;
	int i = 0;
	bool foundID = false;
	while (i < 5  && !foundID) {
		if (classRosterArray[i]->Student::GetStudentID() == studentID) {
			for (int c = 0; c < 3; c++) {

				averageDays += classRosterArray[i]->Student::GetCourseDays(c);
			}
			foundID = true;
		}
		i++;
	}
	if (foundID) {
		cout << "Student ID: " << studentID << ", average days in course: " << (averageDays / 3) << endl;
	}
	else {
		cout << "Student ID: " << studentID << " was not found.";
	}
	

}

void Roster::printInvalidEmails() {
	string email;
	for (int i = 0; i < 5; i++) {
		email = classRosterArray[i]->GetEmail();
		if ((email.find("@") == string::npos) || (email.find(".") == string::npos) || (email.find(" ") != string::npos)) {
			cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->Student::GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
}


