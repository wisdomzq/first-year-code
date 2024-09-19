#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll n,p,l,t,work=0;
        cin>>n>>p>>l>>t;
        ll judge=ceil(double(n)/7);
        // cout<<judge<<endl;
        if(p<=floor(double(judge)/2)*(2*t+l))work=ceil(double(p)/(2*t+l));
        else{
            work+=floor(double(judge)/2);
            p-=floor(double(judge)/2)*(2*t+l);
            // cout<<p<<endl;
            if(judge%2==1)p-=(l+t),work++;
            if(p>0)
            work+=ceil(double(p)/l);
        }
        cout<<n-work<<endl;
    }
}