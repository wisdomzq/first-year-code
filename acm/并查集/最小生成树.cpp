#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,w;
}edge[400005];
int fa[5005],n,m,ans,cnt,eu,ev;
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal()
{
    sort(edge+1,edge+1+m,cmp);
    for(int i=1;i<=m;i++)
    { 
          eu=find(edge[i].u),ev=find(edge[i].v);
          if(eu==ev)continue;
          ans+=edge[i].w;
          fa[ev]=eu;
          if(++cnt==n-1)break;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i].u=a,edge[i].v=b,edge[i].w=c;
    }
    kruskal();
    if(cnt<n-1)cout<<"orz";
    else cout<<ans;
}