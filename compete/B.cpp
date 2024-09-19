#include<iostream>
using namespace std;
double a[1005],b[1005];
int main()
{
    int n;
    int a1,b1;
    cin>>n;
    a1=0,b1=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]>b[j])a1++;
            if(b[i]>a[j])b1++;
        }
    } 
    if(a1>b1)cout<<"first";
    if(a1==b1)cout<<"tie";
    if(a1<b1)cout<<"second";
    cout<<endl;
}