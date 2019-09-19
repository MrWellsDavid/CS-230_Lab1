//Students.cpp
#include"Students.h"
//constructors
Students::Students()  //default constructor definition
{ 
    first_name = "";
    last_name = "";
    id = "";
   
                    }

Students::Students(string first, string last)//overloaded constructor definition
{ 
    first_name = first;
    last_name = last;
    id = "";
  
                        }

Students::Students(string first, string last, string i)
{
    first_name = first;
    last_name = last;
    id = i;
    }
//accessors
void Students::print() const
{
     cout <<"Student information\n"
          <<"===================\n"
          <<"Full Name: "<<first_name<<" "<<last_name<<"\n"
          <<"Student ID: "<<id<<"\n";
          
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
