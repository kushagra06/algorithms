#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,t,b,l,r,dir=0;
    cin >> n >> m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    }
    t=0,b=n-1,l=0,r=m-1;
    while(t<=b && l<=r)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
                cout << a[t][i] << " ";
            dir=1;
            t++;
        }
        else if(dir==1)
        {
            for(int i=t;i<=b;i++)
                cout << a[i][r] << " ";
            dir=2;
            r--;
        }
        else if(dir==2)
        {
            for(int i=r;i>=l;i--)
                cout << a[b][i] << " ";
            dir=3;
            b--;
        }
        else
        {
            for(int i=b;i>=t;i--)
                cout << a[i][l] << " ";
            dir=0;
            l++;
        }
    }
    cout << endl;
    return 0;
}
