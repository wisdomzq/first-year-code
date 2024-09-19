#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
double dist[2010];
bool mark[2010]={0};
int n,m,x,y,A,B;
double z;
struct Node{
    int id;
    double dis;
    bool operator<(const Node &a) const{
        return a.dis>dis;
    }
};
struct node{
    int id;
    double dis;
};
vector<node> edge[100005];
void Dij()
{
    priority_queue<Node> q;
    Node tmp;
    tmp.id=A;
    tmp.dis=1;
    q.push(tmp);
    while(!q.empty())
    {
        int u=q.top().id;
        q.pop();
        if(mark[u])continue;
        mark[u]=1;
        for(int i=0;i<edge[u].size();i++)
        {
           int v=edge[u][i].id;
           double l=edge[u][i].dis;
            if(!mark[v]&&dist[v]<dist[u]*l)
            {
                dist[v]=dist[u]*l;
                tmp.id=v;
                tmp.dis=dist[v];
                q.push(tmp);
            }
        }
    }
}
int main()
{
     node tmp;
     cin>>n>>m;
     memset(dist,-0x3f,sizeof(dist));
     for(int i=1;i<=m;i++)
     {
         cin>>x>>y>>z;
         tmp.id=y,tmp.dis=1-z/100;
         edge[x].push_back(tmp);
         tmp.id=x;
         edge[y].push_back(tmp);
     }
     cin>>A>>B;
     dist[A]=1;
     Dij();
     cout<<fixed<<setprecision(8)<<100/dist[B];
     

}