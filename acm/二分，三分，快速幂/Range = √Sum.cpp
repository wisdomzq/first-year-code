#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
       int n;
        cin>>n;
       if(n&1)
       {
        int begin=(n-1)/2+2,end=n;
        for(int i=begin;i<=end;i++)cout<<i<<" ";
        begin=n+3,end=(n-1)/2+n+3;
        for(int i=begin;i<=end;i++)cout<<i<<" ";
        cout<<endl;
       }
       else{
        for(int i=n/2;i<n;i++) cout<<i<<' ';
		for(int i=n+1;i<=n+n/2;i++) cout<<i<<' ';
		cout<<endl;
       }
    }
}