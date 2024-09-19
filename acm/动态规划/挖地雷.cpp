#include<iostream>
using namespace std;
int r[22][22],val[22],n,f[22],pre[22]={0},mark,ans,cnt,col[22];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>val[i],f[i]=val[i];
    for(int i=1;i<n;i++)
         for(int j=i+1;j<=n;j++)
             cin>>r[i][j]; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
             if(r[j][i]==1)
             {
                if(f[j]+val[i]>f[i])
                {
                    f[i]=f[j]+val[i];
                    pre[i]=j;
                   
                }  
             }
        }
        if(f[i]>ans)ans=f[i],mark=i;
    }
   
    col[++cnt]=mark;
    while(pre[mark]!=0)
    {
        col[++cnt]=pre[mark];
        mark=pre[mark];
    } 
    for(int i=cnt;i>=1;i--)cout<<col[i]<<" ";
    cout<<endl;
    cout<<ans;
}