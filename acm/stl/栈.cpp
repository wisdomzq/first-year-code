#include<iostream>
#include<stack>
#include<string>
typedef unsigned long long ull;
using namespace std;
int main()
{
    stack<ull> s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for(int j=1;j<=m;j++)
        {
            string s1;
            cin>>s1;
            if(s1=="push")
            {
                ull num;
                cin>>num;
                s.push(num);
            }
            if(s1=="query")
            {
                if(s.empty())cout<<"Anguei!"<<endl;
                else cout<<s.top()<<endl;
            }
            if(s1=="size")cout<<s.size()<<endl;
            if(s1=="pop")
            {
                if(s.empty())cout<<"Empty"<<endl;
                else s.pop();
            }
        }
        while(!s.empty())s.pop();
    }
}