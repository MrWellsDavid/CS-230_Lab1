//Courses.cpp
#include "Courses.h"

using namespace std;

Courses::Courses(){  //default constructor definition
 
    course_name = "";
    courseID = "";
    course_cred = 0;
   
}



Courses::Courses(string cName, string cID, int credits){
    course_name = cName;
    courseID = cID;
    course_cred = 3;
}
//accessors
void Courses::print()const{
     cout <<"Course information\n"
          <<"===================\n"
          <<"Course: "<<course_name<<" "
		  <<"Course credits: "<<course_cred<<"\n"
          <<"Course ID: "<<courseID<<"\n";
          
}

//mutators
void Courses::setCourse(string cName, int credits){
     course_name = cName;
     course_cred = credits;
}
 
 
 void Courses::setID(string cID)
 {
      courseID = "CS-" + cID;
 }
