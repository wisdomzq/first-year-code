#include<iostream>
#include<cstring>
using namespace std;
char a[105];
int main()
{
    gets(a);
    int n,len,len_back,len_head=0;
    cin>>n;
    len=strlen(a);
    if(n>len)
    {
        puts(a);
        return 0;
    }
    len_back=len-n;
    if(len_back<n)len_head=n-len_back;
    if(len_head!=0)
    for(int i=0;i<len_head;i++)cout<<a[i];
    for(int i=len-1;i>=len-len_back;i--)
    cout<<a[i];
    cout<<endl;
}