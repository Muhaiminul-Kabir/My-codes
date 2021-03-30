#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int i;
    int n;
    cin >>n;
   int *arr ;
    arr = (int *)malloc(n);
    for( i = 0; i < n; i++){
        cin>>arr[i];
    }
    for( i = 0; i < n; i++){
       if( arr[i]<arr[i + 1]){
            continue;
        }
     else{
           break;
        
        }
    
    }
    if(i == n-1){
        cout<<"Yes"<<endl;
    
    }
    else{
        cout<<"No"<<endl;
    
    }
    
    
}