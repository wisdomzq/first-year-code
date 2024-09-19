#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int len,len2,len3,len4,jin,asc[1000],p,num;
	char a[100];
	memset(asc,0,sizeof (asc));
	char base[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
	jin=0;
	cin>>a;
	len=strlen(a);
	len2=8*len;
	while(len2%24!=0)
	len2++;
	len3=8*len;
	while(len3%6!=0)
	len3++;
	while(jin<len)
	{
		jin++;
		num=jin*8;
		p=int(a[jin-1]);
		while(p>0)
		{
			asc[num]=p%2;
			num--;
			p/=2;
		}
	}
	len4=0;
	while(len4<len3)
	{
		int ans=0;
		len4+=6;
		for(int i=1;i<=6;i++)	
		if(asc[len4+1-i]==1)
		ans+=pow(2,i-1);
		cout<<base[ans];
	}
	p=(len2-len3)/6;
	for(int i=1;i<=p;i++)cout<<"=";
	cout<<endl;
 } 
