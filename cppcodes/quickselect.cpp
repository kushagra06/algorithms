#include<iostream>
#include<algorithm>
using namespace std;

/*void swap(int *p,int *q)
{
    int hold=*p;
    *p=*q;
    *q=hold;
}*/

int quickselect(int a[],int s,int e,int k)
{
    if(s<e)
    {
        int pivot=a[e];
        int i=s-1;
        for(int j=s;j<e;j++)
        {
            if(a[j]<=pivot)
            {
                i++;
                iter_swap(&a[i],&a[j]);
            }
        }
        iter_swap(&a[i+1],&a[e]);

        if(i+1==k)
            return a[i+1];
        else if(i+1 < k)
            quickselect(a,i+1,e,k);
        else
            quickselect(a,s,i,k);
    }
}

int main()
{
    int t;
    for(cin >> t;t--;)
    {
        int n,k;
        cin >> n >> k;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin >> a[i];

        int x=quickselect(a,1,n,k);
        cout << x << endl;
    }
    return 0;
}


