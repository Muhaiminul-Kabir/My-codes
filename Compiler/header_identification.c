#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {

     

	  FILE * p1, * p2;
	  int in = 0;
	  char c;
	  char f = ' ';
	  p1 = fopen("header_identification.c", "r");
	  p2 = fopen("output.txt", "w");
	  if (!p1) printf("\nFile can't be opened!");
	  else {
	    while ((c = fgetc(p1)) != EOF) {
	      	
	    	if (c == '#' && (f == ' ' || f =='\n'))
	    	{
	    		in = 1;
	    	}

	      	if (in ==2 && c == '.'){
	        	fputc('.', p2);
	        	fputc('h', p2);
	        	fputc('\n', p2);
	        	in = 0;
	        }
	        

	        if (in == 1 && (f == '<'|| f == '\"')){
	        	in = 2;
	        }
	        
	        if(in == 2)
		    {
		        fputc(c, p2);

		    }
 
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
