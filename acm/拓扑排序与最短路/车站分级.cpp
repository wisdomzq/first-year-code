//*********
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1500;
int n,m,ans=0,num=0;
int is[maxn],dep[maxn],head[maxn],a[maxn],in[maxn],vis[maxn][maxn]; //dis数组表示起点到某点的最短路大小，
struct Edge{
    int v,nxt;
}edge[3000010];
void add(int u,int v)//链式前缀星！！！重要，比vector稳定，是一维的
{
    ++num;
    edge[num].v=v;
    edge[num].nxt=head[u];
    head[u]=num;
}
void Topo_sort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    if(in[i]==0)q.push(i),dep[i]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=head[t];i;i=edge[i].nxt)
        {
            int v=edge[i].v;
            dep[v]=dep[t]+1;
            ans=max(ans,dep[v]);
            in[v]--;
            if(in[v]==0)q.push(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        memset(a,0,sizeof(a));
        memset(is,0,sizeof(is));
        int s;
        cin>>s;
        for(int j=1;j<=s;j++)
        cin>>a[j],is[a[j]]=1;
        for(int j=a[1]+1;j<=a[s];j++)
        {
            if(!is[j])
            for(int k=1;k<=s;k++)
            {
                if(!vis[j][a[k]])
                {
                    in[a[k]]++;
                    add(j,a[k]);
                    vis[j][a[k]]=1;
                }
            }
        }
        
    }Topo_sort();
        cout<<ans;
}