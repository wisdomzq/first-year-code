#include<iostream>  
#include<fstream>  
using namespace std;  
int main()  
{  
    ifstream ifs;  
    char a[20],b[20],r[200],map[30][2];    
    cin>>a>>b;  
    int i=0;  
    ifs.open(a); 
    while(ifs>>r)  
    {  
        map[i][0]=r[0],map[i][1]=r[2];  
        i++;   
    }  
    ifs.close();    
    ifs.open(b);
    while(ifs.getline(r, sizeof(r)))  
    {  
        for(int m=0;m<sizeof(r);m++) 
        {
             for(int j=0;j<i;j++)  
                if(r[m]==map[j][0]) 
                {
                    r[m]=map[j][1]; break;
                }  
        } 
        cout<<r<<endl;
    }  
    ifs.close();  
}  