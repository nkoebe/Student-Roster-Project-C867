//
//  student.h
//  Third Attempt
//
//  Created by Noah Koebe on 7/10/21.
//

#ifndef student_h
#define student_h

#include <stdio.h>
#include "degree.h"
#include <string>

using namespace std;


class Student {
public:
    //Getters - Step D.2.a
    string GetStudentID ();
    string GetFirstName ();
    string GetLastName ();
    string GetEmail ();
    int GetAge ();
    int* GetDaysInCourse ();
    DegreeProgram GetDegreeProgram ();
    
    //Setters - Step D.2.b
    void SetStudentID (string newStudentID);
    void SetFirstName (string newFirstName);
    void SetLastName (string newLastName);
    void SetEmail (string newEmail);
    void SetAge (int newAge);
    void SetDaysInCourse (int* arrDaysInCourse);
    void SetDegreeProgram (DegreeProgram newDegreeProgram);
    
    //print function
    void print();
    
    //Constructor
    Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);
    Student();

    //Destructor
    ~Student();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int *daysInCourse;
    DegreeProgram degreeProgram;

};



#endif /* student_h */
