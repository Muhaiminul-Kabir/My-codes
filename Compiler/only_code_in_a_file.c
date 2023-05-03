//Assignment - 1


#include <stdio.h>
#include <complex.h>
#include <math.h> 
#include <stdlib.h>
#include <string.h>

int ln = 1;
int scmblock = 0;
int mcmblock = 0;


int main(void) {

// Single Line Comment

 

	  FILE * p1, * p2;
	  int in = 0;
	  char c;
	  char f = '\0';
	  p1 = fopen("only_code_in_a_file.c", "r");
	  p2 = fopen("output.txt", "w");
	  if (!p1) printf("\nFile can't be opened!");
	  else {
//amar nam nirjon
	  	int comment = 0;
	  	int space_count = 0;

	    while ((c = fgetc(p1)) != EOF) {

	    	
/*sjndnjsndjn
dlkc,dmccjndc
dmckdmc
dmckdmc
dcmkdmc
dmckdmcd
cdkcmkdmc
dmckdmkcm
dcmkdm
cmkmd
cmkdmc
kd*/

	    	if (comment == 1 && c=='\n')
	    	{
	    		comment = 0;
	    	}else if(comment == 2 ){
	    		if(c == '/' &&f == '*'){comment = 0;}
	    		c = fgetc(p1);
	    	}

	    	if (comment == 0 && c == '/')
	    	{
				char ac = fgetc(p1);
				if (ac=='/')
			    {
					comment = 1;
				}else if (ac=='*')
				{
					comment = 2;
				}else{
					
					fputc('/',p2);

					fputc(ac,p2);  

				}


	    	}else if (comment == 0)
	    	{
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
