#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double e=2;
    double j=1;
    for(int i=1;i<n-1;i++)
    {
        j=j*(i+1);
        e+=1/j;
    }
    if(n==1)
        cout << "1\n";
    else
        cout << e << endl;
    return 0;
}

