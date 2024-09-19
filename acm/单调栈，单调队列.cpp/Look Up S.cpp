#include<iostream>
#include<stack>
using namespace std;
int a[100005],f[100005];
int main()
{
    int n;
    stack<int> s;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[i]>=a[s.top()])s.pop();
        if(!s.empty())f[i]=s.top();
        else f[i]=0;
        s.push(i);
    }
    for(int i=1;i<=n;i++)cout<<f[i]<<endl;
}