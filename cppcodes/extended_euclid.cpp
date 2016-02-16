#include<iostream>
#include<cmath>
using namespace std;

int x,y,d1,d,x1,y_1;//y1 can't be declared

int extended_euclid(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        d1=extended_euclid(b,a%b);
        x1=x;
        y_1=y;
        d1=b*x1+(a%b)*y_1;
        d=d1;
        x=y_1;
        y=x1-floor(a/b)*y_1;
        return d;
    }
}

int main()
{
    int a,b,gcd;
    cin >> a >> b;
    gcd=extended_euclid(a,b);
    cout << gcd << " " << x << " " << y << endl;
    return 0;
}
