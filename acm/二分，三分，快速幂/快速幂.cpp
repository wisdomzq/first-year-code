#include<iostream>
using namespace std;
long long a,b,k;
long long qpow(long long m,long long n)
{
    long long ans=1,base=m;
    while(n)
    {
        if(n&1)ans*=base;
        ans%=k;
        base=((base%k)*(base%k))%k;
        n/=2;
    }
    ans%=k;
    return ans;
}
int main()
{
      cin>>a>>b>>k;
    cout<<a<<"^"<<b<<" mod "<<k<<"="<<qpow(a,b);
}