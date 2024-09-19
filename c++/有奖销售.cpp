#include<iostream>
using namespace std;
int main()
{
	char sep;
	int a,b,c,d,total,m,jm,km,nm;
	cin>>a>>sep>>b>>sep>>c>>sep>>d>>total;
	for(int i=1;;i++)
	{
		m=total;
		m=m-i*a;
		if(m<0)break;
		else
		for(int j=i;;j++)
		{
			jm=m;
			jm=jm-j*b;
			if(jm<0)break;
			else
			for(int k=j;;k++)
			{
				km=jm;
				km=km-k*c;
				if(km<0)break;
				else
				for(int n=k;;n++)
				{
					nm=km;
					nm=nm-n*d;
					if(nm<0)break;
					else 
					if(nm==0) cout<<i<<","<<j<<","<<k<<","<<n<<endl;
				}
			}
		}
	}
}
