#include<iostream>
using namespace std;


class helllo{
    public:
        int c;
        helllo(int c){
            this-> c = c;
            cout<<"hi"<<c<<endl;
        }

};

typedef struct Vector3{
    float x;
    float y;
    float z;
    }v3;
    
typedef struct ai{
    v3 hp={1,3,3};
    v3 bp={2,2,2};
}AI;



int main()
{
    helllo t(4);
    helllo c(7);
    AI gk;
    gk.hp = {2,3,4};
    gk.bp = {2,3,4};
    for(int  i =0;i< 100;i++){
    
        
        if(i > 50){gk.hp.z--; gk.bp.z--;}
        else{ gk.hp.z++; gk.bp.z++;}
        cout << gk.hp.z<<" "<<gk.bp.z<<endl ;
    
    }
       
    return 0;
}