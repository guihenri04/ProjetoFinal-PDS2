#include <iostream>


using namespace std;
#include "Student.hpp"

int main () 
{
    Student sams;
    sams.semesterHours = 3;
    sams.gpa = 3.0;
    sams.addCourse (5, 5.0);

    cout << sams.semesterHours << endl;
    cout << sams.gpa << endl;

    
}