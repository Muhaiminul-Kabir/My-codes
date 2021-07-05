#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int i= 0,j =0;
int c = 0;
double cpuTime(int x[],int size,void (*p)(int*,int)) {
    clock_t t;
    t = clock();
    p(x,size);
    t = clock()-t;
    double time_taken = (double)t/CLOCKS_PER_SEC ;
    return time_taken ;
}

bool isSort(int x[],int size) {
    for (j = 0; j < size - 1; j++) {
        if(x[j] > x[j + 1]) {
            return false;
        }
    }
    cout<<endl<<"got here";
    return true;
}
void sortArr(int x[],int size) {
    for (; i < size; i++) {
        if(!isSort(x,size)) {
            for (int step = 1; step < size; step++) {
                int key = x[step];
                int j = step - 1;
                while (key < x[j] && j >= 0) {
                    x[j + 1] = x[j];
                    --j;
                }
                x[j + 1] = key;
            }
        }
        else break;
    }
}
int main() {
    void (*p)(int*,int);
    int x[] = {71,2,3,4,1,66,7};
    int size = sizeof(x) / sizeof(x[0]);
    p = &sortArr;
    double time = cpuTime(x,size,*p);
    cout<<endl;
    for (i = 0; i < size; i++) {
        cout << x[i] << " ";
    }
    cout<<endl<<"Program executed in "<<time<<"s";
}
