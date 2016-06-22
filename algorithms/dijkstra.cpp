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

void dijkstra(vector< list< ii > > &adjlist, int s, int n)
{
    int vis[n+1], dist[n+1], parent[n+1], curr_dist = 0;
    priority_queue< ii, vii, greater<ii> > heap;
    memset(dist, MEMSET_INF, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    parent[s] = -1;
    heap.push(make_pair(s,dist[s]));
    ii temp;
    while(heap.size())
    {
        ii min = heap.top();
        heap.pop();
        vis[min.first] = 1;
        list< ii >::iterator x;
        for(x = adjlist[min.first].begin(); x != adjlist[min.first].end(); ++x)
        {
            curr_dist = dist[min.first] + x->second;
            if (vis[x->first]!=1 && curr_dist<dist[x->first])
            {
               dist[x->first] = curr_dist;
               parent[x->first] = min.first;
               heap.push(make_pair(x->first, x->second));
            }
        }
    }
    REP(i, 1, n)
        printf("%d ",dist[i]);
    printf("\n");
}

int main()
{
    int n,e,s,u,v,w;
    scanf("%d%d",&n,&e);
    vector< list< ii > > adjlist(n+1);
    REP(i, 1, e)
    {
        scanf("%d%d%d",&u,&v,&w);
        adjlist[u].push_back(make_pair(v,w));
    }
    scanf("%d",&s);
    dijkstra(adjlist, s, n);
    return 0;
}
