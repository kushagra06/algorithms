#include<iostream>
#include<string>
using namespace std;

class GradeBook
{
    public:
        void displayMessage(string nameOfCourse)
        {
            cout << "Welcome to the grade book for\n" << nameOfCourse << "!"<< endl;
        }
};

int main()
{
    string nameOfCourse;
    GradeBook myGradeBook;
    cout << "\nPlease enter the course name:" << endl;
    getline(cin,nameOfCourse);
    myGradeBook.displayMessage(nameOfCourse);
    return 0;
}
