#include<stdio.h>
#include<string.h>
int a[5][5];
int search(int i,int j)
{
    int m=a[i][j];
    if(a[i][j-1]==m)return 1;
    if(a[i][j+1]==m)return 1;
    if(a[i-1][j]==m)return 1;
    if(a[i+1][j]==m)return 1;
    return 0;
}
main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int ju=1,to=1;
        memset(a,0,sizeof(a));
        for(int j=1;j<=4;j++)
        for(int k=1;k<=4;k++)
		{
			scanf("%d",&a[j][k]);
			if(a[j][k]==2048)
			to=0;
		}
         if(to==0)printf("NO\n");
		 if(to==0)continue;
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
         {
            if(ju==1)
            {
               if(search(j,k)==1)
            ju=0,printf("YES\n");
         } 
        }    
      } if(ju==1)printf("NO\n");
    }
}