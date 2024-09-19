#include<iostream>
#include<queue>
#include<functional>
int a[500001];
using namespace std;
int main()
{
    int k,m,num=0,leng=0;
    priority_queue<int,vector<int>,greater<int> > q1;
    cin>>k>>m;
    q1.push(1);
    while(!q1.empty())
    {
        int s=q1.top();
        int s1=s,len=0;
        q1.pop();
        num++;
        q1.push(2*s+1);
        q1.push(4*s+5);
        while(s1>0)
        {
            len++;
            s1/=10;
        }
        for(int i=leng+len;i>leng;i--)
        {
              a[i]=s%10;
              s/=10;
        }
        leng+=len;
        if(num==k)break;
    }
    for(int i=1;i<=leng;i++)cout<<a[i];
    cout<<endl;
    int last_len=leng-m,out=0,begin=1;
    while(out<last_len)
    {
        int max=0,mark;
        for(int i=begin;i<=(leng-(last_len-out)+1);i++)
        {
            if(a[i]>max)max=a[i],mark=i;
        }
        cout<<max;
        begin=mark+1,out++;
     
        
    }

}