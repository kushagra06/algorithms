#include<iostream>
#include<cmath>
#define N 8
using namespace std;

int isSafe(int r,int c,int a[][N])
{
    if(r>=0 && r<N && c>=0 && c<N && a[r][c]==0)
        return 1;
    return 0;
}

int move(int a[][N],int hor[8],int ver[8],int cur_row,int cur_col,int cnt)
{
    int r,c;
    if(cnt==N*N+1)
        return 1;
    for(int i=0;i<8;i++)
    {
        r=cur_row+ver[i];
        c=cur_col+hor[i];
        if(isSafe(r,c,a))
        {
            a[r][c]=cnt;
            if(move(a,hor,ver,r,c,cnt+1)==1)
                return 1;
            else
                a[r][c]=0;
        }
    }
    return 0;
}

int main()
{
    int a[N][N]={};
    a[0][0]=1;
    int hor[8]={2,1,-1,-2,-2,-1,1,2};
    int ver[8]={-1,-2,-2,-1,1,2,2,1};
    int cur_row=0,cur_col=0;
    int cnt=2;
    int x=move(a,hor,ver,cur_row,cur_col,cnt);
    if(x==1)
    {
        cout << "Tour is possible\n";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No tour possible\n";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
