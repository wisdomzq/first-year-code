#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int m,x,p1,q,time,fu1,p,k,l;
	long long ans;
	char a[60001];
	int fu[60000];
	long long shu[60000],tans[60000],tanfu[60000];
	cin>>x>>a;
	for(int i=0;i<60000;i++)shu[i]=0;
	p=strlen(a);
	fu1=0;
	fu[0]=-1;
	ans=a[0]-'0';
    for(int i=0;i<p;i++) 
	{
		if(a[i]=='-'||a[i]=='+'||a[i]=='*')
		{
			fu1++;
			fu[fu1]=i;
		}
    } 
    for(int i=0;i<fu1;i++)
    {
    	k=fu[i+1]-fu[i]-1;
    	while(k>0)
    	{
    	k--;
		shu[i]=shu[i]*10%x+a[fu[i+1]-k-1]-'0';
		}
		shu[i]%=x;
	}
    k=p-fu[fu1]-1;
    while(k>0)
    	{
    	k--;
		shu[fu1]=shu[fu1]*10%x+a[p-k-1]-'0';
		}
		shu[fu1]%=x;
		l=0;
   for(int i=1;i<=fu1;i++)
   {
   	if(a[fu[i]]=='*')
   	{
   		l++;
   		tanfu[l]=2;
		tans[l]=shu[i-1]*shu[i];
		tans[l]%=x;
		k=i+1;
   		while(a[fu[k]]=='*')
   		{
   		tans[l]*=shu[k];
   		tans[l]%=x;
		a[fu[k]]='N';
		k++;
		tanfu[l]++;	
	    }
	    tans[l]%=x;
    } 
   }
   ans=0,l=1,k=0;
   for(int i=0;i<p;i++)
   {
   	if(a[i]=='*'&&i==fu[1])
	   {
	   	k=1;
	   break;
	   }
   }
   if(k==1)
   {
   	l=1;
	ans=tans[l];
   	q=tanfu[l];
   	for(int i=2;i<=fu1;i++)
   	{
   	if((a[fu[i]]=='+'||a[fu[i]]=='-')&&a[fu[i+1]]!='*')
	   {
	   	if(a[fu[i]]=='+')
	   	{
	   	ans+=shu[q];
	   	q++;
	   }
		if(a[fu[i]]=='-')
	   	{
	   	ans-=shu[q];
	   	q++;
	   }
	   ans%=x;
	   }
	   if(a[fu[i]]=='*')
	   {
	   	l++;
	   	if(a[fu[i-1]]=='+') ans+=tans[l];
	    if(a[fu[i-1]]=='-')ans-=tans[l];
		q+=tanfu[l];	
		 ans%=x;
	   }	
    }
   }
   if(k==0)
   {
   	l=0;
    ans=shu[0];
    q=1;
   	for(int i=1;i<=fu1;i++)	
   	{
   	if((a[fu[i]]=='+'||a[fu[i]]=='-')&&a[fu[i+1]]!='*')
	   {
	   	if(a[fu[i]]=='+')
	   	{
	   		ans+=shu[q];
	   	q++;
		   }
		if(a[fu[i]]=='-')
	   	{
	   	ans-=shu[q];
	   	q++;
		   } ans%=x; 
	   }
	   if(a[fu[i]]=='*')
	   {
	   	l++;
	   	if(a[fu[i-1]]=='+') ans+=tans[l];
	    if(a[fu[i-1]]=='-')ans-=tans[l];
		q+=tanfu[l];
		ans%=x;		
	   }		
    }
   }
   while(ans<0)ans+=x;
   cout<<ans%x<<endl;;
}

