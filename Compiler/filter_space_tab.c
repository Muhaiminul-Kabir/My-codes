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
	  p1 = fopen("filter_space_tab.c", "r");
	  p2 = fopen("output.txt", "w");
	  if (!p1) printf("\nFile can't be opened!");
	  else {

	  	 
	  	int space_count = 0;

	    while ((c = fgetc(p1)) != EOF) {

	    	
	     
	    	if (c==' ')
	    	{
	    		space_count++;
	    	}else if(c != '\n' && c!='\t'){
	    		if (space_count > 0)
	    		{
	    			fputc(' ',p2);
	    			fputc(c,p2);
	    			space_count = 0;
	    		}else{
	    			fputc(c,p2);
	    			
	    		}

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
