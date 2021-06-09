#include<iostream>
#include<math.h>
using namespace std;


float getDis(float theta , float v0){
  float dis;
  dis = (v0*v0*sin(2*theta))/g ;
  return dis;
}

float g = 9.8f ;
float u = 15;

float c = 10 * (3.1416/180);
int main()
{
    float x = 0.0f ,y;
    //y = tan(c)*x ;
    for(int i = 0;i< getDis(c,u) ; i++){
        x++;
       
        
         y = tan(c)*x - ((g*x*x)/((2*u*cos(c))*(2*u*cos(c))));
         
        cout <<x<<' '<<y<<endl;
    }
    return 0;
}