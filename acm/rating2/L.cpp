#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll dr[1000005],num;
bool judge=true;
struct ask{
    ll val,ans,id;
}a[1000005];
bool cmp(ask x,ask y)
{
    return x.val<y.val;
}
bool cmp2(ask x,ask y)
{
    return x.id<y.id;
}
int n,q;
int main()
{
     cin>>n>>q;
     for(int i=1;i<=n;i++)cin>>dr[i];
    //  while(q--)
    //  {
    //     judge=false;
    //     cin>>num;
    //     // int mark=upper_bound(dr+1,dr+1+n,num)-dr,begin=1;
    //     // if(mark==1)cout<<num<<endl;
    //     // else{
    //     //     num+=mark-begin;
    //     //     begin=mark;
    //     //     while()
    //     // }
    //     for(int i=1;i<=n;i++)
    //     {
    //         if(num<dr[i])
    //         {
    //             cout<<num<<endl;
    //             judge=true;break;
    //         }
    //         else
    //         num++;
    //     }
    //     if(!judge)cout<<num<<endl;
    //  }
    for(int i=1;i<=q;i++)cin>>a[i].val,a[i].id=i;
    sort(a+1,a+1+q,cmp);
    int j=1; 
    a[q + 1].val = 1e18;
    for(int i=1;i<=n;i++)
    {
        while(a[j].val+i-1<dr[i])
        {
            a[j].ans=a[j].val+i-1;
            j++;
        }
    }
   
    while(j<=q)
    {
        a[j].ans=a[j].val+n;
        j++;
    }
    sort(a+1,a+1+q,cmp2);
    for(int i=1;i<=q;i++)cout<<a[i].ans<<endl;
}