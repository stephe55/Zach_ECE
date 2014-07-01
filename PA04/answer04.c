#include "answer04.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>

#define FALSE 0
#define TRUE 1

static int Headercheck(ImageHeader * header);

Image * Image_loadbmp(const char * filename)
{
  FILE * fp=NULL;
  int err= FALSE;
  size_t read;
  ImageHeader Iheader;
  Image* im1=NULL;
  Image* im2=NULL;
  
  //opening file for reading
  if(!err)
    {
      fp=fopen(filename,"rb");
      if(fp==NULL)
	{
	  fprintf(stderr,"Failed to open %s",filename);
	  err = TRUE;
	}	
    }
  //reading header into Iheader
  if(!err)
    {
      read = fread(&Iheader,sizeof(ImageHeader),1,fp);
      if(read !=1)
	{
	  fprintf(stderr,"Failed to read header from the image %s\n",filename);
	  err=TRUE;
	}
    }
  //check header to be valid
  if(Headercheck(&Iheader)==FALSE)
    {
      fprintf(stderr,"invalid header\n");
      err=TRUE;
    }

  //Alocate space for the image, comment and pixels
  if(!err)
    {
      im1 = malloc(sizeof(Image));
	if(im1 = NULL)
	  {
	    fprintf(stderr,"Failed to allocate im1 structure\n");
	    err = TRUE;
	}
    }
  
  if(!err)
    {
      im1->width=Iheader.width;
      im2->height=Iheader.height;
    }
  //start her ////////////////////////////////////////
  return 0;
}

static int Headercheck(ImageHeader * header)
{
  if(header->magic_number != ECE264_IMAGE_MAGIC_NUMBER)
    {   
      return FALSE;
    }
  if(header->width == 0)
    {
      return FALSE;
    }  
  if(header->height==0)
    {   
      return FALSE;
    } 
  if(header->comment_len<2)
    { 
      return FALSE;  
    }  
  return TRUE;
}
