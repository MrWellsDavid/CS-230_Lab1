//Courses.cpp
#include <string>
#include "Courses.h"

using namespace std;



Courses::Courses(){  //default constructor definition
 
    course_name = "";
    courseID = "";
    course_cred = 0;
    cLength = 0;
   
}


Courses::Courses(string cName, string cID, int credits){
    course_name = cName;
    courseID = cID;
    course_cred = 3;
    cLength = 0;
}
//accessors
void Courses::print(){
     cout <<"Course information\n"
          <<"===================\n"
          <<"Course: "<<course_name<<" "
		  <<"Course credits: "<<course_cred<<"\n"
          <<"Course ID: "<<courseID<<"\n";
          
}
string Courses::getCourseID(){
	return courseID;
} 
//mutators
void Courses::setCourse(string cName){
     course_name = cName;
 
}
void Courses::setCredits(int credits){
	course_cred= credits;
}
 
void Courses::setCID(string cID)
 {
      courseID = "CS-" + cID;
 }
