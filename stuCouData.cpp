#include <iostream>
#include <string.h>
#include "Student.h"
#include "Course.h"

//returns the location of the object with the id and if it isnt found returns the length of the list
int findCourse(Course* courses, int coursesLen, string id){
	for(int i = 0; i < coursesLen; i++){
		if((courses+i)->getId().compare(id)==0)
			return i;
	}
	return coursesLen;
}

int findStudent(Student* students, int studentsLen, string id){
	for(int i = 0; i < studentsLen; i++){
		if((students+i)->getId().compare(id)==0)
			return i;
	}
	return studentsLen;
}

int addStudents(Student* students, int studentsLen){
	cout <<"How many students are being entered?";
	int min = max(0,4-studentsLen);
	printf(" (Minimum %d)\n",min);
	int inputLen = -1;
	do{
		int e = scanf("%d",&inputLen);
		if(e==0||inputLen<min)
			cout <<"Incorrect input! Try again.\n";
		getchar();
	}while(inputLen<min);
	for(int i = 0; i < inputLen; i++){
		string id;
		string firstName;
		string lastName;
		cout <<"\nEnter Student's Id.\n";
		while(true){
			getline(cin,id);
			if(findStudent(students,studentsLen,id)!=studentsLen)
				cout <<"A Student already has that Id! Try again.\n";
			else break;
		}
		cout <<"Enter Student's First Name.\n";
		getline(cin,firstName);
		cout <<"Enter Student's Last Name.\n";
		getline(cin,lastName);
		*(students+studentsLen) = Student(firstName,lastName,id);
		studentsLen++;
	}
	return studentsLen;
}

int addCourses(Course* courses, int coursesLen){
	cout <<"How many courses are being entered?";
	int min = max(0,10-coursesLen);
	printf(" (Minimum %d)\n",min);
	int inputLen = -1;
	do{
		int e = scanf("%d",&inputLen);
		if(e==0||inputLen<min)
			cout <<"Incorrect input! Try again.\n";
		getchar();
	}while(inputLen<min);
	for(int i = 0; i < inputLen; i++){
		string id;
		string name;
		int credits = -1;
		cout <<"\nEnter Course's Id.\n";
		while(true){
			getline(cin,id);
			if(findCourse(courses,coursesLen,id)!=coursesLen)
				cout <<"A Course already has that Id! Try again.\n";
			else break;
		}
		cout <<"Enter Course's Name.\n";
		getline(cin,name);
		cout <<"Enter Course's Credits.\n";
		do{
			int e = scanf("%d",&credits);
			if(e==0||credits<0)
				cout <<"Incorrect input! Try again.\n";
			getchar();
		}while(credits<0);
		*(courses+coursesLen) = Course(id,name,credits);
		coursesLen++;
	}
	return coursesLen;
}

void assignCourses(Student* students, Course* courses, int studentsLen, int coursesLen){
	if(studentsLen < 4){
		cout <<"\nNot enough students!\n";
	}else if(coursesLen < 10){
		cout <<"\nNot enough courses!\n";
	}else{
		string tempid;
		int studentLoc;
		cout <<"Enter the Student's Id.\n";
		do{
			getline(cin,tempid);
			studentLoc = findStudent(students, studentsLen,tempid);
			if(studentLoc==studentsLen)
				cout <<"Id not found! Try again.\n";
		}while(studentLoc==studentsLen);
		students += studentLoc;
		cout <<"How many courses are being assigned?";
		int min = max(0,4-students->getCoursesLen());
		printf(" (Minimum %d)\n",min);
		int inputLen = -1;
		do{
			int e = scanf("%d",&inputLen);
			if(e==0||inputLen<min)
				cout <<"Incorrect input! Try again.\n";
			getchar();
		}while(inputLen<min);
		for(int i = 0; i < inputLen; i++){
			int courseLoc;
			cout <<"Enter the Course's Id.\n";
			do{
				getline(cin,tempid);
				courseLoc = findCourse(courses, coursesLen,tempid);
				if(courseLoc==coursesLen)
					cout <<"Id not found! Try again.\n";
				else if(students->addCourse(courses+courseLoc)==0){
					cout <<"Student already has that course! Try again.\n";
				}else return;
			}while(true);
		}
	}
}

//prints all students sequentially
void report(Student* students, int studentsLen, int coursesLen){
	for(int i = 0; i < studentsLen; i++){
		students->print();
		students++;
	}
}

int menu(){
	cout <<"\nMenu:\n"
		<<"1: Add students\n"
		<<"2: Add courses\n"
		<<"3: Assign courses\n"
		<<"4: Print report\n"
		<<"5: EXIT\n";
	int result = -1;
	while(result<0||result>5){
		int e = scanf("%d",&result);
		if(e==0||result<0||result>5){
			cout <<"Invalid option! Try again.\n";
			getchar();
		}else return result;
	}
}

int main(int argc, char** argv) {
	Student students[100];
	Course courses[100];
	int studentsLen = 0;
	int coursesLen = 0;
	int option;
	do{
		option = menu();
		switch(option){
			case 1:
				studentsLen = addStudents(students,studentsLen);
				break;
			case 2:
				coursesLen = addCourses(courses,coursesLen);
				break;
			case 3:
				assignCourses(students,courses,studentsLen,coursesLen);
				break;
			case 4:
				report(students,studentsLen,coursesLen);
				break;
			case 5:
				cout <<"Cya";
				break;
		}
	}while(option != 5);
	return 0;
}
