//Course.cpp
#include <string>
#include "Course.h"
using namespace std;

Course::Course(){
	id = "";
	name = "";
	credits = 0;
}

Course::Course(string Id, string Name, int Credits){
	id = Id;
	name = Name;
	credits = Credits;
}

string Course::getId(){
	return id;
}

string Course::getName(){
	return name;
}

int Course::getCredits(){
	return credits;
}

void Course::setId(string Id){
	id = Id;
}

void Course::setName(string Name){
	name = Name;
}

void Course::setCredits(int Credits){
	credits = Credits;
} 
