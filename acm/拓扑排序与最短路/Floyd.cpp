#include<iostream>
#include<cstring>
using namespace std;
int tu[101][101];
int main()
{
    int n,m,u,v,w;
    memset(tu,10000,sizeof(tu));
    cin>>n>>m;
    for(int i=1;i<=n;i++)tu[i][i]=0;
    for(int i=1;i<=m;i++)
    {
         cin>>u>>v>>w;
         if(w<tu[u][v])
         tu[u][v]=tu[v][u]=w;
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j)continue;
         tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]),tu[j][i]=min(tu[j][i],tu[j][k]+tu[k][i]);
    }
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<tu[i][j]<<" ";
        cout<<endl;
    }
}