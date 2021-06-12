#include<stdio.h>


typedef enum silde {left,right,top,bottom}side;
side hitSide = right;//global

side p(){
    printf("x");
}

int main()
{
   side hitSide = top;
   p();
   if(hitSide == top){
        printf("y");
   }
   printf("%d",hitSide);
       
   return 0;
}
/** OUTPUT -- xy2 **/