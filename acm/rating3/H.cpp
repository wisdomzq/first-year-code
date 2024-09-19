#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[300005],n,tot[300005],cnt,tmp[300005];
int search(int x)
{
    int ans=0;
   
    // cout<<x<<"oooooo"<<endl;
  
       while(1)
       {
        if(x>cnt)return ans;
        if(tmp[cnt-x+1]>x)
        {
            ans+=tmp[cnt-x+1]-x;
        for(int i=cnt;i>=cnt-x+1;i--)tmp[i]-=tmp[cnt-x+1]-x;
        
        sort(tmp+1,tmp+1+cnt);
        }
        else
        {
         if(tmp[cnt-x+1]>0)
        {
            ans++;
        for(int i=cnt;i>=cnt-x+1;i--)tmp[i]--;
        
        sort(tmp+1,tmp+1+cnt);
        } 
        else 
          return ans;
        }
          
       }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])
        tot[++cnt]++;
        else tot[cnt]++;
    }
    sort(tot+1,tot+1+cnt);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=cnt;j++)
        tmp[j]=tot[j];
        cout<<search(i)<<endl;
    }
}