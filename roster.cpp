//
//  roster.cpp
//  Third Attempt
//
//  Created by Noah Koebe on 7/10/21.
//
#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

int classSize = 5;
int daysArr[3];
Student* classRosterArray[5];

Roster::Roster() {
    /*Create a student object for each student */
    for (int i = 0; i < classSize; i++) {
        classRosterArray[i] = new Student();
    };
}


void Roster::parse(const string rStudentData[]) {
    for (int i = 0; i < 5; i++) {
        string the_str = rStudentData[i];
        stringstream s_stream(the_str);
        string token;
        getline(s_stream, token, ',');
        classRosterArray[i]->SetStudentID(token);
        getline(s_stream, token, ',');
        classRosterArray[i]->SetFirstName(token);
        getline(s_stream, token, ',');
        classRosterArray[i]->SetLastName(token);
        getline(s_stream, token, ',');
        classRosterArray[i]->SetEmail(token);
        getline(s_stream, token, ',');
        int ageToken = stoi(token);
        classRosterArray[i]->SetAge(ageToken);
        for (int j = 0; j < 3; j++) {
            getline(s_stream, token, ',');
            daysArr[j] = stoi(token);
        }
        classRosterArray[i]->SetDaysInCourse(daysArr);
        getline(s_stream, token, ',');
        for (int k = 0; k < 3; k++) {
            if (token == degreeProgramStr[k]) {
                classRosterArray[i]->SetDegreeProgram((DegreeProgram)k);
            }
        }
        
    }

    
}

void Roster::add (string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    
    for (int i = 0; i < classSize; i++) {
        int combinedDaysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
        classRosterArray[i] = new Student (studentID, firstName, lastName, email, age, combinedDaysInCourse, degreeProgram);
    }
};

void Roster::remove (string studentID) {
    cout << endl << endl;
    for (int i = 0; i < (classSize+1); i++) {
        if (i == classSize) {
            cout << "ERROR: Student ID: " << studentID << " not found." << endl;
            break;
        }
        if (classRosterArray[i]->GetStudentID() == studentID) {
            cout << "Removing Student ID: " << studentID << endl;
            classSize = classSize-1;
            for (int g = 0; g < 2; g++){
                classRosterArray[(i+g)] = classRosterArray[(i+g+1)];
            }
            
            break;

        }
    }
};

void Roster::printAll() {
    cout << endl << endl << "Displaying all students:" << endl;
    for (int i = 0; i < classSize; i++) {
        classRosterArray[i]->print();
    }
};

void Roster::printAverageDaysInCourse (string studentID) {
    cout << endl;
    float avgDaysInCourse = 0;
    int* classDays[3];
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            
            for (int j = 0; j < 3; j++) {
                classDays[j] = &classRosterArray[i]->GetDaysInCourse()[j];
                avgDaysInCourse = avgDaysInCourse + *classDays[j];
            }
            avgDaysInCourse = (avgDaysInCourse/3);
            cout << "Student ID: " << studentID << ", average days in course is: " << avgDaysInCourse;
            
        }
    }
}

void Roster::printInvalidEmails () {
    cout << endl << "Displaying invalid emails: " << endl << endl;
    for (int i = 0; i < classSize; i++) {
        if ( (classRosterArray[i]->GetEmail()).find('@') == -1) {
            cout << classRosterArray[i]->GetEmail() << " - is invalid." << endl;
        }
        else if ( (classRosterArray[i]->GetEmail()).find('.') == -1) {
            cout << classRosterArray[i]->GetEmail() << " - is invalid." << endl;
        }
        else if ( (classRosterArray[i]->GetEmail()).find(' ') != -1) {
            cout << classRosterArray[i]->GetEmail() << " - is invalid." << endl;
        }
    }
    
};

void Roster::printByDegreeProgram (DegreeProgram degreeProgram) {
    cout << endl << endl << "Showing students in degree Program: " << degreeProgramStr[degreeProgram] << endl << endl;
    for (int i = 0; i < classSize; i++) {
        if ( (classRosterArray[i]->GetDegreeProgram()) == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
};


Roster::~Roster() {
};

