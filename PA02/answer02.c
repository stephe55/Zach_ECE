#include "answer02.h"
#include <string.h>
#include <stdio.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  int len1;
  int len2;
  if((src==NULL)&(*dest == NULL))
    {
      return NULL;
    }
  else if((src==NULL)&(*dest != NULL))
    {
      return *dest;
    }
  else
    {
      if((*dest != NULL) & (src != NULL))
	{
	  len1 = strlen(*dest);
	  len2 = strlen(src);
	}
      if((*dest == NULL) || (*n<(len1+len2+1)) )
	{
	  char* buffer;
	  if((*dest != NULL))
	    {
	      len1=strlen(*dest);
	      len2=strlen(src);
	      buffer = malloc(sizeof(char)*(1+2*(len1+len2)));
	      *n=2*(strlen(*dest)+strlen(src));
	      buffer[0]='\0';
	      buffer = strcpy(buffer,*dest);
	      *dest = buffer;
	      *dest = strcat(*dest,src);
	    }
	  else
	    {
	      len2=strlen(src);
	      buffer = malloc(sizeof(char)*(1+2*len2));
	      *n=2*(strlen(src));
	      buffer[0]='\0';
	      *dest=buffer;
	      *dest=strcat(*dest,src);
	    }
      
	}
      else
	{
	  *dest = strcat(*dest,src);
	}

      return *dest;
    } 
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
  printf("str is %s\n", str);
  printf("the length of str is %d\n", *arrLen);
  i=0;
  i2=0;
  increment=0;
  dnum=0;
  //for loop that counts number of delims (dnum) in str
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
  printf("number of delims = %d\n", dnum);
  strArr=malloc(sizeof(char*)*(dnum+1));///memory error will need to free in main
  //statement for zero delimeters
   if(dnum==0)
  {
    printf("DNUM == ZERO\n");
    strArr[0]=malloc(sizeof(char)*(*arrLen+1));////////MEMORYERROR/////
    strArr[0]=strcpy(strArr[0],str);
    // printf("the length of strArr[0] is %d\n", strlen(strArr[0]));
    return strArr;
  }
  //malloc dlmary(dnum ) for indexes of delims
  dlmary=malloc(sizeof(int)*(dnum));
  //dlmary[0]=0 dlmary  dlmary[12]=arrLen
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

  //for loop i= 1 to i <arrLen placing delimiter indexes in dlmary
  //malloc obtains sizes for arrays in strArr
  strArr[0]=malloc(sizeof(char)*(dlmary[0]+1));
  strArr[0][dlmary[0]]='\0';
  // copying first string;
  memcpy(strArr[0],str,sizeof(char)*dlmary[0]);
  // printf("strArr[0]= |%s|\n",strArr[0]);

  for(i=1;i<(dnum);i++)
    {
      printf("\n");
      strArr[i]=malloc(sizeof(char)*(dlmary[i]-dlmary[i-1]));
      strArr[i][dlmary[i]-dlmary[i-1]-1]='\0';
      memcpy(strArr[i],str+dlmary[i-1]+1,sizeof(char)*(dlmary[i]-dlmary[i-1]-1));
      // printf("strArr[%d]= |%s|\n",i,strArr[i]);
      //printf("\n");
    }
  strArr[dnum]=malloc(sizeof(char)*(*arrLen-dlmary[dnum-1]));
  strArr[dnum][*arrLen-dlmary[dnum-1]-1]='\0';
  memcpy(strArr[dnum],str+dlmary[dnum-1]+1,sizeof(char)*(*arrLen-dlmary[dnum-1]-1));
  //printf("strArr[dnum]= |%s|\n",strArr[dnum]);
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
      printf("%s\n",new);
    }
      new=strcat_ex(&new,&newlen,(const char*)strArr[len-1]);
      return new;
}



