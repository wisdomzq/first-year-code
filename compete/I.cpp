#include<iostream>
using namespace std;
int main()
{
    int *time,*a,n,core,p=0,gap=1,max=0;
    bool shout=false,tot=true;
    cin>>n>>core;
    time=new int [n+2];
    a=new int [core+2];
    for(int i=1;i<=n;i++)cin>>time[i];
    for(int i=1;i<=core;i++) 
    {
        a[i]=0;
        if(p<n)
        {
        p++;
        a[i]=time[p];
        }
    }
    while(1)
    {
        shout=false;
        for(int i=1;i<=core;i++)
        {
             a[i]--;
             if(a[i]==0) 
             {
                shout=true;
                if(p<n)
                p++,a[i]=time[p];
             }
        }
        if(shout==false) gap++;
        if(shout==true) 
        {
            if(gap>max) max=gap;
            gap=1;
        } 
        tot=true;
        for(int i=1;i<=core;i++)
        {
            if(a[i]>0) tot=false;
        }
        if(p==n&&tot==true) break;
    }
    cout<<max<<endl;
}