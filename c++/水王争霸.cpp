#include<iostream>
#include<cstring>
using namespace std;
struct member{
    char name[30];
    char score[300];
}mem[1005],tmp;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>mem[i].name>>mem[i].score;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
           int op=0,len1=strlen(mem[i].score),len2=strlen(mem[j].score);
            if(len1<len2)
            tmp=mem[i],mem[i]=mem[j],mem[j]=tmp;
            if(len1==len2)
            {
                while(mem[i].score[op]==mem[j].score[op])op++;
                if(mem[i].score[op]<mem[j].score[op])
                tmp=mem[i],mem[i]=mem[j],mem[j]=tmp;
            }
            
        }
    }
    for(int i=1;i<=n-1;i++)
     {
        int p,q=i;
        p=0;
        while(q+1<=n&&strcmp(mem[q].score,mem[q+1].score)==0) q++,p++;   
        if(p>0)
        {  
            for(int j=i;j<i+p;j++)
            {
               for(int k=j+1;k<=i+p;k++)
                 if(strcmp(mem[j].name,mem[k].name)>0&&strcmp(mem[j].score,mem[k].score)==0) 
                 tmp=mem[j],mem[j]=mem[k],mem[k]=tmp;
            }
            i+=p,p=0;
        }
     }
     for(int i=1;i<=n;i++)cout<<mem[i].name<<endl;
}