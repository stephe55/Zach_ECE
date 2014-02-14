#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind;
  int num;
  FILE *f;
  //printf("beginning\n\n\n\n");
  if(argc==1)
    {
      printf("sjdhfkl\n\n\n\n");
      for(ind = 0;ind<(argc-1);ind++)
	{
	  fprintf(stdout,"%s \n",argv[ind]);
	}
      return EXIT_SUCCESS;
    }
  
  for(ind=1;ind<argc;ind++)
    {
      if(strcmp(argv[ind],"-")!=0)
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
      else if (argc==2)
	{
	  for(ind=0;ind<argc;ind++)
	    {
	      printf("%s ",argv[ind]);
	    }
	  printf("\n");
	}
	
    }
  return EXIT_SUCCESS;
}
