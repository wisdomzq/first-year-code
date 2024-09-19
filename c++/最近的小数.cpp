#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int x,p1,q1,p2,q2;
 long double m,n,p,ans,min;
	min=10000000;
	cin>>m>>n>>x;
	ans=m/n;
	for(double i=1;i<=x;i++)
	{
		p=i*ans;
		p1=int(p)-1;
		q1=p1+2;
		for(double j=p1;j<=q1;j++)
		{
			if((min-abs(j/i-ans))>1e-15)
			{   
				min=abs(j/i-ans);
				p2=j,q2=i;
			}
		}
	}
	cout<<p2<<"/"<<q2<<endl;
}
