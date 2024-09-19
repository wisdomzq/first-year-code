#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double m,n;
	double out[10001],ans,min;
	int a[10001],b[10001];
	cin>>m>>n;
	cin>>a[1];
	min=10;
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		cin>>a[i]>>b[i];
		ans=ans+a[i]-b[i];
		if(ans>n)ans=n;
		out[i]=ans/n;
		if(out[i]<min)min=out[i];
		
	}
	for(int i=2;i<=m;i++)
	cout<<fixed<<setprecision(3)<<out[i]<<endl;
	
		for(int i=2;i<=m;i++)
		if(out[i]==min)cout<<i-1<<",";
	
	cout<<endl;
}
