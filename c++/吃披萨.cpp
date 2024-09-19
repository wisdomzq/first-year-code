#include<iostream>
using namespace std;
int main()
{
    int n;
    char op;
    cin>>n>>op;
    //第一行
    cout<<"#";for(int i=1;i<=n-2;i++)cout<<"-";cout<<"#"<<endl;
    //第二行
    cout<<"|";for(int i=1;i<=n-2;i++)
    {
        if(i%2==1)cout<<"*";else cout<<"-";
    }
    cout<<"|"<<endl;
    for(int i=1;i<=n-4;i++)
    {
        cout<<"|";
        if(i%2==0)cout<<"*";
        else cout<<"|";
        for(int j=1;j<=n-4;j++)cout<<op;
        if(i%2==0)cout<<"*";
        else cout<<"|";
        cout<<"|";
       cout<<endl;
    }
    cout<<"|";for(int i=1;i<=n-2;i++)
    {
        if(i%2==1)cout<<"*";else cout<<"-";
    }
    cout<<"|"<<endl;
    cout<<"#";for(int i=1;i<=n-2;i++)cout<<"-";cout<<"#"<<endl;
}