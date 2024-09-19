#include<iostream>
using namespace std;
char a[12];
int main()
{
    int n,m,k;
    cin>>n>>a>>m>>k;
    if(k==n)
    cout<<"mei you mai "<<a<<" de";
    else
    {
        if(k==m)cout<<"kan dao le mai "<<a<<" de";
        else
        cout<<"wang le zhao mai "<<a<<" de";
    }
}