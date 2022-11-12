//
//  student.cpp
//  Third Attempt
//
//  Created by Noah Koebe on 7/10/21.
//

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//Getters
string Student::GetStudentID() {
    return studentID;
};
string Student::GetFirstName() {
    return firstName;
};
string Student::GetLastName() {
    return lastName;
};
string Student::GetEmail() {
    return email;
};
int Student::GetAge() {
    return age;
};
int* Student::GetDaysInCourse() {
    return daysInCourse;
};
DegreeProgram Student::GetDegreeProgram() {
    return degreeProgram;
};

//Setters
void Student::SetStudentID(string newStudentID){
    studentID = newStudentID;
};
void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
};
void Student::SetLastName(string newLastName) {
    lastName = newLastName;
};
void Student::SetEmail(string newEmail) {
    email = newEmail;
};
void Student::SetAge(int newAge) {
    age = newAge;
};
void Student::SetDaysInCourse(int* arrDaysInCourse) {
    for (int i = 0; i < 3; i++) {
        daysInCourse[i] = arrDaysInCourse[i];
    }
};
void Student::SetDegreeProgram(DegreeProgram newDegreeProgram) {
    degreeProgram = newDegreeProgram;
};

//Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysInCourse = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
};

Student::Student() {
    this->studentID = "Unknown";
    this->firstName = "Unknown";
    this->lastName = "Unknow";
    this->email = "Unknown";
    this->age = -1;
    this->daysInCourse = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = -1;
    }
    this->degreeProgram = NETWORK;
};





//print function
void Student::print() {
    cout << GetStudentID() << "     ";
    cout << GetFirstName() << "    " << GetLastName() << "     ";
    cout << GetEmail() << "    ";
    cout << GetAge() << "    ";
    cout << "{";
    for (int i = 0; i < 3; i++) {
        cout << daysInCourse[i];
        if (i < 2) {
            cout << ", ";
        }
    }
    cout << "}   ";
    cout << degreeProgramStr[GetDegreeProgram()] << endl;
};


Student::~Student() {
    
};
