#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind;
  int num;
  FILE *f;
  
  for(ind=1;ind<argc;ind++)
    {
      if( strcmp(argv[ind],"--help")==0)
	{
	  printf("<help-message>");
	  return EXIT_SUCCESS;
	}
      else
	{
	  f = fopen(argv[ind],"r");
   
	  if (f==NULL)
	    {
	      fprintf(stderr, "cat cannot open %s \n", argv[ind]);
	      fclose(f);//seg fault here on unopenable files
	      return EXIT_FAILURE;
	    }
	  else
	    {
	      while((num=fgetc(f))!= EOF)
		{
		  fputc(num,stdout);
		}
	      fclose(f);
	    }
	}
    }
  return EXIT_SUCCESS;
}
