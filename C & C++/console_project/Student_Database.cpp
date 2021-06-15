#include<stdio.h>
#include<string.h>

void file1(int n){
    for(int i = 1; i<=n ;i++){
        char  fnamen[10000];
        printf("enter student id: ");
        gets(fnamen);
        char dpath[]= "";
   
        char fnamew[] ="";
   
    
   
        char ext[5] = ".txt";
        strcat(fnamew,dpath); 		
        strcat(fnamew,fnamen); 			
        strcat(fnamew,ext);
    

    
        FILE *f = fopen(fnamew,"w"); 
    }  
}

void file(char *fnamen){
  
    char dpath[]= "";
   
    char fnamew[] ="";
   
    
   
    char ext[5] = ".txt";
    strcat(fnamew,dpath); 		
    strcat(fnamew,fnamen); 			
    strcat(fnamew,ext);
    

    
    FILE *f = fopen(fnamew,"w"); 
}

void enelse if rc(char *fnamen){

    char dpath[]= "";
   
    char fnamew[] ="";
   
    
   
    char ext[5] = ".txt";
    strcat(fnamew,dpath); 		
    	strcat(fnamew,fnamen); 			
    strcat(fnamew,ext);
    FILE *f = fopen(fnamew,"a");
       
    char h[2222];
    printf("Enter Semester:\n"); 
    fgets(h, sizeof(h), stdin); 
    fprintf(f, "Semester (%s)", h);
    for(int i = 0;i < 8; i++){
        printf("Enter course:\n"); 
        fgets(h, sizeof(h), stdin); 
        fprintf(f, "%s \n", h);
        
     }
     fclose(f);



}


void enid(char *fnamen){
    char dpath[]= "";
   
    char fnamew[] ="";
   
    
   
    char ext[5] = ".txt";
    strcat(fnamew,dpath); 		
    	strcat(fnamew,fnamen); 			
    strcat(fnamew,ext);
    FILE *f = fopen(fnamew,"w");

    char sy[1000]; 
    char h[2222];
    printf("Enter name of student:\n"); 
    fgets(h, sizeof(h), stdin); 
    printf("Enter ID of student:\n");
    fgets(sy, sizeof(sy), stdin);
    fprintf(f, "\t \t \t%s", h);
    fprintf(f, "ID : %s", sy); 
    fclose(f);
}
void cls() {
#ifdef __linux__ 
    printf("\e[1;1H\e[2J");
#elif _WIN32
    system("cls");
#else

#endif

}

int main()
{
    char fnamen[10000];
    int n;
    int a,b;
    for(;;){
        printf("   #####AUST STUDENTS DATABASE#####");
        printf("\n\n#1 Admit new Student\n#2 Enter Name and ID\n#3 Enter enrolled courses \n#  exit with any key");

        printf("\n-->>");
        scanf("%d",&a);
        getchar();
        if(a == 1){
            printf("\n");
            printf("enter number of records you want to create: ");
            scanf("%d",&b);
            getchar();
            
            file1(b);
            cls();
           
        }
        else if(a == 2){
            printf("\n");
            printf("enter student id: ");
            gets(fnamen);
            enid(fnamen);
            cls();
        }
        else if(a == 3){
            printf("\n");
            printf("enter student id: ");
            gets(fnamen);
            
            enrc(fnamen);
            cls();
        }
        
        else
            break;
   
    }    
   
    
    return 0;
}