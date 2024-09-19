#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,tap=0,hold=0,end=0;
    bool p=true;
    int judge[32]={0};
    scanf("%d",&n);
    while(p==true)
    {
       bool k=false;
       char a[32];
       scanf("%s",a);
            for(int i=0;i<strlen(a);i++)
            {   
                
                if(a[i]=='-')
              {
                if(judge[i]==1)
                tap++,judge[i]=0;
                if(judge[i]>1)
                hold++,judge[i]=0;
              }
                if(a[i]=='#') 
                judge[i]++,k=true;
            }
        if(k==false)end++;
        if(k==true)end=0;
        if(end==3)p=false;
    }
    printf("%d\n%d\n",tap,hold);
}