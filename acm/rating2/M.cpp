#include<iostream>
#include<vector>
using namespace std;
vector<int> out[2005];
bool visit[2005][2005]={0},fin[2005]={0};
int n,m,be,en,ans=0;
void search(int head,int tmp)
{
    
    visit[head][tmp]=1;
    // cout<<head<<" "<<tmp<<endl;
    // fin[head]=1;
    for(int i=0;i<out[tmp].size();i++)
    {
       if(!visit[head][out[tmp][i]]) 
       {
        // visit[head][out[tmp][i]]=1;
        // //  cout<<head<<" "<<out[tmp][i]<<endl;
        // if(fin[out[tmp][i]])
        // {
        //     for(int j=1;j<=n;j++)
        //     if(visit[out[tmp][i]][j])visit[head][j]=1;
        //     continue;
        // }
        search(head,out[tmp][i]);
       }
       
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>be>>en;
        out[be].push_back(en);
    }
    for(int i=1;i<=n;i++)
    search(i,i);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(visit[i][j])ans++;
    cout<<ans;
}