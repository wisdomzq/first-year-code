#include<iostream>
#include<cmath>
using namespace std; 
int main()  
{  
    int a,b=0,c=0,d,e;  
    cin>>a; 
    d=a;  
    while(d>0)  
    {  
        d/=10;  
        b++;  
    }  
    d=a;  
    while(d>0)  
    {  
    e=d%10;  
    d/=10;  
    c+=pow(e,b);   
    }  
    if(c==a)
	cout<<"YES"<<endl;  
    else cout<<"NO"<<endl; 
	return 0;  
}  
