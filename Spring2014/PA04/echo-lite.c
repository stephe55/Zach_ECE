#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
  int ind;
  for(ind = 1;ind<argc; ind++)
    {
      //  if(*argv[ind] != '"')
	// {
	printf("%s",argv[ind]);
	// }
      printf(" ");
    }
  printf("\n");
  return EXIT_SUCCESS;
}
