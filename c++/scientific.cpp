#include<iostream>
using namespace std;
#define N 105
int a[N];
int main()
{
	char ch;
	bool zero=1,pd=0;
	int point=-1,n=0,sgn=1,num=0,cnt=0,i;
	ch=getchar();
	if(ch=='-')
	{
		ch=getchar();
		cout<<'-';
	}
	else if(ch=='+') pd=0,ch=getchar();
	while(ch=='0') ch=getchar();
	if(ch=='.')
	{
		point=0;
		while(ch=getchar(),ch=='0') --point;
		if(ch>'0'&&ch<='9') a[++n]=ch-'0',zero=0;
	}
	else
	{
		zero=0;
		a[++n]=ch-'0';
		while(ch=getchar(),ch>='0'&&ch<='9') a[++n]=ch-'0';
		if(ch=='.') point=n;
	}
	if(zero)
	{
		puts("0.00000000");
		return 0;
	}
	while(ch=getchar(),ch>='0'&&ch<='9') a[++n]=ch-'0';
	if(point==-1) point=n;
	while(ch=getchar(),ch==' '||ch=='e'||ch=='E');
	if(ch=='-')
	{
		sgn=-1;
		ch=getchar();
	}
	num=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9') num=num*10+ch-'0';
	point+=sgn*num;
	if(point<=0)
	{
		cout<<"0.";
		for(i=1;i<=-point;++i)
		{
			++cnt;
			if(cnt>8) break;
			cout<<'0';
		}
		if(cnt<8)
		{
			for(i=1;i<=n;++i)
			{
				++cnt;
				if(cnt>8) break;
				cout<<a[i];
			}
			if(cnt<8)
			{
				for(;cnt<8;++cnt) cout<<'0';
			}
		}
		cout<<endl;
	}
	else
	{
		for(i=1;i<=point;++i) cout<<(i<=n?a[i]:0);
		cout<<'.';
		for(i=1;i<=8;++i) cout<<(point+i<=n?a[point+i]:0);
		cout<<endl;
	}
	return 0;
}
