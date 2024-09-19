#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    char s[100];
    stack<int> s1;
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        int num=0,tot=0;
        bool ju=false;
        if(s[i]=='*')
        {
            int be,en,ans;
            en=s1.top();
            s1.pop();
            be=s1.top();
            s1.pop();
            ans=be*en;
            s1.push(ans);
        }
        if(s[i]=='/')
        {
            int be,en,ans;
            en=s1.top();
            s1.pop();
            be=s1.top();
            s1.pop();
            ans=be/en;
            s1.push(ans);
        }
        if(s[i]=='-')
        {
            int be,en,ans;
            en=s1.top();
            s1.pop();
            be=s1.top();
            s1.pop();
            ans=be-en;
            s1.push(ans);
        }
        if(s[i]=='+')
        {
            int be,en,ans;
            en=s1.top();
            s1.pop();
            be=s1.top();
            s1.pop();
            ans=be+en;
            s1.push(ans);
           
        }
        while(s[i]>='0'&&s[i]<='9')
        {
            ju=true;
            num=s[i]-'0';
            tot=tot*10+num;
            i++;
        }
        if(ju) s1.push(tot);
        
    }
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }
}