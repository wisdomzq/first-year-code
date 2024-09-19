#include<iostream>
#include<cmath>
using namespace std;
double pai(double,double);
double judge(double); 
double m,n;
double spe1(double);
double spe2(double,double);
double spe3(double);
int main()
{
	double cal=0,zho=0;
	cin>>n;
	m=pow(2,n+2);
	for(double i=m;i>=2;i--)
	{
		if((judge(i)==0)&&(i!=2))
		{
			zho=0;
			cal++;
			spe3(cal);
		}
		else
		if(((judge(i-1)==0)||(judge(i+1)==0))&&(i!=2))
			spe2(cal,1);
		else
		if(i==2)
			spe2(cal,0);
	    else
	    {
	   	zho++;
		pai(zho,cal);
		}	
	} 
	cal++;
	spe1(cal);
}
double judge(double k)
{
	double k2;
	k2=log(k)/log(2);
	if((k2-int(k2))==0)return 0;
	else return 1;
}
double spe1(double ji1)
{
	int q=m+10,chu,w=m;
	double n1,chu1,chu2;
	int zu[q];
	for(int i=1;i<=m;i++)zu[i]=0;
	chu=1;
	chu1=1;
	chu2=1;
	n1=n;
	zu[1]=1;
	zu[w]=1;
	for(int i=2;i<=ji1;i++)
	{
		chu+=pow(2,n1);
		zu[chu]=1;
		zu[w-chu+1]=1;
		n1--;
	}
	zu[chu]=0;
	zu[w-chu+1]=0;
	for(int i=1;i<=m;i++)
	{
		if(zu[i]==1)cout<<"+";
		else cout<<"-"; 
	}
	cout<<endl;
	}
double spe2(double ji2,double mark)
{
	int q=m+10,chu,w=m;
	double n1,chu1,chu2;
int zu[q];
	for(int i=1;i<=m;i++)zu[i]=0;
		chu=1;
	chu1=1;
	chu2=1;
	n1=n;
	zu[1]=1;
	zu[w]=1;
	for(int i=2;i<=ji2;i++)
	{
		chu+=pow(2,n1);
		zu[chu]=1;
		zu[w-chu+1]=1;
		n1--;
	}
	if(mark==0)
	{
		zu[chu-1]=0;
		zu[w-chu+2]=0;
	}
	for(int i=1;i<=m;i++)
	{
		if(zu[i]==1)cout<<"|";
		else cout<<" "; 
	}
	cout<<endl;
}
double pai(double ji4,double ji3)
{
	int q=m+10,w=m,w1=ji4,chu;
	double n1=n;
	int zu[q];
	for(int i=1;i<=m;i++)zu[i]=0;
	zu[1]=3;
	zu[w]=3;
	zu[w/2+w1+1]=1;
	zu[w/2-w1]=2;
	chu=1;
		for(int i=2;i<=ji3;i++)
	{
		chu+=pow(2,n1);
		zu[chu]=3;
		zu[w-chu+1]=3;
		n1--;
	}
	for(int i=1;i<=m;i++)
	{
		if(zu[i]==1) cout<<"\\";
		else
		if(zu[i]==2) cout<<"/";
		else
		if(zu[i]==3)cout<<"|";
		else cout<<" "; 
	}
	cout<<endl;	
}
double spe3(double ji3)
{

	int q=m+10,chu,w=m;
	double n1,chu1,chu2;
	n1=n;
	chu=1;
	chu1=1;
	chu2=1;
int zu[q];
	for(int i=1;i<=m;i++)zu[i]=0;
	if(ji3==1)
	{
	zu[1]=1;
	zu[w]=1;
	 }
	 else
	  {
 	zu[1]=3;
	zu[w]=3;
	  }
	for(int i=2;i<=ji3;i++)
	{
		chu+=pow(2,n1);
		zu[chu]=1;
		zu[w-chu+1]=1;
		n1--;
	}
	for(int i=1;i<=m;i++)
	{
		if((zu[i]==1)&&(i!=chu)&&(i!=(w-chu+1)))
		zu[i]=3;
	}
	for(int i=chu+1;i<=(w-chu);i++)
	zu[i]=2;
	for(int i=1;i<=m;i++)
	{
	if(zu[i]==1)cout<<"+";
	else
	if(zu[i]==2)cout<<"-";
	else 
	if(zu[i]==0)cout<<" ";
	else cout<<"|"; 
	}
	cout<<endl;
}







