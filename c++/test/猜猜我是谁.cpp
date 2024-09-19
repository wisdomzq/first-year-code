#include<iostream>   
#include<fstream>   
using namespace std;   
int main()   
{   
    ifstream ifs;   
    char a[20],r[200],map[30][2];    
    int n,i=0;  
    cin>>a>>n;     
    ifs.open(a);  
     if (!ifs.is_open()) 
    { 
   cout <<"File Name Error." << endl; 
     return 0; 
    } 
    while(ifs.getline(r, sizeof(r)))   
    {   
        i++; 
        if(i==n) 
        { 
            cout<<r<<endl; 
            return 0; 
        } 
    }   
    cout<<"Line No Error."<<endl; 
    ifs.close();     
     
} 