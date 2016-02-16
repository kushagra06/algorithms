#include<stdio.h>

long long int fibo[1000001];

long long int fib(int n)
{
    int i;
    long long int f;
    for(i=1;i<=n;i++)
    {
        if(i<=2)
            f=1;
        else
            f=fibo[i-1]+fibo[i-2];
        fibo[i]=f;
    }
    return fibo[n];
}

int main()
{
    int n;
    scanf("%d",&n);
    long long int x=fib(n);
    printf("%lld\n",x);
    return 0;
}

