#include<iostream>
#include<cstring>
using namespace std;
int num(char k)
{
    if(k>='A'&&k<='Z')return k-'A';
    else return k-'a';
}
int main()
{
    char a[200];
    bool b=true;
    int n,len,head,rear,ans=0;
    cin>>a>>n;
    len=strlen(a);
    if(n==1||n>len)cout<<a;
    else
    {
        cout<<a[n-1];
        head=rear=n-1;
        head--;
        rear++;
        while(len>=rear||head>=0)
        {
            if(ans==len)break;
            if(head<0&&rear<len)cout<<a[rear],ans++;
            if(ans==len)break;
            if(rear>=len&&head>=0)cout<<a[head],ans++;
            if(ans==len)break;
            if(rear<len&&head>=0)
            {
            if(num(a[head])>num(a[rear]))cout<<a[rear]<<a[head],ans+=2;
            else cout<<a[head]<<a[rear],ans+=2;
            }
            if(ans==len)break;
            rear++;
            head--;
    }
   }
   cout<<endl;
}