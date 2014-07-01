#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char ** argv)
{
  FILE* fp;
  int ch;
  char buffer[3000];

  if((argc==1)&(stdin!=NULL))
    {
      fgets(buffer,3000,stdin);
      fputs(buffer,stdout);
      return EXIT_SUCCESS;
    }
  
  if(argc<2)
    {
      fprintf(stderr,"%s is only input\n",argv[0]);
      return EXIT_SUCCESS;
    }

  if(strcmp(argv[1],"--help")==0)
    {
      fprintf(stdout,"Usage: cat-lite [--help] [FILE]...\n");
      fprintf(stdout,"With no FILE, or when FILE is -, read standard input.\n\n");    
      fprintf(stdout,"Examples:\n");
      fprintf(stdout,"  cat-lite README   Print the file README to standard output.\n");
      fprintf(stdout,"  cat-lite f - g    Print f's contents, then standard input, \n");
      fprintf(stdout,"                    then g's contents.\n");
      fprintf(stdout,"  cat-lite          Copy standard input to standard output.\n");
	      return EXIT_SUCCESS;
    }
  int i=1;
  for(i=1;i<argc;i++)
    {
      if(strcmp(argv[i],"-")!=0)
	{
	  fp = fopen(argv[i],"r");
	  if(fp==NULL)
	    {
	      fprintf(stderr,"cat cannot open %s\n",argv[i]);
	      return EXIT_FAILURE;
	    }
	  do
	    {
	      ch = fgetc(fp);
	      if(ch!=EOF)
		{ 
		  //fprintf(stdout,"%c",ch);
		  fputc(ch,stdout);
		}
	    }while(ch != EOF);
	  
	  fclose(fp);
	}
      else
  	{
  	  fgets(buffer,3000,stdin);
	  fputs(buffer,stdout);
  	}
    }
       
  return EXIT_SUCCESS;
}
