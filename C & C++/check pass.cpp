
/// COMMENT OFF WHEN Nesseccary 


#include<stdio.h>
#include<stdlib.h>

#include<string.h>

int checkpass(FILE *f,char *pass,char *filename){
    char a[9];
    char dp[]="/storage/emulated/0/Pass/";
    strcat(dp,filename);
    strcat(dp,".txt");
 
    f = fopen(dp,"r");
    int fd = getc(f);
    for(int i = 0;fd != EOF && i<9;i++){
        
          
         a[i]=fd;
          //   putchar(fd);
         //fgets(h,8,f);
           // puts(h);
          fd = getc(f);
            
         
    }
    for(int i = 0;i< 9;i++){
        if(pass[i]==a[i]){
            return 1;
        
        }
        else 
            return 0;
    
    }



}


int main()
{
    int a;
    FILE *f ;
    char filename[80];
    printf("Enter user name ~\t");
    
    gets(filename);
   
    char h[9];
    //int fd = getc(f);
    char dp[]="/storage/emulated/0/Pass/";
    strcat(dp,filename);
    strcat(dp,".txt");
    puts(dp);
    f= fopen(dp,"w");
    puts("Enter your password ~\t");
    fgets(h,sizeof(h),stdin);
    fprintf(f,"%s",h);
  //  fgets(h,9, stdin);
  
    
  /*  f= fopen(dp,"r");
     
       
   for(;fd != EOF;){
        
          
         
          //   putchar(fd);
         fgets(h,8,f);
            puts(h);
          fd = getc(f);
            
         
    }*/
    fclose(f);
    printf("check pass");
    char pass[9];
    fgets(pass,9,stdin);
    a = checkpass(f,&pass[0],&filename[0]);
    if(a == 1){
        printf("yoo");
    }
    else{
    
        printf("boo");
    }
    return 0;
}