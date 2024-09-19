#include<iostream>
#include<map>
#define ll long long
using namespace std;
ll T,n,a[200005],ans,sum;
map<int,int> m;
int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0),cout.tie(0);
     cin>>T;
     while(T--)
     {
        m.clear();ans=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
        sum*=2;
        if(sum%n!=0)
        {
            cout<<0<<endl;continue;
        }
        sum/=n;
        for(int i=1;i<=n;i++)
        {
            ans+=m[sum-a[i]];
            m[a[i]]++;
        }
        cout<<ans<<endl;
     }
}
