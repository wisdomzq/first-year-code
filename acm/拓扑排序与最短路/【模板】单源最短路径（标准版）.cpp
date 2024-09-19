#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dist[100005];
bool mark[100005];
struct node{
    int end,dis;
};
struct Node{
    int end,dis;
    bool operator <( const Node &x )const
    {
        return x.dis<dis;
    }
};
vector<node> edge[100005];
int n,m,s,u,v,w;
void Dij()
{
    priority_queue<Node> q;
    Node tmp;
    tmp.end=s;
    tmp.dis=0;
    q.push(tmp);
    while(!q.empty())
    {
        int u1=q.top().end;
        q.pop();
        if(mark[u1])continue;
        mark[u1]=1;
        for(int i=0;i<edge[u1].size();i++)
        {
            int v1=edge[u1][i].end,l=edge[u1][i].dis;
            if(!mark[v1]&&dist[v1]>dist[u1]+l)
            {
                dist[v1]=dist[u1]+l;
                tmp.end=v1;
                tmp.dis=dist[v1];
                q.push(tmp);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)dist[i]=0x7fffffff;
    dist[s]=0;
    node tmp;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        tmp.end=v;
        tmp.dis=w;
        edge[u].push_back(tmp);  
    }
    Dij();
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
}