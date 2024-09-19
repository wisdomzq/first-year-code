#include<iostream>
using namespace std;
int main()
{
    long long n,ans=0;
    char *a,*b;
    cin>>n;
    a=new char [n];
    b=new char [n];
    cin>>a>>b;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            if(a[i]-b[i]>13)
            ans+=26-(a[i]-b[i]);
            else ans+=(a[i]-b[i]);
        }
        else
        {
             if(b[i]-a[i]>13)
             ans+=26-(b[i]-a[i]);
            else ans+=(b[i]-a[i]);
        }
    }
    cout<<ans<<endl;
}