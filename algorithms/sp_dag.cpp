//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<list>
#include<bits/stdc++.h>
#define endl "\n"
#define _ ios_base :: sync_with_stdio(0);cin.tie(0);
using namespace std;


int sp(vector< list< pair<int,int> > > &adj,int s,int d)
{
    if(s==d)
        return 0;
    else
    {
        
int main()
{
    int V,E,u,v,w;
    cin >> V >> E;
    vector< list< pair<int,int> > > adj(V+1);
    for(int i=1;i<=E;i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
 //       adj[v].push_back(make_pair(u,w));
    }

    /*    for(int i=1;i<=V;i++)
    {
        printf("adj[%d] ",i);
        list< pair<int,int> >::iterator itr=adj[i].begin();
        while(itr!=adj[i].end())
        {
            cout << (*itr).first << " ";
            ++itr;
        }
        cout << endl;
    }*/
    int s,d;
    cin >> s >> d;
    int d[V+1]
    int ans=sp(adj,s,d);
    return 0;
}

