#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[300005],l[300005],r[300005];
int main()
{
   int n,ans=10000000000;
   cin>>n;
   l[0]=0,r[n+1]=0;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)
   l[i]=max(l[i-1],a[i]+n-i);
   for(int i=n;i>=1;i--)
   r[i]=max(r[i+1],a[i]+i-1);
   for(int i=1;i<=n;i++)
   ans=min(ans,max(a[i],max(r[i+1],l[i-1])));
   cout<<ans;
}