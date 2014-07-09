#include "answer05.h"
#include <stdlib.h>
#include <stdio.h>


void worker(int * arr,int wr_pos,int n,int pr);
void IncDecprint(int * arr,int wr_pos,int val);
void EvenOddprint(int * arr,int wr_pos,int val);
void EOPprint(int * arr,int wr_pos,int val);

//declare odd / even print function
/* int main(int argc, char** argv) */
/* { */
/*   int n = 5; */
/*   printf("\n---------all----------\n\n"); */
/*   partitionAll(n); */
/*   printf("\n-----decreasing-----\n\n"); */
/*   partitionDecreasing(n); */
/*   printf("\n-----increasing-----\n\n"); */
/*   partitionIncreasing(n); */
/*   printf("\n-------even-------\n\n"); */
/*   partitionEven(n); */
/*   printf("\n-------odd-------\n\n"); */
/*   partitionOdd(n); */
/*   printf("\n-------odd and even-------\n\n"); */
/*   partitionOddAndEven(n);    */
/*   printf("\n-------prime-------\n\n"); */
/*   partitionPrime(n); */

/*   return 0; */
/* } */

void partitionAll(int value)//0
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,0);
  free(arr);
}
//increasing 1
void partitionIncreasing(int value)//1
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,1);
  free(arr);
}
//decreasing 2
void partitionDecreasing(int value)
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,2);
  free(arr);
}
//even 3
void partitionEven(int value)
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,3);
  free(arr);
}

//odd 4
void partitionOdd(int value)
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,4);
  free(arr);
}

void partitionOddAndEven(int value)
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,5);
  free(arr);
}

void partitionPrime(int value)
{
  int* arr = malloc(sizeof(int)*value);
  worker(arr,0,value,6);
  free(arr);
}

void worker(int * arr,int wr_pos,int n,int pr)
{
  int i;
    if(n ==0)
    {
      if((pr==0)|(pr==1)|(pr==2))
	{
	  IncDecprint(arr,wr_pos,pr);
	}
      else if((pr == 3) | (pr == 4))
	{
	  EvenOddprint(arr,wr_pos,pr);
	}
      else if((pr==5)|(pr==6))
	{
	  EOPprint(arr,wr_pos,pr);
	}	 
      return;
    }		
    for(i=1;i<=n;i++)
      {
	arr[wr_pos]=i;
	worker(arr,wr_pos+1,n-i,pr);
      }	
}
void IncDecprint(int * arr,int wr_pos,int val)
{
  int i;
  int i2=0;
  int inc=1;
  int dec=1;
  //printf arr
  for(i=1;i<wr_pos;i++)
    {
      if((arr[i-1]>arr[i]) & (dec))
	  {
	    dec=1;
	    inc=0;
	  }
	else
	  {
	    dec=0;
	  }
	if((arr[i-1]<arr[i])&(inc))
	  {
	    inc=1;
	    dec=0; 
	  }
	else
	  {
	    inc = 0;
	  }
      }
    if((val==0)|((val==1)&(inc==1))|((val==2)&(dec==1)))
    {
      printf("= %d",arr[i2]);
      i2++;
      while(i2<wr_pos)
	{
	  
	  printf(" + %d",arr[i2]);
	  i2++;
	}
      printf("\n");
      return;
    } 
}


//make print funciton for odd&even / prime
void EOPprint(int * arr,int wr_pos,int val)
{

  int i=0;
  int i2=0;
  int oddeven=1;
  int prime=1;
  //printf arr
  while(i<wr_pos)
    {
      if(arr[i]==1)
	{
	  prime =0;
	}
      for(i2=2;i2<arr[i];i2++)//checks all values in arr are prime
	{
	  if((arr[i]%i2)==0)
	    {

	      prime = 0;
	    }
	}
      i++;
    }
    i=1;
 
  for(i=1;i<wr_pos;i++)    
    {
      if((((arr[i]+arr[i-1])%2)==1)&(oddeven))//check for odd even
	{
	  oddeven=1; 
	}
      else
	{
	  oddeven = 0;
	}
    }
  i2 = 0;
  if((val==0)|((val==5)&(oddeven==1))|((val==6)&(prime==1)))
    {
      printf("= %d",arr[i2]);
      i2++;
      while(i2<wr_pos)
	{	  
	  printf(" + %d",arr[i2]);
	  i2++;
	}
      printf("\n");
    }
}


void EvenOddprint(int * arr,int wr_pos,int val)
{
  int i;
  int i2=0;
  int even=1;
  int odd=1;
  //printf arr
  for(i=0;i<wr_pos;i++)
    {
      if(((arr[i]%2)==0) & (even))
	  {
	    even=1;
	    odd=0;
	  }
	else
	  {
	    even=0;
	  }
      if(((arr[i]%2)==1)&(odd))
	  {
	    odd=1;
	    even=0; 
	  }
	else
	  {
	    odd = 0;
	  }
      }
    if((val==0)|((val==3)&(even==1))|((val==4)&(odd==1)))
    {
      printf("= %d",arr[i2]);
      i2++;
      while(i2<wr_pos)
	{
	  
	  printf(" + %d",arr[i2]);
	  i2++;
	}
      printf("\n");
      return;
    } 
}
