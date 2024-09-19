#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double x,e,p;
	cin>>x>>e;
	p=sqrt(x);
    while(abs(p*p-x)>=e)
    	p=(p+x/p)/2;
    	cout<<fixed<<setprecision(8)<<p<<endl;
}

