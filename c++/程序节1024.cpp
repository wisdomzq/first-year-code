#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,p;
    cin>>n;
    if(n>=0)
    {
       while(n>0)
       {
        p=n%2;
        if(p==1)ans++;
        n/=2;
       }
    }
    else{
        ans++;
        n+=2147483648;
        while(n>0)
       {
        p=n%2;
        if(p==1)ans++;
        n/=2;
       }
    }
    cout<<ans<<endl;
}