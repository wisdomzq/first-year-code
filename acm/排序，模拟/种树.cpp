#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct user{
    int be,en,num;
}u[5005];
bool cmp(user a ,user b)
{
    return a.en<b.en;
}
bool a[30005]={0};
int n,m,ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)  cin>>u[i].be>>u[i].en>>u[i].num;
    sort(u+1,u+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        int k=0;
        for(int j=u[i].be;j<=u[i].en;j++) if(a[j]) k++;
        if(k>=u[i].num) continue;
        for(int j=u[i].en;j>=u[i].be;j--)
        {
            if(!a[j]) 
            {
                ans++;a[j]=1;k++;
            if(k==u[i].num) break;
            }
        }
    }
    cout<<ans;
}
