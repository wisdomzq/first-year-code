#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char **a;
    int n,maxlen=0;
    cin>>n;
    a=new char *[n];
    for(int i=0;i<n;i++)
    a[i]=new char [10005];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
        if(strlen(a[i])>maxlen)maxlen=strlen(a[i]);
    for(int i=)
}