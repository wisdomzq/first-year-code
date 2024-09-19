#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
ll a,b,k,ans=0;
int main()
{
    cin>>a>>b>>k;
    while(a<b)
    {
        a*=k;
        ans++;
    }
    cout<<ans;
}