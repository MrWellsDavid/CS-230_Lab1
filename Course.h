//Course.h
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course{
	public:
		Course();
		Course(string Id, string Name, int Credits);
		
		string getId();
		string getName();
		int getCredits();
		
		void setId(string Id);
		void setName(string Name);
		void setCredits(int Credits);
	private:
		string id;
		string name;
		int credits;
};
#endif
