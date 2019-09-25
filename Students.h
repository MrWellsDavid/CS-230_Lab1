//Students.h
#include<iostream>
#include<string>
#include "Courses.h"
using namespace std;

class Students{
      public:
             //constructor
          Students();
          Students(string first, string last);
          Students(string first, string last, string i);
          
          //accessors
          void print();
          string getID() ;
		string getFName();
		string getLName();
	
		Courses **getCourse();
		int getCLength();
          
          //mutators
          void setName(string first, string last);
          void setID(string);
          int addCourse(Courses *corPTR);
      private:
              string first_name;
              string last_name;
              string id;
              Courses *classes[11];
			  int sLength;
			  int cLength;
      
      };
