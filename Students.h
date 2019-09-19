//Students.h
#include<iostream>
#include<string>
using namespace std;

class Students{
      public:
             //constructor
          Students();
          Students(string first, string last);
          Students(string first, string last, string i);
          
          //accessors
          void print() const;
          string getName() const;
          string getID() const;

          
          //mutators
          void setName(string first, string last);

          void setID(string);
      private:
              string first_name;
              string last_name;
              string id;

      
      };
