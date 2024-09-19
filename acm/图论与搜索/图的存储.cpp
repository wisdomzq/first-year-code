#include<iostream>
#include<algorithm>
using namespace std;
int ma[1005][1005]={0},shu[1005]={0},bian[1005][1005]={0};
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        ma[a][b]=1,ma[b][a]=1;
        bian[a][++shu[a]]=b,bian[b][++shu[b]]=a;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<ma[i][j]<<" ";
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<shu[i]<<" ";
        sort(bian[i]+1,bian[i]+1+shu[i]);
        for(int j=1;j<=shu[i];j++)cout<<bian[i][j]<<" ";
        cout<<endl;
    }
    
}