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
    if(n!=0 && (n&(n-1))==0)
        printf("%d is a power of 2\n",n);
    else
        printf("%d is NOT a power of 2\n",n);
    return 0;
}

