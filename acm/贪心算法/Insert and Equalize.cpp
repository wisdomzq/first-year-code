#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}
int main()
{
    ios::sync_with_stdio(0);;
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ll n,*num,gd=0,insert,n1,ans=0;
        cin>>n;
        n1=n;
        num=new ll[n+3];
        for(int i=1;i<=n;i++)cin>>num[i];
        if (n==1) {
			cout<<1<<endl;
			continue;
		}
        sort(num+1,num+1+n);
        for(int i=2;i<=n;i++)gd=gcd(gd,num[i]-num[i-1]);
        insert=num[n]-gd;
        while(insert==num[n1-1]&&n1-1>=1)
        {
            insert-=gd;
            n1--;
        }
        
         for(int i=1;i<=n;i++)
         ans+=(num[n]-num[i])/gd;
         ans+=abs(insert-num[n])/gd;
         cout<<ans<<endl;
    }
}