#include<iostream>
using namespace std;

typedef struct Vector3{
    float x;
    float y;
    float z;
    }v3;
    
typedef struct ai{
    v3 hp={1,3,3};
    v3 bp={2,2,2};
}ai;



int main()
{
    ai gk;
    gk.hp = {2,3,4};
    for(int  i =0;i< 100;i++){
    
        
        if(i > 50){gk.hp.x--;}
        else{ gk.hp.x++;}
        cout << gk.hp.x<<endl ;
    
    }
       
    return 0;
}