#include<iostream>
using namespace std;
void queen(int m);
bool row[12],line[12],rleft[25],rright[25];
int n;
int ans=0;
int main()
{
	
	cin>>n;
	for(int i=0;i<=n;i++)
		row[i]=true;
	for(int i=0;i<=2*n;i++)
	rleft[i]=rright[i]=true;
	queen(1);
	cout<<ans<<endl;
}
//m是列 
void queen(int m)
{
	for(int i=1;i<=n;i++)//i是行 
	{
		if(row[i]&&rleft[m+i]&&rright[m-i+n+1])
		{
			row[i]=rleft[m+i]=rright[m-i+n+1]=false;
			if(m==n)ans++;
			else queen(m+1);
			row[i]=rleft[m+i]=rright[m-i+n+1]=true;
		}
		
	}
}
