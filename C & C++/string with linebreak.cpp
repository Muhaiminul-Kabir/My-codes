# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
using namespace std;
int main() {
    int LinePos=0;
    int Line_Break_Pos=0;
    int Line_Break=10;
    char abc[40]= {""};
    strcpy(abc,"mein hoon don. ");
    strcat(abc,"Don Don Don");
    cout << "\n" ;
    cout << "Without linebreak : \n";
    cout << abc ;
    cout << "\n\n" ;
    cout << "With linebreak : \n" ;
    while (LinePos < strlen(abc) ) {
        cout <<abc[LinePos];
        if (Line_Break_Pos > Line_Break && abc[LinePos ]==' ') {
            cout << "\n" ;
            Line_Break_Pos=0;
        }
        LinePos++;
        Line_Break_Pos++;
    }
    cout << "\n\n" ;
    return 0;
}