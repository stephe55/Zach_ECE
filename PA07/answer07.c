#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"
//#include "treefun.h"
#define TRUE 1
#define FALSE 0


HuffNode* HuffNode_create(int value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void HuffNode_destroy(HuffNode * tree)
{
  if(tree == NULL)
    return;
  HuffNode_destroy(tree->left);
  HuffNode_destroy(tree->right);
  free(tree);
  return;
}

Stack * Stack_create()
{
  Stack * x = malloc(sizeof(Stack));
  x->head = NULL;
  return x;
}

void StackNode_destroy(StackNode * x)
{
  if(x==NULL)
    return;
  StackNode_destroy(x->next);
  HuffNode_destroy(x->tree);
  free(x);
}
					      
void Stack_destroy(Stack * stack)
{
  if(stack == NULL)
    return;
  StackNode_destroy(stack->head);
  free(stack);
}

int Stack_isEmpty(Stack * stack)
{
  if(stack->head == NULL)
    return TRUE;
  else
    return FALSE;
}

HuffNode * Stack_popFront(Stack * stack)
{
  if(Stack_isEmpty(stack)){
    printf("returing null\n"); 
    return NULL;
  }
  HuffNode* tree = (stack->head)->tree;
  StackNode* tmp = stack->head;
  stack->head = (stack->head)->next;
  free(tmp);    
  return tree;//return item    
}

void Stack_pushFront(Stack * stack, HuffNode * tree)
{
  StackNode* SN = malloc(sizeof(StackNode));
  SN->tree = tree;
  SN->next = stack->head;
  stack->head = SN;
}

void Stack_popPopCombinePush(Stack * stack)
{ 
  // printf("sh->value = %d \n  shn->value = %d\n",stack->head->tree->value,stack->head->next->tree->value);
  HuffNode* tree = Stack_popFront(stack);
  HuffNode* tree2 = Stack_popFront(stack);
  //printf("tree->value = %d \n  tree2->value = %d\n",tree->value,tree2->value);
  HuffNode* root= HuffNode_create(tree->value + tree2->value);
  root->left = tree2;
  root->right = tree;
  Stack_pushFront(stack,root);
}

HuffNode * HuffTree_readTextHeader(FILE * fp)
{
  if(fp == NULL)
    {
      fprintf(stderr,"fp = NULL;");
      return NULL;
    }
  //size len =0;
  HuffNode* Hnode=NULL;
  Stack* stack= Stack_create();
  int ch = fgetc(fp);

  while(!feof(fp))
    {
      //conditions to deal with character
      if(ch == '1')
	{
	  ch = fgetc(fp);
	  Stack_pushFront(stack,HuffNode_create(ch));
	}
      else if(ch=='0')
	{
	  if((stack->head != NULL) && ((stack->head)->next!=NULL))
		Stack_popPopCombinePush(stack);	 
	  else if((stack->head != NULL) & ((stack->head)->next==NULL))
	    break;
	}
            	
      //get next charcter
      ch =fgetc(fp);
    }
  Hnode = Stack_popFront(stack);
  Stack_destroy(stack);
  //Hnode = (stack->head)->tree;
  return Hnode;
}

HuffNode * HuffTree_readBinaryHeader(FILE * fp)
{
  if(fp ==NULL)
    {
      fprintf(stderr,"fp=NULL");
      return NULL;
    }
  HuffNode* Hnode=NULL;
  Stack* stack = Stack_create();
  unsigned char byte;
  unsigned char result = 0;
  int  shift = 7;
  int ind=8;
  int ind2;
  size_t read;
  while(!feof(fp))
    {
      //retrieve byte each 8 increments
      if(ind == 8)
	{
	  read = fread(&byte,sizeof(char),1,fp); 
	  ind=0;
	}   
      shift = 7-ind;
      int bit = (byte >> shift) & 0x01;
      if(bit==0)
	{
	  ind++;
	  if((stack->head != NULL) && ((stack->head)->next!=NULL))
	    Stack_popPopCombinePush(stack);	 
	  else if((stack->head != NULL) & ((stack->head)->next==NULL))
	    break;	  
	}
      if(bit==1)
	{
	  ind++;

	  //for loop obtains the next 8 bits
	  result = 0;
	  for(ind2=7;ind2>=0;ind2--)
	    {	      
	      if(ind == 8)
		{		    
		  read = fread(&byte,sizeof(char),1,fp);//ind =0 shift 7  ind =7 shift 0
		  ind = 0;
		}
	      shift = 7-ind;
	      bit = (byte >>shift)  & 0x01;
	      bit =  bit << (ind2);
	      result = result | bit;
	      bit = 0;
	      ind++; 		    
	    }
	  Stack_pushFront(stack,HuffNode_create(result));	      
	  //need to push next 8bit character onto front of stack
	}      	
    }
  Hnode = Stack_popFront(stack);
  Stack_destroy(stack);
  return Hnode;
}
