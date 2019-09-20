//Student.cpp
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "Student.h"
using namespace std;

Student::Student(){
	id = "";
	firstName = "";
	lastName = "";
	coursesLen = 0;
}

Student::Student(string first, string last, string Id){
	id = Id;
	firstName = first;
	lastName = last;
	coursesLen = 0;
}

void Student::print(){
	cout <<"Student:"
		<<"\n\tId: "<<getId()
		<<"\n\tFirst Name: "<<firstName
		<<"\n\tLast Name: "<<lastName
		<<"\n\tCourses:";
	int credits = 0;
	for(int i = 0; i < coursesLen; i++){
		cout <<"\n\t\t"<<courses[i]->getId()<<": "<<courses[i]->getName();
		credits += courses[i]->getCredits();
	}
	printf("\n\tCredits: %d\n",credits);
}

string Student::getId(){
	return id;
}

string Student::getFirstName(){
	return firstName;
}

string Student::getLastName(){
	return lastName;
}

Course **Student::getCourses(){
	return courses;
}

int Student::getCoursesLen(){
	return coursesLen;
}

void Student::setId(string Id){
	id = Id;
}

void Student::setFirstName(string first){
	firstName = first;
}

void Student::setLastName(string last){
	lastName = last;
}

//returns 1 if not a duplicate id
int Student::addCourse(Course *course){
	for(int i = 0; i < coursesLen; i++)
		if(strcmp(courses[i]->getId().c_str(),course->getId().c_str())==0) 
			return 0;
	courses[coursesLen] = course;
	coursesLen++;
	return 1;
}
