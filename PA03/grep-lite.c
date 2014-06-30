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
  FILE* fp;
  char line[2000];
  int search = 1;
  int val=0;
  int pattern =2;
  if(argc<2)
    {
      fprintf(stderr,"Need arguments\n");
      return 2;
    }
  if(strcmp(argv[1],"--help")==0)
    {
      fprintf(stdout,"<help-message>\n");
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
      fprintf(stdout,"</help-message>\n");
      return 1;
    }
  
  if(strcmp(argv[1],"-v")==0)
    {
      v=1;
      search++;
      pattern++;
    }
  else if(strcmp(argv[1],"-n")==0)
    {
      n=1;
      search++;
      pattern++;
    }
  else if(strcmp(argv[1],"-q")==0)
    {
      q=1;
      search++;
      pattern++;
    }
  

  if(argv[argc-1][0]=='-')//seg fault
  {
    fprintf(stderr,"Incorrect final argument.  Pattern must not begin with -\n");
    return 2;
  }

  fp = fopen(argv[search],"r");
  if(fp==NULL)
    {
      fprintf(stderr,"grep cannot open %s\n",argv[search]);
      return 2;
    }

  while(fgets(line,2000,fp) != NULL)
    {
      

      if((strstr((const char*)line,argv[pattern])!=NULL))
	{
	  sr=1;
	}
      if(((sr==1) & (v==0))|((sr==0) & (v==1)))
	{
	  val=1;
	  if((n==1) & (q==0))
	    {
	      fprintf(stdout,"%d  ",num);
	    }
	  if(q==0)
	    {
	      fputs((const char*) line,stdout);	
	    }
	}
        
      num++;
      sr=0;
   	
    }
 
  printf("\n");
  fclose(fp);
  return val;
  
}
