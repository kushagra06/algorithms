#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
//    cout << time(0) << endl;
    int sum[13]={};
    int x,y,i;
    srand(time(0));
    for(i=0;i<3600;i++)
    {
        x=1+rand()%6;
        y=1+rand()%6;
        sum[x+y]++;
    }
    for(i=2;i<=12;i++)
    {
        cout << i << setw(10) << sum[i];
        cout << endl;
    }

    return 0;
}


