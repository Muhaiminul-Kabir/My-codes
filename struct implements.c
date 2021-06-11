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
    cout << gk.hp.x;
    return 0;
}