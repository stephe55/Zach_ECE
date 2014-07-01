#include <stdlib.h>
#include <stdio.h>
# include <string.h>
int main(int argc,char ** argv)
{
  int i =1;
  while(i<argc-1)
    {  
      printf("%s",argv[i]);
      printf(" ");
      i++;
    }
  if(argc>1)
    printf("%s",argv[argc-1]);
  printf("\n");
  return EXIT_SUCCESS;
}
