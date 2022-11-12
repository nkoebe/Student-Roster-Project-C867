//
//  main.cpp
//  Third Attempt
//
//  Created by Noah Koebe on 7/10/21.
//

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;


int main() {
    /*Add own info to Student Data Table*/
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Noah,Koebe,nkoebe@wgu.edu,28,25,29,45,SOFTWARE"};
    
    /*Print out course and project info*/
    cout << "Course Title: C867 - Scripting and Programming - Applications" << endl;
    cout << "Language Used: C++" << endl;
    cout << "WGU Student ID: " << endl;
    cout << "Name: Noah Koebe" << endl << endl;
    
    //Demonstrate functionality
    Roster classRoster;
    classRoster.parse(studentData);
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (int d = 0; d < 5; d++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[d]->GetStudentID());
    };
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    cout << endl << "DONE." << endl;

};

