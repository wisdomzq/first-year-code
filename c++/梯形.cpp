#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
   int r;
	float n,k,p,m,l;
	cin>>m>>n;
	k=n;
	if(m==1)
	{
		cout<<n<<endl; 
		return 0;
	}
	r=m;
		for(int j=1;j<=2*(m-1)+m;j++)
		{	
			if(j<=ceil((2*(m-1)+m)/2))
			{
				if(k>9)k-=10;
				cout<<k<<" ";
				k++;
				if((j==ceil((2*(m-1)+m)/2))&&(r%2==1))
				k--;
			}
		    else
		    if(j<2*(m-1)+m)
		    {
		    	k--;
		    	if(k<0)k+=10;
		    	cout<<k<<" ";
			}
			else 
			{
	         k--;
			 if(k<0)k+=10;
			cout<<k<<endl;
			}
		}
		k=n;
		for(int i=1;i<=m-2;i++)
		{
			for(int j=1;j<=2*i;j++)cout<<" ";
			k++;
			if(k>9)k-=10;
			cout<<k;
			l=2*(2*(m-1)+m)-1-2*(2*(i+1)-1);
			for(int k=1;k<=l;k++)cout<<" ";
			cout<<k<<endl;
		}
		for(int i=1;i<=2*(m-1);i++)cout<<" ";
		k++;
		l=ceil(m/2);
		for(int i=1;i<=l;i++)
		{
			if(k>9)k-=10;
			cout<<k<<" ";
			k++;
		}
		if(r%2==1)
		k--;
		for(int i=1;i<=(m-l);i++)
		{   k--;
			if(k>9)k-=10;
			if(k<0)k+=10;
			if(i<m-l)
			cout<<k<<" ";
			else cout<<k;
		}
		cout<<endl;
	}


