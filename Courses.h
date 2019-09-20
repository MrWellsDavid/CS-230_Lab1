//Courses.h
#include<iostream>
#include<string>
using namespace std;

class Courses{
      public:
             //constructor
          Courses();
          Courses(string cName);
          Courses(string cName, string cID);
          Courses(string cName, string cID, int credits);
          
          //accessors
          void print() const;
          string getCourse() const;
          string getCourseID() const;

          
          //mutators
          void setCourse(string cName);
          void setCID(string cID);
          void setCredits(int credits);
        

      private:
              string course_name;
              string courseID;
              int course_cred;
      
      };
