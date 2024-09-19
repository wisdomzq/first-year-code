#include<iostream>
#include<cmath>
#define p 998244353
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,power,ans=0,tmp;
        cin>>n>>m;
        power=log2(m/n);
        ans=m/(1<<power)-n+1;
        ans%=p;
        if(power>0)
        {
           tmp=m/(1<<(power-1))/3-n+1;
           if(tmp>0) ans+=(tmp*power%p);
        }
        cout<<power+1<<" "<<ans<<endl;
    }
}