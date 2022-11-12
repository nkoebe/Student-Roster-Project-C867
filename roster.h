//
//  roster.h
//  Third Attempt
//
//  Created by Noah Koebe on 7/10/21.
//

#ifndef roster_h
#define roster_h

#include "student.h"
#include <stdio.h>

class Roster {
public:
    //Step E2
    void parse (const string rStudentData[]);
    //Step E3
    void add (string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove (string studentID);
    void printAll();
    void printAverageDaysInCourse (string studentID);
    void printInvalidEmails ();
    void printByDegreeProgram (DegreeProgram degreeProgram);
    
    //Constructor
    Roster();
    
    //Destructor - Roster object is not made dynamically, so code area is empty.
    ~Roster();
    //Create an array of pointers
    Student* classRosterArray[5];
    

};

#endif /* roster_h */
