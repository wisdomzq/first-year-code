#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,ans;
	ans=0;
	cin>>n;
	while(ans<n) 
	{
		ans++;
		char s[1500],a1[501],b1[501],tmp[501];
		int a[501],b[501],c[600],p,tem,len;
		cin>>s;
		tem=0;
	for(int i=0;i<strlen(s);i++)
	{if((s[i]=='+')||(s[i]=='-'))p=i;
	a1[i]='\0',b[i]='\0';
	}
	
	for(int i=0;i<p;i++)
	a1[i]=s[i];
	for(int i=p+1;i<strlen(s);i++)
		b1[i-p-1]=s[i];
	 int lena=p;
    int lenb=strlen(s)-p-1;
    if(s[p]=='-')
    {
    	if ((lena<lenb) || (lena==lenb && strcmp(a1,b1)<0))
	  {
        printf("-");
        strcpy(tmp,a1);
        strcpy(a1,b1);
        strcpy(b1,tmp);
        lena=strlen(a1);
        lenb=strlen(b1);
      }
      if(lena>lenb)len=lena;
		else len=lenb;
		for(int i=0;i<len+1;i++)c[i]=0,b[i]=0,a[i]=0;
    for (int i=0;i<lena;i++) 
        a[i]=a1[lena-i-1]-'0';
    for (int i=0;i<lenb;i++) 
        b[i]=b1[lenb-i-1]-'0';   
    for (int i=0;i<lena;i++)
	 {
        if (a[i]<b[i]) 
		{
            a[i+1]--;
            a[i]+= 10;
        }
        c[i]=a[i]-b[i];
    }
    for (int i=lena-1;i>=0;i--) {
        if (c[i]==0&&lena>1) 
            lena--;
        else
       break;  
    }
    for (int i=lena-1;i>=0;i--)
	cout<<c[i];
	}
	else
	{
		if(lena>lenb)len=lena;
		else len=lenb;
		for(int i=0;i<len+1;i++)c[i]=0,b[i]=0,a[i]=0;
	 for (int i=0;i<lena;i++) 
        a[i]=a1[lena-i-1]-'0';
    for (int i=0;i<lenb;i++) 
        b[i]=b1[lenb-i-1]-'0';
		for(int i=0;i<len;i++)
	 {
	 	c[i]+=a[i]+b[i];
	 	c[i+1]=c[i]/10;
	 	c[i]%=10;
	 }
		int add=0;
		if(c[len]!=0)add=1;
		for(int i=len+add-1;i>=0;i--)
		cout<<c[i];
	}
	cout<<endl;
	}
	}
	

