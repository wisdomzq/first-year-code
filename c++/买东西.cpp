#include <iostream>  
using namespace std;  
  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
  
int findm( int, int [ ][3], BUY [ ] );  
  
int main( )  
{   int i, j, n, min, price[10][3];  
    BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
    cin >> n;  
    for( i = 0; i < n; i++ )  
        for( j = 0; j < 3; j++ )  
            cin >> price[i][j];  
  
    min = findm( n, price, scheme );  
  
    cout << "Total Money are : " << min <<"\nGoods-Name  Shop-Name  Goods-Price\n";  
    for ( i=0; i<3; i++ )  
        printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice ); //这个应该用C++的语句，不改了   
    return 0;  
}  
int findm( int n, int gp[ ][3], BUY schm[ ] ) 
{
    int ans=0;
    bool b[1000];
    for(int i=0;i<n;i++)b[i]=true;
    for(int i=0;i<3;i++)
    {
        int min=100000,k;
         for(int j=0;j<n;j++)
         if(min>gp[j][i])min=gp[j][i];
         for(int j=0;j<n;j++)
         if(min==gp[j][i]&&b[j]==true){
            schm[i].sname=j+1,schm[i].gprice=gp[j][i],ans+=gp[j][i],b[j]=false;
            break;}
    }
    return ans;
}