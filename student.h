#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "degree.h"
#include <vector> 
using namespace std;

class Student {
	public:
		Student();

		Student(string studentID, string firstName, string lastName, string emailAddress,
				int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

		void SetStudentID(string userID);
		
		string GetStudentID();

		void SetFirstName(string userFirstName);

		string GetFirstName();

		void SetLastName(string userLastName);

		string GetLastName();
		
		void SetEmail(string userEmail);

		string GetEmail();

		void SetAge(int userAge);

		int GetAge();

		void SetCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);

		int GetCourseDays(int indx);

		void SetDegreeProgram(DegreeProgram userDegreeProgram);
		
		DegreeProgram GetDegreeProgram();

		void Print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse1;
		int daysInCourse2;
		int daysInCourse3;
		int courseDays[3];
		DegreeProgram degreeProgram;
};
#endif
