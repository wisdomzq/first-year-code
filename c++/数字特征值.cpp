#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,ans=0,cal=0,p,time;
    cin>>n;
    while(n>0)
    {
        cal++;
        time=pow(2,cal-1);
        p=n%10;
        if((p&1)==(cal&1))ans+=time;
        n/=10;
    }
    cout<<ans<<endl;
}