#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer07.h"
#include "treefun.h"
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
    return FALSE;
  else
    return TRUE;
}

HuffNode * Stack_popFront(Stack * stack)
{
  HuffNode* y;
  StackNode* tmpnode;
  y=stack->head->tree;//set to item to be returned
  tmpnode = stack->head->next;//set to next head
  free(stack->head);//free current head
  stack->head = tmpnode; //set head to next head
  return y;//return item
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
  int num1 = stack->head->tree->value;
  int num2 =  stack->head->next->tree->value;
  int value = num1 + num2;
  HuffNode* tree = HuffNode_create(value);
  tree->left = Stack_popFront(stack);
  tree->right = Stack_popFront(stack);
  Stack_pushFront(stack, tree);
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
	  //Stack_print(fp, &stack);
	}
      else
	{
	  Stack_popPopCombinePush(stack);
	  //Stack_print(fp, &stack);
	}
      //get next charcter
      fgetc(fp);
    }
  Hnode = Stack_popFront(stack);
  Stack_destroy(stack);
  fclose(fp);
  return Hnode;
}

unsigned char * Huffman_applyTree(FILE * fp, HuffNode * tree, size_t * len)
{
  return NULL;
}
