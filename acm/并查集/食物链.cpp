#include<iostream>
using namespace std;
int n,m,ans=0,fa[300005],u,v,w;
int find(int x)
{
    if(fa[x]==x)return x;
    else
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*3;i++)fa[i]=i;
    while(m--)
    {
           cin>>w>>u>>v;
           if(v>n||u>n)
           {
            ans++;
            continue;
           }
           if(w==1)
           {
            if(find(u)==find(v+n)||find(v)==find(u+n)) ans++;
            else fa[find(u)]=find(v),fa[find(u+n)]=find(v+n),fa[find(u+n+n)]=find(v+n+n);
           }
           if(w==2)
           {
            if(find(u)==find(v)||find(u)==find(v+n))ans++;
            else fa[find(u+n)]=find(v),fa[find(u+n+n)]=find(v+n),fa[find(u)]=find(v+n+n);
           }
    }
    cout<<ans;
}