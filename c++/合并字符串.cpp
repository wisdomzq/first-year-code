#include <iostream> 
using namespace std;   
void mergestr(char *, char *, char *);  
  
int main()  
{  
    char str1[100], str2[100], str3[200];  
    cin.getline(str1, sizeof(str1));  
    cin.getline(str2, sizeof(str2));  
    mergestr(str1, str2, str3);  
    cout<<str3<<endl;  
    return 0;  
} 
#include<cstring> 
void mergestr(char *a,char *b,char *c)
{    
	memset(c,0,101);
	int i=0,l=0;
	if(strlen(a)<strlen(b))
	mergestr(b,a,c);
	else
	{
		while(l!=strlen(b)&&i!=strlen(a))
	{
		if(b[l]>=a[i])
		{
			c[l+i]=a[i];
			i++;
		}
		else
		{
			c[l+i]=b[l];
			l++;	
		}	
	}
	if(i<strlen(a))
	{
		while(i<strlen(a))
		{
		c[l+i]=a[i];
		i++;
		}
	}
	if(l<strlen(b))
	{
		while(l<strlen(b))
		{
		c[l+i]=b[l];
		l++;
		}	
	}
	}
 } 
