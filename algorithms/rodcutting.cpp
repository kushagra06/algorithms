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
#define TRvii(c, it) for(vii:iterator it = c.begin(); it != c.end(); it++)
#define TRmsi(c, it) for(msi::iterator it = c.begin(); it != c.end(); it++)

#define MEMSET_INF 127
#define MEMSET_HALF_INF 63
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distance
//memset(dp_memo, -1, sizeof dp_memo); // usefull to initialize DP memoization table 
//memset(arr, 0, sizeof arr); //useful to clear array of integers

int main()
{
    int n;
    scanf("%d",&n);
    vi p(n+1);
    REP(i,1,n)
    {
        scanf("%d",&p[i]);
    }
    int dp[n+1]; //dp[i] stores best possible profit of len i
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    REP(i,1,n)
    {
        REP(j,1,i)
        {
            int x = p[j] + dp[i-j];
            if (x>dp[i])
                dp[i] = x;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
