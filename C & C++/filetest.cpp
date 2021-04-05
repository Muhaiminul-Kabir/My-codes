#include "stdio.h"
void  newstd(FILE *f){
    char sy[1000];
    char h[2222];
      f = fopen("/storage/emulated/0/x.txt","a");
     printf("Enter name of student:\n");
    fgets(h, sizeof(h), stdin);
     printf("Enter ID of student:\n");
    fgets(sy, sizeof(sy), stdin);
    fprintf(f, "Name : %s", h);
    fprintf(f, "ID : %s", sy);
    fclose(f);
 }
void  restd(FILE *f){
    char sy[1000];
    char h[2222];
      f = fopen("/storage/emulated/0/x.txt","w");
     printf("Enter name of student:\n");
    fgets(h, sizeof(h), stdin);
     printf("Enter ID of student:\n");
    fgets(sy, sizeof(sy), stdin);
    fprintf(f, "Name : %s", h);
    fprintf(f, "ID : %s", sy);
    fclose(f);
    fscanf(f, "%[^\n]s", h);
    if(h[0] == ' '){
         f = fopen("/storage/emulated/0/x.txt","a");

         fprintf(f,"Session ended");
    }
    else if(h[0]!= ' '){
            restd(f);
    }
    
    
 }
void  constd(FILE *f){
    char t[] = "Session ended";
    char sy[1000];
    char h[2222];
      f = fopen("/storage/emulated/0/x.txt","a");
     printf("Enter name of student:\n");
    fgets(h, sizeof(h), stdin);
     printf("Enter ID of student:\n");
    fgets(sy, sizeof(sy), stdin);
    fprintf(f, "Name : %s", h);
    fprintf(f, "ID : %s", sy);
    fclose(f);
     
    fscanf(f, "%[^\n]s", h);
    if(h[0] == ' '){
         h[0] = '\0';
         f = fopen("/storage/emulated/0/x.txt","a");
      //    fgets(h, sizeof(h),stdin);
         
         fprintf(f,"\tIgnore last input\n\t  ,%s\n",t);
    }
    else if(h[0]!= ' '){
            constd(f);
    }
    
 }
int main()
{
    char c;
    FILE *f ;
    char x;
    char sentence[100];
    char se[100];
    for(;;){
        printf("1. Enter new student\n \n2.Rewrite whole record \n \n3. Enter data without stopping\n \nTo exit press any key except 1,2 & 3 \n");
        printf("\nIn case of dismissing  2 & 3  press enter [space] in student name\n \nEnter your choice \n");
        scanf("%c",&x);
        getchar();
        if(x == '1'){
            
            newstd(f);
       }
       else if(x == '2'){
         
         restd(f);
       }
        else if(x == '3'){
         
         constd(f);
       }
       else{
           printf("Do you want ro continue?(Y/N)");
           scanf("%c",&c);
           if(c == 'n')
           {
                puts("Program exited successfully");
                break;
           }
           else if(c == 'y'){
                continue ;
           }
       }
//  fscanf(f, "%[^\n]", sentence);
 //  puts(sentence);
   } 
   return 0;
}