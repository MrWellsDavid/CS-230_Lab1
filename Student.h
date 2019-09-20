//Student.h
#include <string>
#include "Course.h"
using namespace std;

class Student{
	public:
		Student();
		Student(string first, string last, string id);
		
		void print();
		string getId();
		string getFirstName();
		string getLastName();
		Course **getCourses();
		int getCoursesLen();
		
		void setId(string Id);
		void setFirstName(string first);
		void setLastName(string last);
		int addCourse(Course *course);
	private:
		string id;
		string firstName;
		string lastName;
		Course *courses[100];
		int coursesLen;
};
