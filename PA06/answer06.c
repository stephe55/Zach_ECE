#include <stdio.h>
#include "answer06.h"
#include <stdlib.h>



SparseNode * SparseNode_create(int index, int value)
{
  SparseNode * node = malloc(sizeof(SparseNode));
  node->index = index;
  node->value = value;
  node->left = NULL;
  node->right= NULL;
  return node;
}

SparseNode * SparseArray_insert(SparseNode * array, int index, int value)
{
  if(array == NULL)
    {
      if(value)
	{
	  return SparseNode_create(index,value);
	}
      else
	return array;
    }
  if(array->index == index)
    {
      array->value=value;
      return array;
    }
  if(index < array->index)
    {
      array->left = SparseArray_insert(array->left,index,value);
    }
  else
    {
      array->right = SparseArray_insert(array->right,index,value);
    }
  return array;
}

SparseNode * SparseArray_build(int * indices, int * values, int length)
{
  int ind;
  SparseNode * node=NULL;
  for(ind = 0;ind < length;ind ++)
    {
      node = SparseArray_insert(node,indices[ind],values[ind]);
      //printf("%d\n",ind);
    }
  return node;
}

void SparseArray_destroy(SparseNode * array)
{
  if(array == NULL) return;
  SparseArray_destroy(array->left);
  SparseArray_destroy(array->right);
  free(array);
}

int SparseArray_getMin(SparseNode * array)
{
  if(array == NULL) return -666;//EVIL NULL
  if(array->left == NULL)
    return array->index;
  else
    return SparseArray_getMin(array->left);
}

int SparseArray_getMax(SparseNode * array)
{
  if(array == NULL) return 666;//EVIL NULL
  if(array->right == NULL)
    return array->index;
  else
    return SparseArray_getMax(array->right);
}

SparseNode * SparseArray_getNode(SparseNode * array, int index)
{
  if(array == NULL)return NULL;
  if((array->index) == index) return array;
  if((array->index) < index)
    return SparseArray_getNode(array->right,index);
  else
    return SparseArray_getNode(array->left,index);  
}

SparseNode * SparseArray_remove(SparseNode * array, int index)
{
  SparseNode * new= NULL;
  int min;
  int tmp;
  if(array == NULL)return NULL;
  if(index<(array->index))
    {
      array->left = SparseArray_remove(array->left,index);
      return array;
    }
  else if(index>(array->index))
    {
      array->right= SparseArray_remove(array->right,index);
      return array;
    }
  else
    {
      if(((array->left)==NULL)&((array->right)==NULL))
	{
	  free(array);
	  return NULL;
	}
      else if((array->left)==NULL)
	{
	  new = array->right;
	  free(array);
	  return new;      
	}
      else if((array->right)==NULL)
	{
	  new = array->left;
	  free(array);
	  return new;
	}
      else
	{
	  min = SparseArray_getMin(array->right);
	  new = SparseArray_getNode(array,min);
	  tmp = new->value;
	  new->value=array->value;
	  array->value = tmp;
	  tmp = new->index;
	  new->index=array->index;
	  array->index=tmp;//both are swapped
	  //need to delete new
	  array->right=SparseArray_remove(array->right,index);
	  return array;
	}
    }
}

SparseNode * SparseArray_copy(SparseNode * array)
{
  //printf("ind = \"%d\"  value = \"%d\"\n",array->index,array->value);
  SparseNode * new= malloc(sizeof(SparseNode));
  if(array == NULL)
    {
      free(new);
    return NULL;
    }
  new->left = SparseArray_copy(array->left);
  //printf("ind = \"%d\"  value = \"%d\"\n",array->index,array->value);
  new->value = array->value;
  new->index = array->index;
  new->right = SparseArray_copy(array->right);
  return new;
}


SparseNode* merge_helper(SparseNode * x,SparseNode * y)
{
  SparseNode* node=NULL;
  if(y==NULL) return NULL;
  //go left
  y->left=merge_helper(x,y->left);
  //do something
  node = SparseArray_getNode(x,y->index);
  if(node != NULL)
    {
      node->value+=y->value;
    }
  else
    {   
      if(y->value != 0)
	{
	  x=SparseArray_insert(x,y->index,y->value);
	}
    }
  //go right
  y->right=merge_helper(x,y->right);
  return y; 
}

SparseNode * remove_zeros(SparseNode* x,SparseNode* y)
{
  if(y==NULL)
    {
      return NULL;
    }
  y->left=remove_zeros(x,y->left);
  if(y->value == 0)
    {
      x=SparseArray_remove(x,y->index);
    }
  y->right=remove_zeros(x,y->right);
  return y;
}

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2)
{
  SparseNode * new_1 = NULL;
  SparseNode * new_2 =NULL;
  SparseNode * new_3 = NULL;
  new_1 = SparseArray_copy(array_1);
  new_2 = SparseArray_copy(array_2);
  new_3 = merge_helper(new_1,new_2);
  SparseArray_destroy(new_2);
  new_2 = SparseArray_copy(new_1);
  new_3 = remove_zeros(new_2,new_1);//new_2 is edited new_1 finds zero values
  SparseArray_destroy(new_3);
  return new_2;
}
