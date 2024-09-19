#include<iostream>
using namespace std;
#define ll long long
ll a[200005],b[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ll ans=0,maxx=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],ans+=a[i];
        for(int i=1;i<=n;i++)cin>>b[i],maxx=max(maxx,b[i]),ans+=b[i];
        ans-=maxx;
        cout<<ans<<endl;
        
    }
}