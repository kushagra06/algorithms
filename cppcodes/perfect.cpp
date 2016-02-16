#include<iostream>
using namespace std;

void isPerfect(int x)
{

    int a[10000];
    int j=0,sum=0;
    for(int i=1;i<=x/2;i++)
    {
        if(x%i==0)
        {
            a[j++]=i;
            sum+=i;
        }
    }
    if(sum==x)
    {
        cout << x << endl;
        for(int i=0;i<j;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    for(int i=1;i<=10000;i++)
    {
        isPerfect(i);
    }
    return 0;
}
