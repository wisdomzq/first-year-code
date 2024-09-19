#include<iostream>
using namespace std;
int main()
{
    int g1,g2,x,y,z;
    int a=0,b=0;
    cin>>g1>>g2>>x>>y>>z;
    if(x==1)b++;
    else a++;
     if(y==1)b++;
    else a++;
     if(z==1)b++;
    else a++;
    if(b==3)
    cout<<"The winner is b: "<<g2<<" + "<<b;
        else 
        {
            if(a==3)
        cout<<"The winner is a: "<<g1<<" + "<<a;
        else
      {
       if(g1>g2)cout<<"The winner is a: "<<g1<<" + "<<a;
       else cout<<"The winner is b: "<<g2<<" + "<<b;
       }
        }
        
    }

