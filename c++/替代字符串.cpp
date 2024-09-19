#include <iostream>  
using namespace std;  
  
void replstr(char *, char *, char *);  
  
int main()  
{  
    char str1[100], str2[100], str3[200];  
    cin.getline(str1, sizeof(str1));  
    cin.getline(str2, sizeof(str2));  
    cin.getline(str3, sizeof(str3));  
    replstr(str1, str2, str3);  
    cout<<str3<<endl;
    return 0;  
}  
#include<cstring>
char d[101]; 
void replstr(char* a, char* b, char* c)  
{  
    int a1,b1,c1,ans=0,t=0;
	a1=strlen(a);
	b1=strlen(b);
	c1=strlen(c);
	for(int i=0;i<100;i++)
	{
	  if(a[i]==b[0])
	  {
		if(b1==1)
		{
			for(int j=0;j<c1;j++)
			d[i+j+t]=c[j];
			t+=c1-1;
		}
		else
		{
			for(int j=1;j<b1;j++)if(a[i+j]==b[j])ans++;
			if(ans==b1-1)
			{
				for(int j=0;j<c1;j++)
				d[i+j+t]=c[j];
				t+=c1-b1;
				i+=b1-1;
			}
			else d[i+t]=a[i];
		}
	  }
	  else
	  d[i+t]=a[i];
	  ans=0;  
	}  
	for(int i=0;i<100;i++)c[i]=d[i]; 
}  
