#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1000005,maxn1=4000010,mod=100003;
int n,m,dist[maxn],head[maxn],sh[maxn],s,num; //dis数组表示起点到某点的最短路大小，
//sh数组表示起点到某点的最短路条数。
struct Edge{
    int v,w,nxt;
}edge[maxn1];
void add(int u,int v,int w)//链式前缀星！！！重要，比vector稳定，是一维的
{
    edge[num].v=v;
    edge[num].w=w;
    edge[num].nxt=head[u];
    head[u]=num++;
}
struct node{
    int x,y;
    bool operator< (const node &a) const{
        return a.y<y;
    }
};
void dijkstra()
{
    memset(dist,0x3f,sizeof(dist));                //初始化。 
    dist[1]=0;
    priority_queue<node> q;
    sh[1]=1;
    q.push((node){1,0});
    node a;
    while(!q.empty())
    {
        a=q.top();
        int u=a.x,d=a.y;
        q.pop();
        if(d!=dist[u])continue;
        for(int i=head[u];i!=-1;i=edge[i].nxt)
        {
            int v=edge[i].v;
            if(d+edge[i].w==dist[v])
            sh[v]=(sh[u]+sh[v])%mod;
            if(dist[v]>dist[u]+edge[i].w)
            {
                 dist[v]=dist[u]+edge[i].w;
                 sh[v]=sh[u];
                 q.push((node){v,dist[v]});
            }
        }
    }
}
int main()
{
       ios::sync_with_stdio(0);
       cin.tie(0);cout.tie(0);
       cin>>n>>m;
       for(int i=1;i<=n;i++)head[i]=-1;
       num=0;
       for(int i=1;i<=m;i++)
       {
        int u1,v1;
        cin>>u1>>v1;
        add(u1,v1,1),add(v1,u1,1);
       }
       dijkstra();
       for(int i=1;i<=n;++i)
		cout<<sh[i]<<endl;
} 
