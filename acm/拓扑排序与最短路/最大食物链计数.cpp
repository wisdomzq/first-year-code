#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int mod=80112002;
int n,m,x,y;
vector<int> a[5005];
queue<int> q;
int du[5005]={0},value[5005],ans=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        du[y]++;
    }
    for(int i=1;i<=n;i++)
        if(du[i]==0)value[i]=1,q.push(i);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int j=0;j<a[k].size();j++)
            {
                value[a[k][j]]+=value[k];
                value[a[k][j]]%=mod;
                du[a[k][j]]--;
                if(du[a[k][j]]==0)
                {
                   
                    if(a[a[k][j]].empty())
                    {
                        ans+=value[a[k][j]],ans%=mod;
                        continue;
                    }
                     q.push(a[k][j]);
                }
            }
        }
        cout<<ans;
   
}