#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],b[100010],n,cnt;
using namespace std;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
       if(a[i]>b[cnt])
       {
        b[++cnt]=a[i];
       }
       else{
        b[upper_bound(b+1,b+1+cnt,a[i])-b]=a[i];
       }
    }
    cout<<cnt;
}