#include <iostream>
#include "student.h"
#include <string>
#include <vector>
using namespace std;

Student::Student() {
	studentID = -1;
	firstName = "NoFirstName";
	lastName = "NoLastName";
	emailAddress = "NoEmailAddress";
	age = -1;
	int courseDays[3];
	daysInCourse1 = 0;
	daysInCourse2 = 0;
	daysInCourse3 = 0;
	for (int i = 0; i < 3; i++) {
		courseDays[i] = 0;
	}
	degreeProgram = DegreeProgram::DEFAULT;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->courseDays[0] = daysInCourse1;
	this->courseDays[1] = daysInCourse2;
	this->courseDays[2] = daysInCourse3;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

void Student::SetStudentID(string userID) {
	studentID = userID;
}

string Student::GetStudentID() {
	return studentID;
}

void Student::SetFirstName(string userFirstName) {
	firstName = userFirstName;
}

string Student::GetFirstName() {
	return firstName;
}

void Student::SetLastName(string userLastName) {
	lastName = userLastName;
}

string Student::GetLastName() {
	return lastName;
}

void Student::SetEmail(string userEmail) {
	emailAddress = userEmail;
}

string Student::GetEmail() {
	return emailAddress;
}

void Student::SetAge(int userAge) {
	age = userAge;
}

int Student::GetAge() {
	return age;
}
void Student::SetCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse2 = daysInCourse3;

}

int Student::GetCourseDays(int indx) {
	return courseDays[indx];
}

void Student::SetDegreeProgram(DegreeProgram userDegreeProgram) {
	degreeProgram = userDegreeProgram;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

void Student::Print() {
	string degree_string;
	if (degreeProgram == DegreeProgram::SECURITY) {
		degree_string = "SECURITY";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		degree_string = "SOFTWARE";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		degree_string = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::DEFAULT) {
		degree_string = "DEFAULT";
	}
	cout << studentID << "\t First Name: " << firstName << "\t Last Name: " << lastName << "\t Email Address: " << emailAddress << "\t age :";
	cout << age << "\t daysInCourse: {" << daysInCourse1 << ", " << daysInCourse2 << ", " << daysInCourse3 << "}\t Degree Program: " << degree_string << endl;
}