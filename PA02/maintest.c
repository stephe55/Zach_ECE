#include "answer02.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv)
{
  // test for strcat 
  /* char * str1 = NULL; //"Zach ";
  char * str2 ="Stephens\n";
  char * dest;
  int len = 3;
  int i;
  i=0;
  int * ptlen = &len;
  dest = strcat_ex(&str1,ptlen,str2);
  printf("\n\ndest is %s \n\n",dest);
  free(dest);
  */
   // test for explode
  printf("------------------\n Now test for explode function \n-----------------\n");
  char** arrstr;
  const char* delims = " ";
  int arrLen;
  const char* str3="My name is Zach Stephens";
  int i;
  char* impld;
  arrLen = strlen(str3);
  arrstr=explode(str3,delims,&arrLen);
  
  for(i=0; i<5;i++)// make sure i< number of delimeters plus 5
    {
      printf("arrstr[%d] is |%s| \n",i,arrstr[i]);
      
    }
      

  impld=  implode(arrstr,5,delims);
  printf("the impld string is \"%s\"\n",impld);
  free(impld);

  for(i=0; i<5;i++)// make sure i< number of delimeters plus 5
    {
      free(arrstr[i]);
    }
      free(arrstr);
  return 0;
}
