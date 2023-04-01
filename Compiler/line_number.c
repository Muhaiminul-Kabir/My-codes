#include <stdio.h>
#include <complex.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>

int ln = 1;

int main(void) {



	  FILE * p1, * p2;
	  int in = 0;
	  char c;
	  char f = '\0';
	  p1 = fopen("play.c", "r");
	  p2 = fopen("output.txt", "w");
	  if (!p1) printf("\nFile can't be opened!");
	  else {
	    while ((c = fgetc(p1)) != EOF) {
	      	char buffer[20];
    		itoa(ln,buffer,10);
	      	if(f == '\n' || f == '\0'){
	      		for (int i = 0; i < (int)log10(ln)+1; ++i)
	      		{
	      			fputc(buffer[i],p2);
	      		}
	      		fputc(':',p2);
	      		ln++;
	      	}
	      	fputc(c,p2);
	    	

	        
	        
	        f = c;
	        
	    }
	    
	  }



	  fclose(p1);
	  fclose(p2);
	  p2 = fopen("output.txt", "r");
	  while ((c = fgetc(p2)) != EOF)
	    printf("%c", c);
	  fclose(p2);
	  return 0;
}
