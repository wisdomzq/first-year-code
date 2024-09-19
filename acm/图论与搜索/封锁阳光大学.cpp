#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> q[10005];
int visit[10005]={0},colour[10005];
int n,m,x,y,tmp,ttmp;
void dfs(int p,int col)
{
    if(colour[p]!=-1&&colour[p]!=col)
    {
        cout<<"Impossible"<<endl;exit(0);
    }
    if(colour[p]==col) return;
    colour[p]=col,tmp++,visit[p]=1;
    for(int i=0;i<q[p].size();i++)dfs(q[p][i],col^1);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        q[x].push_back(y),q[y].push_back(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            tmp=0,ttmp=0;
            memset(colour,-1,sizeof(colour));
            dfs(i,0);
            for(int j=1;j<=n;j++)if(colour[j]==1)ttmp++;
            ans+=min(ttmp,tmp-ttmp);
        }
    }
    cout<<ans<<endl;
}