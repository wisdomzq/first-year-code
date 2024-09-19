#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int num,tmp,ans=0;
    char op;
    cin>>num;
    s.push(num%10000);
    while(cin>>op>>num)
    {
        if(op=='*')
        {
            tmp=(num*s.top())%10000;
            s.pop();
            s.push(tmp);
        }
        if(op=='+')  s.push(num%10000);
    }
    ans=s.top();
    s.pop();
    while(!s.empty())
    {
        ans+=s.top();
        ans%=10000;
        s.pop();
    }
    cout<<ans;
}