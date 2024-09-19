#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int maxn[1001]={0},bian[1005][1005]={0};
bool point[1005]={0};
 vector<int> p[1001];
void dfs(int u,int v)//u为起点,v为遍历到的点
{
     if(p[u].empty()) return ;
     for(int i=0;i<p[v].size();i++) 
     {
        if(point[p[v][i]]==false)
        {
           maxn[u]=max(maxn[u],p[v][i]);
           point[p[v][i]]=true;
           dfs(u,p[v][i]);
        }
     }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
   
    for(int i=1;i<=n;i++)maxn[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        p[x].push_back(y);
    } 
    for(int i=1;i<=n;i++)
    {
        dfs(i,i);
        cout << maxn[i] << " ";
		memset(point, 0, sizeof(point));
    }
    
}