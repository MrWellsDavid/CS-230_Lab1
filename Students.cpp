//Students.cpp
#include <string.h>
#include <iostream>
#include <stdio.h>
#include"Students.h"
//constructors
Students::Students()  //default constructor definition
{ 
    first_name = "";
    last_name = "";
    id = "";
    sLength=0;
}

Students::Students(string first, string last)//overloaded constructor definition
{ 
    first_name = first;
    last_name = last;
    id = "";
    sLength=0;
  
                        }

Students::Students(string first, string last, string i)
{
    first_name = first;
    last_name = last;
    id = i;
    }
//accessors
string Students::getFName(){
	return first_name;
}

string Students::getLName(){
	return last_name;
}
string Students::getID(){
	return id;
}

void Students::print() 
{
     cout <<"Student information\n"
          <<"===================\n"
          <<"Full Name: "<<first_name<<" "<<last_name<<"\n"
          <<"Student ID: "<<id<<"\n";
          
                 }

Courses **Students::getCourse(){
	return classes;
}

int Students::getCLength(){
	return cLength;
}


//mutators
void Students::setName(string first, string last)
{
     first_name = first;
     last_name = last;
}
 

 void Students::setID(string i)
 {
      id = "CTU-" + i;
 }
 int Students::addCourse(Courses *corPTR){
	for(int i = 0; i < cLength; i++)
		if(strcmp(classes[i]->getCourseID().c_str(),corPTR->getCourseID().c_str())==0) 
			return 0;
	classes[cLength] = corPTR;
	cLength++;
	return 1;
}
