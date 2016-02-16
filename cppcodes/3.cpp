#include<iostream>
#include<string>
using namespace std;

class GradeBook
{
    public:
        GradeBook(string name)
        {
            setCourseName(name);
        }
        void setCourseName(string name)
        {
            courseName=name;
        }
        string getCourseName()
        {
            return courseName;
        }
        void displayMessage()
        {
            cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
        }
    private:
        string courseName;
};

int main()
{
    string nameOfCourse;
    GradeBook myGradeBook("CS 101 Intro to CS");
    cout << "Initial course name is\n" << myGradeBook.getCourseName()<< endl;
    cout << "\nPlese enter the course name: " << endl;
    getline(cin,nameOfCourse);
    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;
    myGradeBook.displayMessage();
    return 0;
}


