#include<stdio.h>
int main()
{
    int a,b,x,y,r;
    printf("Enter 2 nos:\n");
    scanf("%d%d",&a,&b);
    x=a;
    y=b;
    while(y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    printf("gcd is: %d\n",x);
    return 0;
}

