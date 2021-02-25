#include <stdio.h>

#include "string.h"
struct d {
    char pl[1000];
    int scr;
} temp;
int line() {
    FILE *f = fopen("i.txt","r");
    char us[100];
    int g;
    int count = 0;
    for(; !feof(f);) {
        fscanf(f,"%s %d",us,&g);
        count++;
        if(feof(f)) {
            break;
        }
    }
    return count;
}
int main() {
    int k = line();
    char z[1000];
    struct d x[k];
    FILE *a = fopen("i.txt","r+");

    for(int i = 0; i<k; i++) {
        fscanf(a,"%s %d",x[i].pl,&x[i].scr);
    }
    fclose(a);
    for(int i = 0; i<k; i++) {
        for(int j = i+1 ; j < k; j++) {
            if(x[i].scr < x[j].scr) {
                temp= x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    FILE *n = fopen("i.txt","w+");

 
    for (int i = 0; i < k; i++) {
        fprintf(n,"%s %d\n",x[i].pl,x[i].scr );
    }
    for (int i = 0; i < k; i++) {
        printf("%s %d\n",x[i].pl,x[i].scr );
    }
    fclose(n);
}
