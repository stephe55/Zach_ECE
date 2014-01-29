#include "answer02.h"
#include <stdio.h>


// count length of C string str returns number of characters or null
size_t my_strlen(const char * str)
{
  size_t count;
  int i;
  i=0
  count =0;
  while(str[i]!='/0')
    {
      i++;
      count++;
    }
  return count;
}

//counts number of occurrences of a character within string . returns integer of occurences
int my_countchar(const* char * str, char ch)
{
  int i;
  int lenstr;
  int count;
  count = 0;
  i=0;
  lenstr = my_strlen(str);
  for(i=0;i<lenstr;i++)
    {
      if(str[i]==ch)
	{
	  count++;
	}
    }
  return count;
}
//returnspointer of fist occurrence of a character in a string
char * my_strchr(const char * str, int ch)
{
  int i;
  char *p;
  i=0;
  len= my_strlen(str);
  for(i=0;i<len;i++)
    {
      if(str[i]==ch)
	{
	  p=&str[i];
	  return p;
	}
    }
  return '/0';
}
//returns first occurence from the right sight
char * my_strrchr(const char * str,int ch)
{
  int i;
  char *p;
  len=my_strlen(str);
  for(i=len;i>0;i--)
    {
      if(str[i]==ch)
	{
	  p=&str[i];
	  return p;  
	}
    }
  return '/0';
}
