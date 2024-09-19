#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
bool visit[100005];
ll value[100005],ans;
int n,m,x,y,j;
vector<int> v[100005];
//  vector< vector<int> > v;

ll search(int x)
{
     if(value[x]) return value[x];
     visit[x]=1;
    ll sum=0;
    for(int i=0;i<v[x].size();i++)
   {
    if(visit[v[x][i]]) continue;
    sum+=search(v[x][i]);
   }
   return sum;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
       cin>>n>>m;
       for(int i=1;i<=n-1;i++)
       cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
       ans=0; 
       for(int i=1;i<=m;i++)
       cin>>x>>y,value[x]=y;
       for(int i=1;i<=n;i++)
       {
        if(value[i]||visit[i])continue;
        ans=max(ans,search(i));
       }
       cout<<ans<<endl;
       for(int i=1;i<=n;i++)    v[i].clear();
     memset(value,0,sizeof(value));
       memset(visit,0,sizeof(visit));
    }
}