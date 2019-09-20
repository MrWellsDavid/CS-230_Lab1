#include <iostream>
#include <cstdlib>
#include "Students.h"
#include "Courses.h"

using namespace std;

int addStudents(Students* stuPTR, int counter)
{
    string first, last, id;
    
    int stuNum;
    cout <<"How many students do you want to enter?: ";
    cin >>stuNum;
    for (int i = 0; i < counter; i++)
        stuPTR++;        
        
    for (int i = 0; i < stuNum; i++)
    {
        cout <<"Enter student full name: ";
        cin >>first>>last;
        cout <<"Enter student ID: ";
        cin >>id;

        
        //update the object where you're pointing
        stuPTR ->setName(first, last);
        stuPTR ->setID(id);
        
        
        //move the pointer
        stuPTR++;
        //update the counter
        counter++; 
    }
    
    
    return counter;
}
int addCourses(Courses* corPTR, int counter)
{
    string cName,  courseID;
	int credits;
    
    int corNum;
    cout <<"How many courses do you want to enter?: ";
    cin >>corNum;
    for (int i = 0; i < counter; i++)
        corPTR++;        
        
    for (int i = 0; i < corNum; i++)
    {
        cout <<"Enter Course \n \n";
        cin >>cName;
        cout <<"Enter course ID: \n";
        cin >>courseID;
        cout <<"Enter Credit hours \n";
		cin >>credits;
        
        //update the object where you're pointing
        corPTR ->setCourse(cName);
        corPTR ->setCID(courseID);
        corPTR ->setCredits(credits);
        
        
        //move the pointer
        corPTR++;
        //update the counter
        counter++; 
    }
    
    
    return counter;
}

void printStudents(Students* stuPTR, int counter)
{
     for (int i = 0; i < counter; i++)
     {
         stuPTR -> print();
         stuPTR++;
     }
}


int menu(){
	
	

	    int choice;
    cout <<"\t\tMain Menu\n"
         <<"\t\t=========\n"
         <<"\t\t1. Enter all 4 students in the database \n"
         <<"\t\t2. Enter all 10 courses into the database\n"
         <<"\t\t3. Assign 4 existing courses for an existing student\n"
         <<"\t\t4. Display a report\n"
         <<"\t\t5. EXIT\n"
         <<"\tEnter your choice: ";
    cin >>choice;
    return choice;
	
}

int main(int argc, char *argv[])
{
	
    int option;
    Students stu[4];  //student buffer
    Courses cor[10]; // Course buffer
	int recStudent = 0;  //record counter 
    int recCourse = 0; // course counter
    
    do
    {
        system("CLS");
        option = menu();
        
        switch(option)
        {
                      case 1: recStudent = addStudents(stu, recStudent);
                           break;
                      case 2: recCourse = addCourses(cor, recCourse);
                           break;
                      case 3: 
                           break;
                      case 4:printStudents(stu, recStudent);
                           break;
                      case 5: cout <<"Goobye!\n";
                           break;                           
                      default: cout <<"Invalide choice!\n";
                      
                      
        }
        
        system("PAUSE");
    }while (option != 5);
}
