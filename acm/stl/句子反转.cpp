#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    stack<string> s;
    string s1,s2;
    while(cin>>s1)  s.push(s1);

    while(!s.empty())
    {
           s2=s.top();
           if(s2[0]<='9'&&s2[0]>='0')
           {
            for(int i=s2.size()-1;i>=0;i--)cout<<s2[i];
            cout<<" ";
            s.pop();
           }
           else
           {
            for(int i=0;i<s2.size();i++)
            {
                if(s2[i]>='a'&&s2[i]<='z')s2[i]-=32;
                else s2[i]+=32;
               
            } cout<<s2<<" ";
                s.pop();
           }
    }
}