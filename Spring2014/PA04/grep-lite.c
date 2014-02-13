#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind =0;
  int quiet = 0;
  int invert=0;
  FILE * f;
  char* buffer;
  int count =1;
  int end=1;

    for(ind=0;ind<(argc-1);ind++)
      {
	
	if((strcmp(argv[ind], "-q")==0) || (strcmp(argv[ind],"--quiet")==0))
	  {
	    quiet = 1; 
	  }

	if(argv[argc-1][0]=='-')
	  {
	    fprintf(stderr,"last argument begins with -  ");
	    return 2;
	    
	  }
      }
    for(ind=1;ind<(argc-2);ind++)
      {
	if((strcmp(argv[ind],"-v")!=0)&&(strcmp(argv[ind],"-n")!=0) &&(strcmp(argv[ind],"-q")!=0) &&(strcmp(argv[ind],"--invert-match")!=0) &&(strcmp(argv[ind],"--line-number")!=0)&&(strcmp(argv[ind],"--quiet")!=0))
	{
	  fprintf(stderr,"incorrect argument\n");
	  return 2;
	}
	  
	  
      }
      
     for(ind=0;ind<(argc);ind++)
    {
      if( strcmp(argv[ind],"--help")==0)
	{
	  if(quiet==0)
	    {
	      printf("\n-v, --invert-match   select non-matching lines\n");
	      printf("\n-n, --line-number    print line numbers with output\n");
	      printf("\n-q, --quiet          suppress all output\n\n");
	    }
	  return EXIT_SUCCESS;
	}
      
      else if((strcmp(argv[ind],"-v")==0)||(strcmp(argv[ind],"--invert-match")==0))
	{
	  invert = 1;
	}
    }
       if(argc==1)
    {
      if(quiet ==0)
	{
	  printf("Not enough arguments!\n");
	}
      return EXIT_FAILURE;
    }
     
     if(invert==0)
    {
     
      f=fopen(argv[argc-2],"r");
      if(f==NULL)
	{
	  fprintf(stderr,"invalid argument");
	  return 2;
	}
      buffer =malloc(sizeof(char)*2000);
      while(!feof(f))
	{
	  if(fgets(buffer,2000,f)!=NULL)
	    {
	      if(strstr(buffer,argv[argc-1])!=NULL)
		{
		  if(quiet==0)
		    {
		      end=0;
		      printf("%d     ",count);
		      printf("%s",buffer);
		      printf("\n");
		    }
		   
		}
	      count++;
	      
	    }
	}
      free(buffer);
    }
     if(invert==1)
       {
	  f=fopen(argv[argc-2],"r");
      buffer =malloc(sizeof(char)*2000);
      while(!feof(f))
	{
	  if(fgets(buffer,2000,f)!=NULL)
	    {
	      if(strstr(buffer,argv[argc-1])==NULL)
		{
		  if(quiet==0)
		    {
		      end=0;
		      printf("%d",count);
		      printf("%s",buffer);
		      printf("\n");
		    }
		}
	      count++;
	    }
	}
      free(buffer); 
       }

 
  return end;
}
