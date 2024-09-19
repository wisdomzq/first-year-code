#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int p,q;
    float s,ans,ans1,ans2;
    cin>>s>>p>>q;
    ans=s*0.1;
    s-=ans;
    ans1=s*p/100*q/100;
    ans2=s*(100-p)/100;
    ans=ans+ans1+ans2;
    cout<<fixed<<setprecision(2)<<ans<<endl;
}