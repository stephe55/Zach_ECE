#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int sum;
  int i;
  sum = 0;
  for(i=0;i<len;i++)
    {
      sum = sum + array[i];
    }
    return sum;
}

int arrayCountNegative(int * array, int len)
{
  int i;
  int count;
  count=0;
  for(i=0;i<len;i++)
    {
      if(i<0)
	{
	  count++;
	}
    }
    return count;
}

int arrayIsIncreasing(int * array, int len)
{    
  int i;
  i=0;
  int value;

  for(i=1;i<len;i++)
    {
      if(array[i]< array[i-1])
	{
	  value=0;
	  return value;
	}
    }
  value = 1;
  return value;
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int i;
  int place;
  place = -1;
  i=0;
  for(i=0;i<len;i++)
    {
      if(haystack[i]==needle)
	{
	  place=i;
	}

    }
    return place;
}

int arrayFindSmallest(int * array, int len)
{
  int i;
  int small;
  small = 0;
  if(len==0)
    {
      return 0;
    }
  else
    {
      for(i=1;i<len;i++)
	{
	  if(array[i]<array[small])
	    {
	      i=small;
	    }
	}
    }
    return array[small];
}
