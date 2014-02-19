#include "answer05.h"
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#define FALSE 0
#define TRUE 1

/**
 * Loads an ECE264 image file, returning an Image structure.
 * Will return NULL if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
Image * Image_load(const char * filename);
{
  FILE * f = NULL; 
  Image * im1 = NULL;
  char* comment = NULL;
  ImageHeader  header;
  size_t read;
  int error = FALSE;
  

  
  if(!error)
    {
      f=fopen("filename","rb");
      if(!f)
	{
	  fprintf(stderr,"Unable to open file '%s', filename\n");
	}
      error=TRUE;
    }

  //read header
  if(!error)
    {
      read = fread(&header,sizeof(ImageHeader),1,f);
      if(read!=1)
	{
	  fprintf(stderr,"Failed to read header");
	  error = TRUE;
	}
    }
  
  if(!error)
    {
      if(header->magic_number != ECE_IMAGE_MAGIC_NUMBER )
	{
	  error = TRUE;
	}
    }


  if(!error)
    {
      if(header->width == 0)
	{
	  error = TRUE;
	}
    }



  if(!error)
    {
      if(header->height==0)
	{
	  error = TRUE;
	}
    }


  if(!error)
    {
      if(header.comment_length==0)
	{
	  error = TRUE;
	}
    }





  if(!error)
    {
      im1 = malloc(sizeof(Image));
      if(im1==NULL)
	{
	  fprintf(stderr,"Failed to allocate in structure\n");
	  error = TRUE;
	}
    }
  
  if(!error)
    {
      im1->width = image_264.width;
      im1->height = image_264.height;
      if
      
       
    }

  


 
  








}
/**
 * Save an image to the passed filename, in ECE264 format.
 * Return TRUE if this succeeds, or FALSE if there is any error.
 *
 * Hint: Please see the README for extensive hints
 */
int Image_save(const char * filename, Image * image);
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
void Image_free(Image * image);
{
  
}
/**
 * Performs linear normalization, see README
 */
void linearNormalization(int width, int height, uint8_t * intensity);
{
  
}
