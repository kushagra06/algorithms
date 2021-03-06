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


void dfs_visit(vector< list<int> > &adj,vi &vis, int u)
{
    vis[u] = 1;
    printf("%d ",u);
    list<int>::iterator i;
    for(i=adj[u].begin(); i!=adj[u].end(); ++i)
    {
        if(vis[*i] != 1)
            dfs_visit(adj,vis,*i);
    }
}

void dfs(vector< list<int> > &adj, int n, int e)
{
    vi vis(n);
    for(int i=0;i<n;i++)
            if(vis[i]==0)
            dfs_visit(adj,vis,i);
    }
}

int main()
{
    int n,e,u,v;
    scanf("%d%d",&n,&e);
    vector< list<int> > adj(n);
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
/*    int c = 0;
    vector< list<int> >::iterator i;
    for(i=adj.begin();i!=adj.end();++i)
    {
        cout << c++ << " ";
        list<int> li = *i;
        list<int>::iterator j;
        for(j=li.begin();j!=li.end();++j)
            cout << *j << " ";
        cout << endl;
    }*/

    dfs(adj, n, e);
    printf("\n");
    return 0;
}
