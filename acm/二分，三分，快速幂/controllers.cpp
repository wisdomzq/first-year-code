#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
char a[200005];
int main()
{
    ll n,plus=0,minus=0;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='+')plus++;
        if(a[i]=='-')minus++;
    }
    int T;
    cin>>T;
    while(T--)
    {
        ll x,y;
        cin>>x>>y;
        if(plus==minus)cout<<"YES"<<endl;
        else{
           if(x==y)
        {
            if(minus!=plus)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else{
            if(((plus-minus)*(y))%(y-x)==0)
        {
            ll ans=((plus-minus)*y)/(y-x);
            if(ans<=plus&&ans+minus>=0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
        } 
        }
        
        
    }


}
