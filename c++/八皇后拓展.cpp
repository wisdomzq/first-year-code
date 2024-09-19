#include<iostream>
using namespace std;
void search(int,int); 
void print();
int a[12][12];
int ans=0; 
int qu,n;
int main()
{
	cin>>n>>qu;
    for(int j=1;j<=n;j++)	
	for(int i=1;i<=n;i++)
	a[i][j]=0;
	for(int i=1;i<=n-qu+1;i++)
		search(1,i);
		cout<<ans<<endl; 
}
void search(int p,int m)//m为行 ，p为摆了几个皇后 
{
	int judge=0; 
	for(int i=1;i<=n;i++)
	{
		if(a[i][m]==0)//i为列，m为行 
		{  
			for(int j=1;j<=n;j++)//标记控制范围 
			{
				a[j][m]-=1,a[i][j]-=1;
				for(int k=1;k<=n;k++)
				 {
				 	if(k+j==i+m)a[k][j]-=1;
				 	if(k-j==i-m)a[k][j]-=1;
				 }
			}
			if(p==qu)
			{   
				judge=0;
				for(int j=1;j<=n;j++)
				{
					for(int k=1;k<=n;k++)
					{
						if(a[j][k]==0)
						{
							judge=1;break;	
						} 
					}
				}
				if(judge==0)
				{
					ans++;
					for(int j=1;j<=n;j++)
		     {
				a[j][m]+=1,a[i][j]+=1;
				for(int k=1;k<=n;k++)
				 {
				 	if(k+j==i+m)a[k][j]+=1;
				 	if(k-j==i-m)a[k][j]+=1;
				 }
		     }
				}
				//得到一个取法 
				else
				{
					for(int j=1;j<=n;j++)
		     {
				a[j][m]+=1,a[i][j]+=1;
				for(int k=1;k<=n;k++)
				 {
				 	if(k+j==i+m)a[k][j]+=1;
				 	if(k-j==i-m)a[k][j]+=1;
				 }
		     }//恢复 
				}	
			}//继续搜索 
			else
			{   
				for(int q=1;q<=n-qu-m+p+1;q++)
			{
		       search(p+1,m+q);
				for(int j=1;j<=n;j++)
			  {
				a[j][m]+=1,a[i][j]+=1;
				for(int k=1;k<=n;k++)
				 {
				 	if(k+j==i+m)a[k][j]+=1;
				 	if(k-j==i-m)a[k][j]+=1;
				 }
			  }//恢复 
		    }
	        }
	    }
}
 } 
