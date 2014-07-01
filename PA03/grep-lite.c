#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char** argv)
{
  int v=0;
  int n=0;
  int q=0;
  int sr=0;
  int num=1;
  FILE* fp=NULL;
  char line[2000];
  int search = 1;
  int val=1;
  //int pattern =2;
  int i=1;
 
 

  for(i=1;i<(argc);i++)
    {
      if(strcmp(argv[i],"--help")==0)
	{
	  fprintf(stdout,"Usage: grep-lite [OPTION]... PATTERN\n");
	  fprintf(stdout,"Search for PATTERN in standard input. PATTERN is a\n");
	  fprintf(stdout,"string. grep-lite will search standard input line by\n");
	  fprintf(stdout,"line, and (by default) print out those lines which\n");
	  fprintf(stdout,"contain pattern as a substring.\n\n");
	  fprintf(stdout,"  -v, --invert-match     print non-matching lines\n");
	  fprintf(stdout,"  -n, --line-number      print line numbers with output\n");
	  fprintf(stdout,"  -q, --quiet            suppress all output\n\n");
	  fprintf(stdout,"Exit status is 0 if any line is selected, 1 otherwise;\n");
	  fprintf(stdout,"if any error occurs, then the exit status is 2.\n");
	  return 1;
	}
  
      if((strcmp(argv[i],"-v")==0)| (strcmp(argv[i],"--invert-match")==0))
	{
	  v=1;
	  search++;
	}
      else if((strcmp(argv[i],"-n")==0)|(strcmp(argv[i],"--line-number")==0))
	{
	  n=1;
	  search++;

	}
      else if((strcmp(argv[i],"-q")==0)|(strcmp(argv[i],"--quiet")==0))
	{
	  q=1;
	  search++;

	}
    }
  
  if(argv[argc-1][0]=='-')
    {
      fprintf(stderr,"Incorrect final argument.  Pattern must not begin with -\n");
      return 2;
    }
 
  if((argc==2) || (argv[argc-2][0]=='-'))
    {
      fp = stdin;//how to open file from standard inpt???????????????

    }
 else
   {
    
      fp = fopen(argv[search],"r");
   }
  if(fp==NULL)
    {
      fprintf(stderr,"grep cannot open fp\n");
      return 2;
    }
  // printf("entering while loop\n");
  while(fgets(line,2000,fp) != NULL)
    {     //printf("argv[%d] = %s\n",argc,argv[argc]);
      if((strstr((const char*)line,argv[argc-1])!=NULL))
	{
	  sr=1;
	}
      if(((sr==1) & (v==0))|((sr==0) & (v==1)))
	{
	  val=0;//return 1 or 0
	  if(q==0)
	    {
	      if(n==1)fprintf(stdout,"%d:",num);
	      fputs((const char*) line,stdout);	
	    }
	}
        
      num++;
      sr=0;
   	
    }
  fclose(fp);
  return val;  
}
