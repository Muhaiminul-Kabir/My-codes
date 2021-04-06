#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    char ch[46788];
    for(int i = 0;;i++){
        ch[i] = _getch();
        
        if(ch[i]=='\n'){
          ch[i] = '\0';
              break;
        
        }
        cout<<'*';
        
    }
    cout<<endl<<ch;
    return 0;
}