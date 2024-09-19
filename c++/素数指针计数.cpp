#include <iostream>  
#include <cmath>  
using namespace std;  
  
int * input( int );           
int  PrimCount( int *, int );     
bool isPrim( const int );   
  
 
int * input(int n)   
{ 
int *p;
p=new int[n];
for(int i=0;i<n;i++)
cin>>p[i];
return p; 
} 
 
int PrimCount( int *p, int n)  // 统计n个整数中的素数数量  
{ 
int ans=0;
for(int i=0;i<n;i++)
if(isPrim(p[i])==true)ans++; 
return ans;
} 
 
  
bool isPrim(const int x)  
{   int i;  
    if ( x==2 ) return true;        // 是素数，返回1  
    if ( x<=1 || x%2==0 )    return false;   // 不是素数，返回0   
    for ( i=3; i<=sqrt(x); i+=2 )  
        if ( x%i==0 )   return false;   // 不是素数，返回0   
    return true;            // 是素数，返回1   
}  
  
int main()  
{   int n, count, *p;  
  
    cin >> n;             // 接受整数数量n  
    p = input( n );     // 调用函数输入n个整数   
    count = PrimCount( p, n );  // 对素数进行计数   
    cout << "PrimCount=" << count << endl;  
    return 0;  
}  