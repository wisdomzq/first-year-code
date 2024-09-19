#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,ans,n;
	ans=0;
	scanf("%d/%d",&a,&b);
	cout<<"0.";
	while((a!=0)&&(ans<200))
	{
		ans++;
		a*=10;
		n=a/b;
		a=a%b;
		cout<<n;
	}cout<<endl;	
}
