#include "answer02.h"
#include <stdio.h>


// count length of C string str returns number of characters or null
size_t my_strlen(const char * str)
{
  size_t count;
  int i;
  i=0;
  count =0;
  while(str[i]!='\0')
    {
      i++;
      count++;
    }
  return count;
}

//counts number of occurrences of a character within string . returns integer of occurences
int my_countchar(const char * str, char ch)
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
  //char *p;
  int len;
  i=0;
  len= my_strlen(str);
  for(i=0;i<len;i++)
    {
      if(str[i]==ch)
	{
	  //p=&str[i];
	  return &str[i];
	}
    }
  //*p='\0';
  return NULL;
}
//returns first occurence from the right sight
char * my_strrchr(const char * str,int ch)
{
  int i;
  //char *p;
  int len;
  len=my_strlen(str);
  for(i=len;i>0;i--)
    {
      if(str[i]==ch)
	{
	  //p=&str[i];
	  return &str[i];  
	}
    }
  //*p=NULL;
  return NULL;
}

//returns the first occurence of a string within another string
char * my_strstr(const char * haystack, const char * needle)
{
  int len;
  int i;
  int i2;
  int len2;
  len=my_strlen(haystack);
  len2=my_strlen(needle);
  for(i=0;i<(len-len2);i++)
    {
      i2=0;
      while(haystack[i+i2]==needle[i2])
	{
	  if(i2==len2)
	    {
	      //p=&haystack[i];
	      return &haystack[i];
	    }
	  i2++;
	}
    }
  return NULL;
}
//copys src in memory pointed to by dest.
char * my_strcpy(char * dest, const char * src)
{
  int i;
  for(i=0;src[i]!='\0';i++)
    {
      dest[i]=src[i];
    }
  return dest;
  
}

//Append src to dest
char * my_strcat(char * dest, const char * src)
{
  int len;
  int len2;
  int i;
  int i2;
  i2=0;
  len = my_strlen(dest);
  len2 = my_strlen(src);
  for(i=(len+2);i<(len + len2 + 3);i++)
    {
      dest[i]=src[i2];
    }
  return dest;
}

//returns 1 when 'ch' is a whitespace character and 0 otherwise
int my_isspace(int ch)
{
  int status;
  if(ch=='\f'||ch=='\n'||ch=='\r'||ch=='\t'||ch=='\v'||ch==' ')
    {
      status=1;
    }
  else
    {
      status = 0;
    }
  return status;
}

//convert the intial portion of 'str' to an integer

int my_atoi(const char * str)
{
  int *ptr=0;
  int len;
  int i;
  i = 0;
  int count;
  ptr=my_strcpy(ptr,str);
  count=1;
  len = my_strlen(str);
  for(i=0;i<len;i++)//not sure how to increment
    {
      if(*ptr =='-')
	{
	  *ptr = '-';
	}
      if(ptr[i]>='0'&& ptr[i]<='9')
	{
	  ptr[count]=ptr[i];
	  
	}
    }
  count = ptr;// pointer to integer?
  return count;// not going to work
}

//main function
int  main(int argc, char * * argv)
{
  char array[50] = "Zach";
  char array2[50] = "Stephens";
  size_t length;
  int count;
  char key;
  key="z";
  char *ptr;
  printf("Hello World!\n");
  length=my_strlen(array);
  count = my_countchar(array,key);
  ptr = my_strchr(array, key);
  ptr = my_strrchr(array,key);
  ptr = my_strstr(array, array2);
  ptr = my_strcpy(array, array2);
  ptr = my_strcat(array,array2);
  count = my_isspace(key);
  count = my_atoi(array);
  printf("%d  %d  %d %p",length,count, key, ptr);
  return 0;
  
}

