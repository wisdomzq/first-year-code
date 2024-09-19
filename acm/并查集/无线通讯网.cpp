#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
struct Edge{
    double u,v,w;
}edge[1000005];
int fa[5005],n,m,cnt,eu,ev,s,p;
double a[1005],b[1005],ans;
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
          ans=edge[i].w;
          n++;
          fa[ev]=eu;
          if(n>=p-s){
            cout<<fixed<<setprecision(2)<<ans;
            return;
          }
    }
}
int main()
{
    cin>>s>>p;
    for(int i=1;i<=p;i++)fa[i]=i;
    for(int i=1;i<=p;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=1;j<i;j++)
        {
            m++;
            edge[m].u=i,edge[m].v=j,edge[m].w=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
        }
    }
    kruskal();
   
}