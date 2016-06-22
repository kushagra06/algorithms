#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b) for(int i=a; i <= int(b); i++) 
#define TRvi(c, it) for(vi::iterator it = c.begin(); it != c.end(); it++)
#define TRvii(c, it) for(vii::iterator it = c.begin(); it != c.end(); it++)
#define TRmsi(c, it) for(msi::iterator it = c.begin(); it != c.end(); it++)

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distance
//memset(dp_memo, -1, sizeof dp_memo); // usefull to initialize DP memoization table 
//memset(arr, 0, sizeof arr); //useful to clear array of integers

int main()
{
    int n,S;
    int s,v;
    scanf("%d%d",&n,&S);
    vii a(n+1);
    REP(i,1,n)
    {
        scanf("%d%d",&s,&v);
        a[i] = make_pair(s,v);
    }
    int dp[n+1][S+1];
    memset(dp, 0, sizeof dp);
    REP(i, 1, n)
    {
        for(int j=1; j<=S; j++) // j = current max wt.
        {
            int x;
            if(j-a[i].first < 0) // if wt of i-th item is greater than current max. wt.
                x = 0;
            else
                x = dp[i-1][j-a[i].first]+a[i].second;
            dp[i][j] = max(dp[i-1][j], x);
        }
    }
    REP(i, 0, n)
    {
        REP(j, 0, S)
            printf("%d ",dp[i][j]);
        printf("\n");
    }
    printf("%d\n",dp[n][S]);
    return 0;
}
