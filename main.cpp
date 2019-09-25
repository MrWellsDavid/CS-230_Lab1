#include <iostream>
#include <cstdlib>
#include "Students.h"
#include "Courses.h"

using namespace std;

int findCourse(Courses* corPTR, int cLength, string courseID){
	for(int i = 0; i < cLength; i++){
		if((corPTR+i)->getCourseID().compare(courseID)==0)
			return i;
	}
	return cLength;
}

int findStudent(Students* stuPTR, int sLength, string id){
	for(int i = 0; i < sLength; i++){
		if((stuPTR+i)->getID().compare(id)==0)
			return i;
	}
	return sLength;
}

int addStudents(Students* stuPTR, int sLength)
{
    string first, last, id;
    
    int stuNum;
    cout <<"How many students do you want to enter?: ";
    cin >>stuNum;
    for (int i = 0; i < sLength; i++)
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
        sLength++; 
    }
    
    
    return sLength;
}
int addCourses(Courses* corPTR, int cLength)
{
    string cName,  courseID;
	int credits;
    
    int corNum;
    cout <<"How many courses do you want to enter?: ";
    cin >>corNum;
    for (int i = 0; i < cLength; i++)
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
        cLength++; 
    }
    
    
    return cLength;
}
void assignCourses(Students* stuPTR, Courses* classes, int sLength, int cLength){
	if(sLength < 4){
		cout <<"\nplease assign students and courses # \n\n";
	}else if(cLength < 10){
		cout <<"\nEnter please assign courses for the students #\n\n";
	}else{
		string tempid;
		int studentLoc;
		cout <<"Enter the Student Id \n\n";
		do{
			getline(cin,tempid);
			studentLoc = findStudent(stuPTR, sLength,tempid);
			if(studentLoc==sLength)
				cout <<"Id not found! Try again.\n";
		}while(studentLoc==sLength);
		stuPTR += studentLoc;
		cout <<"Enter # of courses";
		int min = max(0,4-stuPTR->getCLength());
		printf(" (Minimum %d)\n",min);
		int inputLen = -1;
		do{
			int e = scanf("%d",&inputLen);
			getchar();
			if(e==0||inputLen<min)
				cout <<"Please try again \n\n";
		}while(inputLen<min);
		for(int i = 0; i < inputLen; i++){
			int courseLoc;
			cout <<"Enter Course Id\n\n";
			do{
				getline(cin,tempid);
				courseLoc = findCourse(classes, cLength,tempid);
				if(courseLoc==cLength)
					cout <<"Invalid ID \n";
				else if(stuPTR->addCourse(classes+courseLoc)==0){
					cout <<"Student already assigned that course \n\n";
				}else break;
			}while(true);
		}
	}
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
    Students stuPTR[4];  //student buffer
    Courses classes[10]; // Course buffer
	int sLength = 0;  //record counter 
    int cLength = 0; // course counter
    
    do
    {
        system("CLS");
        option = menu();
        
        switch(option)
        {
                      case 1: sLength = addStudents(stuPTR, sLength);
                           break;
                      case 2: cLength = addCourses(classes, cLength);
                           break;
                      case 3: assignCourses(stuPTR,classes,sLength,cLength);
                           break;
                      case 4:printStudents(stuPTR, sLength);
                           break;
                      case 5: cout <<"Goobye!\n";
                           break;                           
                      default: cout <<"Invalide choice!\n";
                      
                      
        }
        
        system("PAUSE");
    }while (option != 5);
}
