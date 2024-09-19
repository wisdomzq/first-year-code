// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// int dist[100005];
// bool mark[100005];
// struct node{
//     int end,dis;
// };
// struct Node{
//     int end,dis;
//     bool operator <( const Node &x )const
//     {
//         return x.dis<dis;
//     }
// };
// vector<node> edge[100005];
// int n,m,u,v,w;
// void Dij()
// {
//     priority_queue<Node> q;
//     Node tmp;
//     tmp.end=1;
//     tmp.dis=0;
//     q.push(tmp);
//     while(!q.empty())
//     {
//         int u1=q.top().end;
//         q.pop();
//         if(mark[u1])continue;
//         mark[u1]=1;
//         for(int i=0;i<edge[u1].size();i++)
//         {
//             int v1=edge[u1][i].end,l=edge[u1][i].dis;
//             if(!mark[v1]&&dist[v1]>dist[u1]+l)
//             {
//                 dist[v1]=dist[u1]+l;
//                 tmp.end=v1;
//                 tmp.dis=dist[v1];
//                 q.push(tmp);
//             }
//         }
//     }
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)dist[i]=0x7fffffff;
//     dist[1]=0;
//     node tmp;
//     for(int i=n;i>=2;i--)
//     {
//         tmp.end=i-1;tmp.dis=0;
//         edge[i].push_back(tmp);
//     }
//     for(int i=1;i<=m;i++)
//     {
//         cin>>u>>v>>w;
//             tmp.end=v;tmp.dis=w;
//             edge[u].push_back(tmp);
//         }
//     Dij();
//     if(dist[n]>=0x7fffffff)cout<<-1;
//     else
//     cout<<dist[n];
// }
#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
ll head[100005],cnt;
ll ans[1000005];
bool vis[1000005];
ll m,n,s;
struct edge
{
	ll to;
	ll nextt;
	ll wei;
}edge[1000005];
struct priority
{
    ll ans;
    ll id;
    bool operator <(const priority &x)const
    {
        return x.ans<ans;
    }
};
void addedge(ll x,ll y,ll z)
{
	edge[++cnt].to=y;
	edge[cnt].wei=z;
	edge[cnt].nextt=head[x];
	head[x]=cnt;
}
priority_queue<priority> q;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
        ans[i]=1e10;
	ans[1]=0;
    for(int i=m;i>=2;i++)
    cout<<1<<endl,addedge(i,i-1,0);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		addedge(a,b,c);
	}
	ll u;
	q.push((priority){0,1});
    while(!q.empty())
    {
        priority temp=q.top();
        q.pop();
        u=temp.id;
        if(!vis[u])
        {
        	vis[u]=1;
	        for(int i=head[u];i;i=edge[i].nextt)
	        {
	            int v=edge[i].to;
	            if(ans[v]>ans[u]+edge[i].wei)
	            {
	                ans[v]=ans[u]+edge[i].wei;
	                if(!vis[v])
	                {
	                    q.push((priority){ans[v],v});
	                }
	            }
	        }
		}
    }
	if(ans[m]>=1e10)cout<<-1;
    else
		cout<<ans[m]<<' ';
	}