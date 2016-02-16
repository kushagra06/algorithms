#include<iostream>
#include<list>
#include<algorithm>
#include<stack>
//#include<bits/stdc++.h>
#define _ios_base :: sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define INF 99999999
using namespace std;


class Node
{
    int v;
    int wt;
    public:
    Node(int _v,int _w)
    {
        v=_v;
        wt=_w;
    }
    int getV()
    {
        return v;
    }
    int getWt()
    {
        return wt;
    }
};



class Graph
{
    int V;
    list<Node> *adj;
    void topoSort(int v,bool visited[],stack<int> &Stack);
    void DFSUtil(int v,bool visited[]);
    void spUtil(int s,int dist[],stack<int> &Stack,int visited[]);
    public:
    Graph(int V);
    void addEdge(int v,int u,int wt);
    void DFS(int v);
    void sp(int s);
};



Graph::Graph(int V)
{
    this->V=V;
    adj=new list<Node>[V+1];
}

void Graph::addEdge(int v,int u,int wt)
{
    Node node(u,wt);    
    adj[v].push_back(node);
}


void Graph::topoSort(int v,bool visited[],stack<int> &Stack)
{
    visited[v]=1;
    list<Node>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        Node node=*i;
        if(!visited[node.getV()])
            topoSort(node.getV(),visited,Stack);
    }
    Stack.push(v);
}

/*void Graph::DFSUtil(int v,bool visited[])
{
    visited[v]=1;
    cout << v << " ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
            DFSUtil(*i,visited);
    }
}*/

/*void Graph::DFS(int v)
{
    bool *visited=new bool[V+1];
    for(int i=0;i<V;i++)
        visited[i]=0;
    for(int i=1;i<=V;i++)
    {
        if(visited[i]==0)
            DFSUtil(i,visited);
    }
}*/


void Graph::sp(int s)
{
    stack<int> Stack;
    int dist[V+1];
    bool *visited=new bool[V+1];
    for(int i=2;i<=V;i++)
        dist[i]=INF;
    dist[1]=0;
    for(int i=1;i<=V;i++)
        visited[i]=0;

    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
            topoSort(i,visited,Stack);
    }
}

void Graph::spUtil(int s,int dist[],stack<int> &Stack,int visited[])
{
    
    while(Stack.empty()==0)
    {
        int u=Stack.top();
        Stack.pop();

        list<Node>::iterator i;
        if(dist[u]!=INF)
        {
            for(i=adj[u].begin();i!=adj[u].end();i++)
            {
                if(dist[i->getV()] > dist[u] + i->getWt())
                    dist[i->getV()]=dist[u] + i->getWt();
            }
        }
        else
            spUtil(u,dist,Stack,visited);

    }

    for(int i=1;i<=V;i++)
        (dist[i]==INF) ? cout  << "INF ": cout << dist[i] << " ";
    cout << endl;
}


int main()
{
    int V,E,v,u,w;
    cin >> V >> E;
    Graph g(V);
    for(int i=0;i<E;i++)
    {
        cin >> v >> u >> w;
        g.addEdge(v,u,w);
    }
//    g.DFS(1);
    cout << endl;
    int s;
    cin >> s;
    g.sp(s);
    cout << endl;
    return 0;
}


