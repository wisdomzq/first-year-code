#include<iostream>
using namespace std;
int main()
{
    int a,p,q;
    char op;
    cin>>a>>op;
    if(a==1)cout<<op<<endl;
    else
    {
      for(int i=1;i<a;i++)cout<<"_";
    cout<<op;
    for(int i=1;i<=2*a-3;i++)cout<<"_";
    q=2*a-3;
    cout<<op;
    cout<<endl;
    p=a-1;
    for(int i=2;i<a;i++)
    {
        q-=2;
        for(int j=1;j<p;j++)cout<<"_";cout<<op;
        for(int k=1;k<=2*i-3;k++)cout<<"_";cout<<op;
        for(int i=1;i<=q;i++)cout<<"_";cout<<op;
        cout<<endl;
        p--;
    }
    if(a>1)
    {
        cout<<op;
        for(int i=1;i<=2*a-3;i++)cout<<"_";
        cout<<op;
        cout<<endl;
    }  
    }
    
}