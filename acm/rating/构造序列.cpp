#include<iostream>
using namespace std;
int a[15],b[15];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<a[1]<<" ";
    for(int i=2;i<=n;i++)
        cout<<a[i]-a[i-1]<<" ";
}