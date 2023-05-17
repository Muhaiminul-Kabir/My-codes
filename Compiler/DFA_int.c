#include<stdio.h>


int ints1(char c){
    int dead = 1;
    if(c == 'i'){
          printf("f");
        dead = 0;

    }

    return dead;
}

int ints2(char c){
    int dead = 1;
    if(c == 'n'){
            printf("f");
        dead = 0;

    }


    return dead;
}

void intsFinal(char c){
    if(c == 't'){
printf("f");
        printf("Accepted");
    }else printf("Rejected");


}




int main(){
    int i = 0;
    int dead = 1;
    char f[] = {'i','n','t','f'};
    if(f[i] == 'i')
    {

        printf("f");
        dead = ints1(f[i]);
        if(!dead){
            i++;
            dead = ints2(f[i]);
        }
        i++;
        if(!dead && !f[++i]){
            i--;
           intsFinal(f[i]);
        }else{
            dead = 1;
        }



    }

        if(dead){
            printf("Rejected");
        }





}
