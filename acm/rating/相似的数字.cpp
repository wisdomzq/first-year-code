// #include<iostream>
// #include<algorithm>
// #include<cmath>
// using namespace std;
// #define ull unsigned long long
// ull a[200005],b[200005];
// int main()
// {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//     ull n,m,d;
//     cin>>n>>m>>d;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+m);
//     ull dis,ans=0;
//     ull mark=m;
//     for(ull i=n;i>=1;i--)
//     {
//         for(ull j=mark;j>=1;j--)
//         {
//             dis=(a[i]>b[j])?a[i]-b[j]:b[j]-a[i];
//             if(dis<=d)
//             ans=max(ans,a[i]+b[j]);
//             if(a[i]>b[j]&&dis>d)continue;
//             if(i>=2&&b[j]>a[i-1]&&dis>=d)mark=j;
//         }
//     }
//     if(ans>0)cout<<ans;
//     else
//     cout<<-1;
// }

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ull unsigned long long
ull a[200005],b[200005];
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ull ans=0;
    ull n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n); 
    sort(b+1,b+1+m);
        for(int i=m;i>=1;i--)
        {
            if(upper_bound(a+1,a+n+1,b[i]+d)!=NULL)
            {
                if(a[(upper_bound(a+1,a+n+1,b[i]+d)-a)-1]-b[i]<=d||b[i]-a[(upper_bound(a+1,a+n+1,b[i]+d)-a)-1]<=d)
                {
                    
                    ans=max(ans,b[i]+a[(upper_bound(a+1,a+n+1,b[i]+d)-a)-1]);
                    continue;
                }
            }
        }
        if(ans>0)
        cout<<ans;
        else cout<<-1;
  
    }
    
   

