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

void bfs(vector< list<int> > &adj, int s, int n)
{
    vi vis(n);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int f = q.front();
        printf("%d ",f);
        q.pop();
        list<int>::iterator i;
        for(i=adj[f].begin(); i!=adj[f].end(); ++i)
        {
            if(vis[*i] != 1)
            {
                q.push(*i);
                vis[*i]=1;
            }
        }
    }
}
       
int main()
{
    int n,e,u,v;
    scanf("%d%d",&n,&e);
    vector< list<int> > adj(n);
    for(int i=0; i<e; i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj,0,n);
    printf("\n");
    return 0;
}
