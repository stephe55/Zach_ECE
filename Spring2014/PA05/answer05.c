#include "answer05.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

#define FALSE 0
#define TRUE 1
#define ECE264_IMAGE_MAGIC_NUMBER 0x21343632


/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename)
{
  FILE * f = NULL; 
  Image * im1 = NULL;
  // char* comment = NULL;
  ImageHeader  header;
  size_t read;
  int error = FALSE;
  int len;
  int test;
  
  if(!error)
    {
      f=fopen("filename","rb");
      if(!f)
	{
	  fprintf(stderr,"Unable to open file '%s', filename\n",filename);
	}
      error=TRUE;
    }

  //read header
  if(!error)
    {
      read = fread(&header,sizeof(ImageHeader),1,f);
      if(read!=1)
	{
	  fprintf(stderr,"Failed to read header of %s \n",filename);
	  error = TRUE;
	}
    }
  
  if(!error)
    {
      test = header.magic_number;
      if(test != ECE264_IMAGE_MAGIC_NUMBER )
	{
	  error = TRUE;
	}
    }


  if(!error)
    {
      test = header.width;
      if(test < 1)
	{
	  error = TRUE;
	}
    }



  if(!error)
    {
      test = header.height;
      if(test < 1)
	{
	  error = TRUE;
	}
    }


  if(!error)
    {
      test = header.comment_len;
      if(test < 1)
	{
	  error = TRUE;
	}
    }


  //allocate image struct
  if(!error)
    {
      im1 = malloc(sizeof(Image));
      if(im1==NULL)
	{
	  fprintf(stderr,"Failed to allocate in structure\n");
	  error = TRUE;
	}
    }


  //comment memory allocation
  if(!error)
    {
      im1->width = header.width;
      im1->height = header.height;
      len = header.comment_len;
      im1->comment = malloc(sizeof(char)*(len+1));//should use size char and len header.comment?
	if(im1->comment==NULL)
	  {
	    fprintf(stderr,"Failed to allocate memory for comment");
	    error = TRUE;
	  }
       
    }

  //read pixel data
  read = fread();
  


 
  








}
/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image)
{
  
}
/**
 * Free memory for an image structure
 *
 * Image_load(...) (above) allocates memory for an image structure. 
 * This function must clean up any allocated resources. If image is 
 * NULL, then it does nothing. (There should be no error message.) If 
 * you do not write this function correctly, then valgrind will 
 * report an error. 
 */
void Image_free(Image * image)
{
  if(image != NULL)
    {
      free(image->comment);
      free(image->data);
      free(image);

    }
  
}
/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity)
{
  
}
