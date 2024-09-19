#include <iostream>  
using namespace std;  
  
void delch(char *);  
  
int main()  
{  
    char str[100];  
      
    cin.getline(str, sizeof(str));  
    delch( str );  
    cout << str <<endl;  
    return 0;  
}  
#include<cstring> 
void delch(char *a)
{
	char b[100];
	int n=0;
	memset(b,0,sizeof(b));
	for(int i=0;i<strlen(a);i++)
	{
	    int k;
		for(k=0;k<i;k++)
		{
			if(a[i]==b[k])
			break;
		}
		if(k==i)
		{
			b[n]=a[i];
			n++;
		}	
	}strcpy(a,b);
 } 
