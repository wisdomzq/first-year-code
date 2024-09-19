#include<iostream>
using namespace std;
#define ll long long
ll a[105];
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll num=1;
        for(int i=1;i<=n;i++)
        {
           cin>>a[i]; 
           while(num==a[i])num++;
           if(i<n)num++;
        }
        cout<<num<<endl;
    }

}