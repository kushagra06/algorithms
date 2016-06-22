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

si temp,uni;
void recActivitySelector(int s[],vii &f,int k, int n)
{
    int m = k+1;
    while(m<n && s[m]<f[k].first)
        m++;
    if(m<=n)
    {
        temp.insert(m);
        set_union(temp.begin(),temp.end(),uni.begin(),uni.end(),inserter(uni,uni.begin()));
        recActivitySelector(s,f,m,n);
    }
    else
        return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int s[n+1];
    vii f(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&s[i],&f[i].first);
        f[i].second = i;
    }
    sort(f.begin(),f.end());
    recActivitySelector(s,f,0,n);
    si::iterator i;
    for(i=uni.begin();i!=uni.end();++i)
        printf("%d ",*i);
    printf("\n");
    return 0;
}
