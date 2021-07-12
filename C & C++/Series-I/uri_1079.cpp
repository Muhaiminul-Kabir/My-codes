#include<iostream>
#include<stdio.h>
using namespace std;
#define E <<endl
#define _N printf("\n");
struct st {
    float mem[3];

};
typedef st u;
int main()
{

    int wV[3] = {2,3,5};
    int tW = 10;
    int n,count =0;
    cin>>n;
    u *tcs;
    tcs = (struct st*)malloc(n*sizeof(struct st));
    float *b;
    b = (float*)malloc(n*sizeof(float));

    int i,j;

    i =j= 0;

    while(i < n) {
        j = 0;
        while(j< 3) {
            cin>>tcs[i].mem[j];
            j++;
        }
        i++;
    }
  
    i = 0;
    j = 0;
    float sum =  0,avg;
    while(i < n) {
        j = 0;


        while(j<3) {
            sum += tcs[i].mem[j] * wV[j];
            j++;
        }
        avg = sum/10;
        b[i] = avg;
        sum = 0;
        i++;
    }
    i = 0;
    while(i < n) {
        printf("%.1f",b[i]);_N
        i++;
    }


    free(tcs);
    free(b);
    return 0;
}
