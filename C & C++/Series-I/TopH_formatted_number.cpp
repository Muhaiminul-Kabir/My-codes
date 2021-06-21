#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;






void convertInt(char str[], long int a) {
    long int i, rem, count = 0, f;
    f = a;
    while (f != 0) {
        count++;
        f /= 10;
    }
    for (i = 0; i < count; i++) {
        rem = a % 10;
        a = a / 10;
        str[count - (i + 1)] = rem + '0';
    }
    str[count] = '\0';
}


int main()
{

    int x,i,j;

    cin >> x;
    char temp[100];

    convertInt(temp,x);
    int n ;
    n=strlen(temp);
    int r;
    int h;
    
    if(n == 6){
        r = 1;
    }
    else if(n == 9){
        r = 2;
    }
    else{r = n/3 ;}
    int y;

    char str1[100];
    int *o;
    o = (int*)malloc(4*r);

    if(n < 4 && x < 2000000000) {

        cout<<x;
    }
    else if(n> 3 && x < 2000000000) {

        if(x%1000 == 0) {
            strcpy(str1,"000");
            
            switch(n){
                
                case 5: y = x/ pow(10,(n-2));
                    break;
                case 8: y = x/ pow(10,(n-2));
                   break;
                case 9: y = x/ pow(10,(n-3));
                   break;
                 
                default: y= x/ pow(10,(n-1));
                break;
            }
        }
        else {

            for(i = 0; i<r; i++) {
                h = x %1000;

                x = x/1000;

                o[i] = h;
                //convertInt(rem[i].str,rem[i].rem0);

            }
            y = x;

        }
       
        //convertInt(str1,y);¹


        printf("%d",y);
        for(i = r - 1 ; i>=0; i--) {
            if(x % 1000 == 0){
                printf(",%s",str1);
            }
            else{
                printf(",%d",o[i]);
            }


        }




    }
