#include<stdio.h>



static const char filename[] = "HIGH_SCORE_DR_IMMUNITY.txt";
int main() {
    FILE *file = fopen(filename, "r");
    int count = 0;
    if ( file != NULL ) {
        char line[256]; /* or other suitable maximum line size */ 
        while (fgets(line, sizeof line, file) != NULL) {
            /* read a line */   
              
            if (count<10) { //use line or in a function return it // //in case of a return first close the file with "fclose(file);"
                    printf("%s", line);
            }
            else{
                
                fclose(file);
                break;
                return 0;
            
            }
            count ++;
            
        }
        fclose(file);
    }
    return 0;
}