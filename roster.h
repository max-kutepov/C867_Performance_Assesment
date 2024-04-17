#include <iostream>
#include "student.h"
#include <vector>
using namespace std;

class Roster {
	public:
		Roster();
		Roster(Student* classRosterArray[5]);
		~Roster();

		void add(string studentID, string firstName, string lastName, string emailAddress,
			int age, int daysInCourse1, int daysInCourse2,int daysInCourse3,
			DegreeProgram degreeProgram);

		Student* getClassRosterArrayElement(int index);

		void remove(string studentID);

		void printAll();

		void printAverageDaysInCourse(string studentID);

		void printInvalidEmails();

		void printByDegreeProgram(DegreeProgram degreeProgram);
		void parse(string dataString);

		

	private:
		Student* classRosterArray[5];
		int studentCount = 0;
		int index = -1;
};
