#include<iostream>  
#include<cstring>
using namespace std;  
void copy(int &x,int &y)      
{      
 x=y;         
}      
void copy(double &x,double &y)      
{      
x=y;     
}     
void copy(char x[],char y[])      
 {      
strcpy(x,y);     
}  
int main()  
{  
    int x, y;  
    double a, b;  
    char s[100], s2[100];  
    cin>>y; copy(x, y);  
    cin>>b; copy(a, b);  
    cin>>s2;copy(s, s2);  
    cout << "x=" << x << endl;  
    cout << "a=" << a << endl;  
    cout << "s=" << s << endl;  
    return 0;  
}  
