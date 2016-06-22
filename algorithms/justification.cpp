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
#define PAGE_WIDTH 10

int badness(int i, int j)
{
    int width = j-i;
    int x = PAGE_WIDTH - width;
    printf("i:%d j:%d badness:%d\n", i, j , x*x);
    return (x*x);
}

int main()
{
    char s[100000];
    scanf("%[^\n]s",s);
    int dp[100000];
    memset(dp, INT_MAX, sizeof dp);
    for(int i=0;s[i]!='\0';i++)
    {
        for(int j=i+1;s[j]!='\0';j++)
        {
            int x = dp[j]+badness(i,j);
            if (x<dp[i])
                dp[i] = x;
        }
    }
//    for(int i=0;i<strlen(s);i++)
//        printf("%d ",dp[i]);
//    printf("\n");
    return 0;
}
