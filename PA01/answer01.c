
#include "answer01.h"

// NOTE: You are NOT to use the strings library on this assignment,
// as stated in the README.

// DO NOT BEGIN WORKING ON THIS FILE UNTIL YOU HAVE COMPLETELY AND
// THOROUGHLY READ THE README FILE!!!

int arraySum(int * array, int len)
{
  int sum;
  int i;
  sum = 0;
  for(i = 0;i<len;i++)
    {
      sum+=array[i];
    }
  
    return sum;
}

int arrayCountNegative(int * array, int len)
{
  int count;
  int i;
  count = 0;
  for(i=0;i<len;i++)
    {
      if(array[i]<0)
	count++;
    }
    
    return count;
}

int arrayIsIncreasing(int * array, int len)
{    
  int i;
  for(i=1;i<len;i++)
    {
      if(array[i]<array[i-1]);
      {
	return 0;
      }
    }
    return 1;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int i;
  int place;
  place =-1;
  for(i=0;i<len;i++)
    {
      if(haystack[i]==needle)
	{
	  place = i;
	}
    }
    return place;
}

int arrayFindSmallest(int * array, int len)//want index or value???????????
{
  int place;
  int i;
  if(len == 0)
    {
      return 0;
    }
  place = 0;
  for(i=1;i<len;i++)
    {
      if(array[i]<array[place])
	{
	  place = i;
	}
    }
    return place;
}

size_t my_strlen(const char * str)
{
  int i=0;
  int len;
  len = 0;
  while(str[i] != '\0')
    {
      len++;
      i++;
    }
    return len;
}

char * my_strchr(const char * str, int ch)// Why is it returning null???
{
  int i;
  int len;
  len = my_strlen(str);
  for(i=0;i<len+1;i++)
    {
      if(str[i] == ch)
	{
	  return (char*) &str[i];
	}
    }
  
  return NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int len1;
  int len2;
  int i1;
  int i2;
  len1 = my_strlen(haystack);
  len2 = my_strlen(needle);
  if(len2==0)
    {
      return (char*) haystack;
    }
  for(i1=0;i1<(len1-len2);i1++)
    {
      if(haystack[i1]==needle[0])
	{
	  while(haystack[i1+i2]==needle[i2])
	    {
	      i2++;
	    }
	  if(i2==len2)
	    {
	      return (char*) &haystack[i1];
	    }
	}
      i2=0;
    }
 
    return NULL;
}

char * my_strcpy(char * dest, const char * src)
{
  int len;
  int i;
  len = my_strlen(src);
  for(i=0;i<(len+1);i++)
    {
      dest[i]=src[i];
    }
    return dest;
}

char * my_strcat(char * dest, const char * src)
{
  int len;
  int len2;
  int i;
  len = my_strlen(dest);
  len2 = my_strlen(src);
  for(i=0;i<len2+1;i++)
    {
      dest[len+i]= src[i];
    }
  
  return dest;
}

int my_isspace(int ch)
{
  int out;
  out = 0;
  if((ch=='\f')|(ch=='\n')|(ch=='\r')|(ch=='\t')|(ch=='\v')|(ch==' '))
    {
      out = 1;
    }
    return out;
}

int my_atoi(const char * str)
{
  int white;
  int ret;
  int i;
  int neg;
  //int len;
  // len = my_strlen(str);
  i=0;
  white=my_isspace(str[i]);
  while(white==1)
    {	 
      i++;
      white = my_isspace(str[i]);
    }
  ret=0;

  if(str[i]=='-')
    {
      neg = i;
      i++;
    }
  while(('0' <= str[i])& (str[i]<= '9'))
    {
      ret=ret*10+(str[i]-'0');
      i++;
    }
  if(str[neg]=='-')
    {
      ret=ret*-1;
    }
    return ret;
}

