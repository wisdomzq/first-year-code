#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
struct tran{
	int c,p,t;
}a[100050];
struct sub{
	int c1,p1,t1,u1;
}b[100050];
struct bus{
	int c2,p2,t2;
}c[100050];
bool cmp1(sub x1,sub y1)
{
	return x1.t1<y1.t1;}
bool cmp(bus x2,bus y2)
{
	return x2.t2<y2.t2;	
}
int main()
{  
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int n,q=0,w=0,ans=0,m=1,z;
	bool flag,gg=true;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].c,&a[i].p,&a[i].t);
	for(int i=1;i<=n;i++)
	{
		if(a[i].c==0)b[++q].p1=a[i].p,b[q].t1=a[i].t+45;
			if(a[i].c==1)c[++w].p2=a[i].p,c[w].t2=a[i].t;
	}
	sort(b+1,b+1+q,cmp1);
	sort(c+1,c+1+w,cmp);
	for(int i=1;i<=q;i++)
	{ans+=b[i].p1;
		b[i].u1=1;
		}
		if(b[q].t1<c[1].t2)
		{
			for(int i=1;i<=w;i++)
				ans+=c[i].p2;
			cout<<ans;
			return 0;
		}
	for(int j=1;j<=w;j++)
		{
			flag=false;
		while(b[m].t1<c[j].t2&&m<q)m++;
			if((b[m].t1>=c[j].t2)&&(b[m].p1>=c[j].p2)&&((b[m].t1-45)<=c[j].t2)&&(b[m].u1==1))
			{
				b[m].u1=0;
				continue;flag=true;
			}
		if(flag==false)
		{
			if(m<q)
			{
				z=m;
				while(z<q)
				{
					if(gg=false)continue;
					z++;
				while((b[z].p1>=c[j].p2)&&((b[z].u1)==1)&&(b[z].t1>=c[j].t2)&&((b[m].t1-45)<=c[j].t2))
					{  
						b[z].u1=0;
						gg=false;
					}
					if(gg==true)ans+=c[j].p2;
				}
				
			}
				if(m==q)
				{
					for(int r=j;r<=w;r++)
					ans+=c[r].p2;
                    cout<<ans;
					return 0;
				}
				flag=false;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}