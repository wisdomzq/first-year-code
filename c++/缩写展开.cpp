#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[2001];
bool judge(char m,char n)
{
    if(m>='a'&&m<='z')
    {
        if(n>='a'&&n<='z'&&n>m)return 1;
        return 0;
    }
     if(m>='A'&&m<='Z')
    {
        if(n>='A'&&n<='Z'&&n>m)return 1;
        return 0;
    }
     if(m>='0'&&m<='9')
    {
        if(n>='0'&&n<='9'&&n>m)return 1;
        return 0;
    }
    return 0;
}
int main()
{
    gets(a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i+1]!='-') cout<<a[i];
        if(a[i+1]=='-')
        {
            if(judge(a[i],a[i+2])==0)
            cout<<a[i]<<a[i+1]<<a[i+2];
            if(judge(a[i],a[i+2])==1)
            {
                for(int j=int(a[i]);j<=int(a[i+2]);j++)
                cout<<char(j);
            }
            i+=2;
        }
    } 
    cout<<endl;
}