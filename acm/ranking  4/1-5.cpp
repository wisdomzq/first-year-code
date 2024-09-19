#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    char a[105];
    char b[4];
    strcpy(b,"PTA");
    cin>>n;
    while(n--)
    {
        gets(a);
        int k=strlen(a);
        if(a[k-1]!='?')
        cout<<"enen"<<endl;
        else 
        {
            if(strstr(a,b)!=NULL)cout<<"Yes!"<<endl;
            else cout<<"No."<<endl;
        }
    }
}