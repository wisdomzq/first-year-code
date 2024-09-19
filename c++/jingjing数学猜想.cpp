#include<iostream>
#include<cstring>
using namespace std;
char ans[60];
int num;
void multi(char p[],char q[]);
int main()
{
    char a[201],a1[60],b1[60];//a1数组储存位数
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    int len,j=0;//len1是需要高精度乘法的位数
    cin>>a>>num;
    if(a[0]=='1'&&strlen(a)==1)cout<<1<<endl;
    else{
        len=strlen(a);
    for(int i=len-num;i<len;i++)
       a1[j]=a[i],j++;
    strcpy(b1,a1);
    int ans=1;
     multi(b1,a1);
     while(strcmp(b1,a1)!=0&&ans<1000)
     multi(b1,a1),ans++;
     if(ans<1000)cout<<ans<<endl;
     else cout<<-1<<endl; 
    }
       
}
void multi(char p[],char q[])
{
    int p1[60],q1[60],to[102];
    memset(p1,0,sizeof(p1));
    memset(q1,0,sizeof(q1));
    memset(to,0,sizeof(to));
    for(int i=0;i<num;i++)p1[i]=p[num-1-i]-'0',q1[i]=q[num-1-i]-'0';
    for(int i=0;i<num;i++){
        if(p1[i]>9||p1[i]<0)p1[i]=0;
        if(q1[i]>9||q1[i]<0)q1[i]=0;
    }
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            to[j+i]+=p1[i]*q1[j];
            to[j+1+i]+=to[j+i]/10;
            to[j+i]%=10;
        }
    }
    int total=2*num;
   
    for(int i=0;i<num;i++)p[num-i-1]=to[i]+'0';
}