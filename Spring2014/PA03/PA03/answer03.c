//#include <answer03.h>
// answer03.h not working
#include <stdlib.h>
#include <string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  char * buffer; 
  int length;
  if(*dest!=NULL)
    {
      return NULL;
    }

  length = strlen(*dest);
  length+= strlen(src);
  buffer = malloc(sizeof(char)*2*(strlen(*dest)+strlen(src)+1));
  *n=strlen(buffer);
  strcpy(buffer,*dest);
  free(dest);
  *dest=buffer;
  strcat(*dest,src);
  return *dest;
}

char ** explode(const char * str, const char * delims, int * arrLen)
{
  int count;
  int len;
  int len2;
  int x = 0;
  int i;
  int * dnum;
  int * sizes;
  char ** final;
  char * temp;
  len = strlen(str);
  len2 = strlen(delims);
  //count number of delimeters in str
  for(x=0;x<len2;x++)
    {
      for(i=0;i<len;i++)
	{
	  if(str[i]==delims[x])
	    {
	      count++;
	    }
	}
    }
  i=0;

  //allocate space for array with size number of delims
  dnum = malloc(sizeof(int)*count);
  //arrloc find locations of delims in str put them in allocated array
  count=0;
  for(x=0;x<len;x++)
    {
      for(i=0;i<len2;i++)
	{
	  if(str[x]==delims[i])
	    {
	      dnum[count]=x;
	      count++;
	    }
	}
    }
  i=0;
  count++;
  //count is number of delims
  //count is added because of the last string needed;
  //sizes  make array of integers showing number of characters between delimeters
  sizes = malloc(sizeof(int)*count+1);
  sizes[0]=dnum[0];
  count--;
  for(i=1;i<count;i++)
    {
      sizes[i]=dnum[i]-dnum[i-1];
    }
  sizes[count]=len-dnum[count];
  i=0;
  //use loop to allocate memory into each value of **array
  final=malloc(sizeof(char*)*(count+1));
  for(i=0;i<count;i++)
    {
      final[i]=malloc(sizeof(char)*sizes[i]);
    }
  
  // use loop to place strings in final[1]
  for(i=0;i<count;i++)
    {
      temp=malloc(sizeof(char)*(sizes[i]));
      for(x=dnum[i];x<dnum[i+1];x++)
	{
	  
	  temp[x]=str[x];
	}
      final[i]=temp;
      free(temp);
    }
  for(i=dnum[count];i<len;i++)
    {
      temp[i]=str[i];
    }
  //
  return final;
  }

char * implode(char * * strArr, int len, const char glue)
{
  int i;
  int len2;
  int sum;
  //int count;
  char  *buffer;
  int * loc;
  int * sizes;
  int location;
  sizes = malloc(sizeof(int)*len+1);
  //get array of sizes of strings in strArr
  for(i=0;i<len;i++)
    {
      sizes[i]=strlen(strArr[i]);
    }
  //sums the sizes of the arrays. used for determining location of glue
  for(i=0;i<len;i++)
    {
      sum+=sizes[i]; 
    }
  loc = malloc(sizeof(int)*(len-1));
  location = sizes[1]+1;
  loc[0]=location;
  for(i=1;i<len;i++)
    {
      location+=sizes[i]+1;
      loc[i]=location;
    }
  
  buffer=malloc(sizeof(char)*(sum+len-1));
  buffer=strcat_ex(buffer,&len2,strArr[0]);
  buffer[loc[0]]=glue;
  for(i=1;i<len;i++)
    {
      buffer[loc[i]]=glue;
      buffer=strcat_ex(buffer,&len2,strArr[i]);
    }
  return buffer;
}

/*void sorStringArray(char * * arrString, int len)
{
  if(arrString==NULL)
    {
      return NULL;
    }
  qsort(arrString,len,sizeof(char*),order);//do we need to declare
}

void sortStringCharacters(char * str)
{
  int len;
  len = strlen(str);
  qsort(str,len,sizeof(char),order);
}
*/

void destroyStringArray(char * * strArr, int len)
{
  int i = 0;

  for(i=0;i<len;i++)
    {
      free(strArr[i]);
    }
  free(strArr);
}
