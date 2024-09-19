#include<iostream>
using namespace std;
int main()
{
	int m,n,ans,m1,n1,m2,n2,ju;
		bool r;
		while(scanf("%d %d",&m,&n)!=EOF)
	{
		
		r=false;
		ju=0;
		ans=n/20;
		for(int i=ans;i>=0;i--)
		{
			n1=n;
			m1=m;
			n1-=i*20;
			m1-=i;
			ans=n1/12;
			for(int j=ans;j>=0;j--)
			{
			n2=n1;	
			m2=m1;
			n2-=j*12;
			m2-=j;
			m2=m2-n2/8;
			if((m2==0)&&(n2%8==0))
			{
			ju++;
			r=true;
			if(ju==1)cout<<"KFC  McDonald  PissaHut"<<endl;
				cout<<i<<" "<<j<<" "<<n2/8<<endl;
			}

			}
		}
		if(r==false)cout<<"No Solution!"<<endl;
	}
 } 
