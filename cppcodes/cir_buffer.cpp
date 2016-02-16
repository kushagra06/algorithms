//having problem regarding changing of size and maintaing front and rear
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int N,size=0;
queue<string> buffer;
void append(int n)
{
    if(size>=N)
        size=0;
}
int main()
{
    int n;
    string command;
    cin >> N;
    cin >> command;
    while(command!="Q")
    {
        if(command=="A")
        {
            cin >> n;
            append(n);
        }
        else if(command=="R")
        {
            cin >> n;
            remove(n);
        }
        else if(command=="L")
        {
            list();
        }
        cin >> command;
    }
    return 0;
}
