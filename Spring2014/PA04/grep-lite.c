#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind;
  //int num;
  int invert = 0;
  int line = 0;
  int quiet = 0;
  FILE *f;
  const char * buffer[2000];
  int * ptr;
  for(ind=0;ind<argc;ind++)
	{
	  if((strcmp(argv[ind],"-q")==1)||(strcmp(argv[ind],"--quiet")==1))
	    {
	      quiet = 1; 
	    }
	}
  for(ind=0;ind<(argc);ind++)
    {
      if( strcmp(argv[ind],"--help")==1)
	{
	  if(quiet==0)
	    {
	      printf("-v --invert-match select non-matching lines\n");
	      printf("-n, --line-number    print line numbers with output\n");
	      printf("-q, --quiet         suppress all output\n");
	    }
	  return EXIT_SUCCESS;
	}
      
      else if((strcmp(argv[ind],"-v")==0)||(strcmp(argv[ind],"--invert-match")==0))
	{
	  invert = 1;
	}
    }
      

  if(invert==0)
    {
      f = fopen(argv[argc-2],"r");
      if(f==NULL)
	{
	  fprintf(stderr, "This is input is bogus!");
	  return 2;
	}
      while(fgets(buffer,2000,f)!=NULL)
	{
	  ptr = strstr((const)argv[argc-1],buffer);
	  if(ptr!=NULL)
	    {
	      for(ind=0;ind<2000;ind++)
		{
		  printf("%s",buffer[ind]);
		  printf("\n");
		}
       	}
	}
    }

      return EXIT_SUCCESS;
 }
