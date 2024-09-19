#include<iostream> 
#include<cstring> 
using namespace std; 
int main() 
{ 
    int m; 
    char a[2001]; 
    while(cin>>m>>a) 
    { 
        int n=m,heada=0,headb=0; 
        char b[2001]; 
        while(headb<m) 
        { 
            if(a[n-1]>a[heada]) 
            { 
                b[headb]=a[heada]; 
                headb++,heada++; 
            } 
            if(a[n-1]<a[heada]) 
            { 
                b[headb]=a[n-1]; 
                headb++,n--; 
            } 
            if(a[n-1]==a[heada]) 
            { 
                int n1=n-1,heada1=heada; 
                while(a[n1-1]==a[heada1+1]) 
                n1--,heada1++; 
                if(a[n1-1]>a[heada1+1]) 
                { 
                b[headb]=a[heada]; 
                headb++,heada++; 
                } 
                if(a[n1-1]<a[heada1+1]) 
                { 
                b[headb]=a[n-1]; 
                headb++,n--; 
                } 
            } 
        } 
        if(m<=80) 
        { 
            for(int i=0;i<m;i++) 
        cout<<b[i];  
        cout<<endl; 
        } 
        else 
        { 
            int out1=0,out2=80,l=m; 
            while(l>80) 
            { 
                l-=80; 
                for(int i=out1;i<out2;i++)cout<<b[i]; 
                cout<<endl; 
                out1+=80,out2+=80; 
            } 
            for(int i=out1;i<m;i++)cout<<b[i]; 
            cout<<endl; 
        } 
    } 
}  