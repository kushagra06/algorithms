#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int a,b,x;
    cin >> a >> b;
    x=gcd(a,b);
    cout << x << endl;
    return 0;
}
