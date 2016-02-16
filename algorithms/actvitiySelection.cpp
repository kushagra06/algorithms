#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int a[MAX],j=1;

void actSelect(int s[],int f[],int n)
{
    a[1]=1;
    int k=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]>=f[k])
        {
            a[++j]=i;
            k=i;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int s[n+1],f[n+1];
    
    for(int i=1;i<=n;i++)
        scanf("%d%d",&s[i],&f[i]);

    actSelect(s,f,n);

    for(int i=1;i<=j;i++)
        printf("%d ",a[i]);

    printf("\n");
    return 0;
}

