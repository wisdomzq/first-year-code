#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	double m,k,i,n;
	int j;
	cin>>n;
	k=1;
	j=2;
	m=double(n)/180*3.1415926535897932384626433832795028841971;
	i=pow(m,j)/j;
	while(i>=1e-6)
	{
		if(j%4==0)
		k=k+i;
		else k=k-i;
		for(int k=1;k<=2;k++)
		{
		    j++;
			i=i*m/j;
		}
	}
	
		if(j%4==0)
		k=k+i;
		else k=k-i;
	cout<<"i="<<j/2<<", "<<"cos("<<n<<")=cos("<<fixed<<setprecision(6)<<m<<")="<<fixed<<setprecision(6)<<k<<endl;
}
