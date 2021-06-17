#include<iostream>
using namespace std;

int main()
{
    char ch[]="hu";
    unsigned char c[1000000];
    
   // strcpy(pass,ch)
    for(int i =0;ch[i]!='\0';i++){
        c[i] = ch[i]^0xAA;
        printf("%02X",c[i]); 
    
    }
    
    for(int i =0;ch[i]!='\0';i++){
        ch[i] = c[i]^0xAA;
        printf("%c",ch[i]); 
    
    }
    
    
    return 0;
}