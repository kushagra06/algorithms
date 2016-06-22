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

void init(int parent[], int n)
{
    REP(i,0,n-1)
        parent[i] = i;
}

int root(int i, int parent[])
{
    while(i != parent[i])
    {
        parent[i] = parent[parent[i]]; 
        i = parent[i];
    }
    return i;
}

int main()
{
    int n,e;
    scanf("%d%d",&n,&e);
    int parent[n], sz[n];
    memset(sz, 1, sizeof(sz));
    init(parent,n);
    REP(i,1,e)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int p = root(u, parent);
        int q = root(v, parent);
        if(sz[p] < sz[q])
        {
            parent[p] = q;
            sz[q] += sz[p];
        }
        else
        {
            parent[q] = p;
            sz[p] += sz[q];
        }
    }
    int x,y;
    scanf("%d%d",&x,&y);
    root(x, parent) == root(y, parent) ? printf("Connected\n") : printf("Not Connected\n");
    return 0;
}
