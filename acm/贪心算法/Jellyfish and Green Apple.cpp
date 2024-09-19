#include<iostream>
using namespace std;
#define ll long long
ll gcd(ll x,ll y)
{
    return y?gcd(y,x%y):x;
}
int check(ll x)
{
    return (x&(-x))==x;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
         if(n%m==0)cout<<0<<endl;
          
        
            // cout<<n%m<<endl;
            
        //   cout<<gcd(n,m)<<endl;
            if(!check(m/gcd(n,m)))cout<<-1<<endl;
            else 
            {
               n%=m;
                ll ans=0;
                
                while(n)
                {
                    ans+=n;
                    n=(n*2)%m; 
                }
                cout<<ans<<endl;
            }
        }
    }
