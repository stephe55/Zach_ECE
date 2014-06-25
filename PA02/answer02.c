#include "answer02.h"
#include <string.h>
#include <stdio.h>


int comp2(const void* x,const void* y);
int compchar(const void* x,const void* y);

char * strcat_ex(char * * dest, int * n, const char * src)
{
  int len1 = (*dest == NULL) ? 0 : strlen(*dest);
  int len2 = strlen(src);
 
  if((*dest == NULL) || (*n<(len1+len2+1)))
    {
      *n=1+2*(len1+len2);
      char* buffer = malloc(sizeof(char)*(*n));
      buffer[0]='\0';
      if(*dest) {
	strcpy(buffer,*dest);
	free(*dest);
      }
      *dest = buffer;
    }
  
  *dest = strcat(*dest,src);      

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
  int ndx;
  int Len;
  i=0;
  i2=0;
  increment=0;
  dnum=0;
  //for loop that counts number of delims (dnum) in str
  Len =strlen(str);
  while(str[i] != '\0')
    {
      i2=0;
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

  *arrLen=dnum+1;
  printf("the number of strings %d\n",*arrLen);

  strArr=malloc(sizeof(char*)*(dnum+1));///memory error will need to free in main


  //statement for zero delimeters
   if(dnum==0)
  {
    printf("DNUM == ZERO\n");
    strArr[0]=malloc(sizeof(char)*(Len+1));////////MEMORYERROR/////
    strArr[0]=strcpy(strArr[0],str);
    return strArr;
  }

  dlmary=malloc(sizeof(int)*(dnum));

  i=0;
  i2=0;
  ndx = 0; 
  increment=0;
  while(str[i]!='\0')
    {
      i2=0;
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

 
  strArr[0]=malloc(sizeof(char)*(dlmary[0]+1));
  strArr[0][dlmary[0]]='\0';

  memcpy(strArr[0],str,sizeof(char)*dlmary[0]);


  for(i=1;i<(dnum);i++)
    {
      printf("\n");
      strArr[i]=malloc(sizeof(char)*(dlmary[i]-dlmary[i-1]));
      memcpy(strArr[i],str+dlmary[i-1]+1,sizeof(char)*(dlmary[i]-dlmary[i-1]));
      strArr[i][dlmary[i]-dlmary[i-1]-1]='\0';

    }
  strArr[dnum]=malloc(sizeof(char)*(Len-dlmary[dnum-1]));
  strArr[dnum][Len-dlmary[dnum-1]-1]='\0';

  memcpy(strArr[dnum],str+dlmary[dnum-1]+1,sizeof(char)*(Len-dlmary[dnum-1]));

  free(dlmary);
  return strArr;
  }


char * implode(char * * strArr, int len, const char * glue)
{
  int i;
  char* new= NULL;
  int newlen;
  newlen=0;  
  for(i=0;i<len-1;i++)
    {
      new=strcat_ex(&new,&newlen,(const char*)strArr[i]); 
      new=strcat_ex(&new,&newlen,glue);      
    }
      new=strcat_ex(&new,&newlen,(const char*)strArr[len-1]);
      return new;
}


void sortStringArray(char * * arrString, int len)
{
  qsort((const void**)arrString,len,sizeof(char*),comp2);

}

int comp2(const void* x,const void* y)
{
   char** s1 = (char**) x;
   char** s2 = (char**) y;
   return strcmp(*s1,*s2);
}

void sortStringCharacters(char * str)
{
  int len = strlen(str);
  qsort((const void**)str,len,sizeof(char),compchar);
}


int compchar(const void* x,const void* y)
{
   char* c1 = (char*) x;
   char* c2 = (char*) y;
   return *c1-*c2;
}

void destroyStringArray(char * * strArr, int len)
{
  int i;
  for(i=0;i<len;i++)
    {
      free(strArr[i]);
    }
  free(strArr);
}
