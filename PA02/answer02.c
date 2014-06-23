#include "answer02.h"
#include <string.h>
#include <stdio.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  if((*dest == NULL) || (*n<(strlen(*dest)+strlen(src)+1)) )
    {
      char* buffer;
      if(*dest != NULL)
	{
	  buffer = malloc(1+2*(strlen(*dest)+strlen(src)));
	  *n=2*(strlen(*dest)+strlen(src));
	   buffer = strcpy(buffer,*dest);
	   buffer=strcpy(buffer,src);
	   
	}
      else
	{
	  buffer = malloc(1+2*strlen(src));
	  *n=2*(strlen(src));
	  buffer = strcpy(buffer,src);
	}
      *dest = buffer;
    }
  else
    {
      *dest = strcat(*dest,src);
    }
  return *dest;

  
 
}


char * * explode(const char * str, const char * delims, int * arrLen)
{
  char ** strArr;
  int dnum;
  int i;
  int i2;
  int increment;
  int* dlmary;
  int* first;
  int* last;
  int ndx;
  
  i=0;
  i2=0;
  increment=0;
  dnum=0;
  //for loop that counts number of delims (dnum) in str
  while(str[i] != '\0')
    {
      while(delims[i2]!='\0')
      {
	if(str[i]==delims[i2])
	  {
	    increment = 1;
	  }
	i2++;
      }
      if(increment)
	{
	  dnum++;
	  increment=0;
	}
      i++;
    }
  strArr=malloc(sizeof(char*)*(dnum+1));
  //needs if statement for zero delimeters!!!!!
   if(dnum==0)
  {
    strArr[0]=malloc(sizeof(char)*arrLen);
    strArr[0]=strcpy(*strArr[0],str);     
    return strArr;
  }

  //malloc dlmary(dnum + 2) for indexes of delims
  dlmary=malloc(sizeof(int)*(dnum));
  //dlmary[0]=0 dlmary  dlmary[12]=arrLen
  i=0;
  i2=0;
  ndx = 0; 
  increment=0;
  while(str[i]!='\0')
    {
      while(delims[i2]!='\0')
	{
	  if(str[i]==delims[i2])
	    {
	      increment=1;
	      
	    }
	  i2++;
	}
      if(increment)
	{
	  dlmary[ndx]=i;
	  ndx++;
	  increment=0;
	}
      i++;
    }

  //for loop i= 1 to i <arrLen placing delimiter indexes in dlmary
  
  //malloc int array for sizes
  strArr[0]=malloc(sizeof(char)*dlmary[0]);

  for(i=1;i<(dnum-1);i++)
    {
      strArr[i]=malloc(sizeof(char)*(dlmary[i]-dlmary[i-1]-1));
    }

  //array of first values 

  //array of last values
  
  

   free(dlmary);

  return 0;
  }

