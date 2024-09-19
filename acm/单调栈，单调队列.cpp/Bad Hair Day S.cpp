#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n,num;
    long long ans=0;
    stack<int> s;
    cin>>n;
    while(n--)
    {
        cin>>num;
        while(!s.empty()&&num>=s.top())s.pop();
        ans+=s.size();
        s.push(num);
    }
    cout<<ans;
}