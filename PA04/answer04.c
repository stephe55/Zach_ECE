#include "answer04.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>

#define FALSE 0
#define TRUE 1

static int Headercheck(ImageHeader * header);

Image * Image_load(const char * filename)
{
  FILE * fp=NULL;
  int err= FALSE;
  size_t read;
  ImageHeader Iheader;
  Image* im1=NULL;
  //Image* im2 =NULL;
  size_t n_bytes = 0;
  
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
      if(read != 1)
	{
	  fprintf(stderr,"Failed to read header from the image %s\n",filename);
	  err=TRUE;
	}
    }
  //check header to be valid
  if(!err){
    if(!Headercheck(&Iheader))//Error unitialized value in headercheck!!!!!!!!
      {
	fprintf(stderr,"invalid header\n");
	err=TRUE;
      }
  }

  //Alocate space for the image, comment and pixels
  if(!err)
    {
      im1 = malloc(sizeof(Image));//error    block not freed!!!!!
	if(im1 == NULL)
	  {
	    fprintf(stderr,"Failed to allocate im1 structure\n");
	    err = TRUE;
	}
    }
  
  if(!err)
    {
      im1->width=Iheader.width;
      im1->height=Iheader.height;
      //THE comment
      n_bytes = Iheader.comment_len;
      im1->comment=malloc(n_bytes);//error on 16th byte!!!!!!!!!!!!
      if(im1->comment == NULL)
	{
	  free(im1);
	  fprintf(stderr,"could not allocate memory for im1->comment\n");
	  err = TRUE;
	}
    }
  if(!err)
    {
      read = fread(im1->comment,sizeof(char),Iheader.comment_len,fp);
      if(read != Iheader.comment_len)
	{
	  free(im1->comment);
	  free(im1);
	  fprintf(stderr,"was not able to read comment from file\n");
	  err = TRUE;
	}
    }
  if(!err)
    {     
      if(im1->comment[n_bytes-1]!='\0')
	{
	  free(im1->comment);
	  free(im1);
	  fprintf(stderr,"the comment does not end with null byte\n");
	  err=TRUE;
	}
      else
	{
	  //image data
	  n_bytes = sizeof(uint8_t)*Iheader.width*Iheader.height;
	  im1->data = malloc(n_bytes);
	  if(im1->data ==NULL)
	    {
	      free(im1->comment);
	      free(im1);
	      fprintf(stderr,"Unable to allocate memory for im1->data\n");	
	      err = TRUE;
	    }
	}
    }
  //read pixel data
  if(!err)
    {
      read = fread(im1->data,sizeof(uint8_t),(im1->height)*(im1->width),fp);   
      if(read !=(Iheader.height)*(Iheader.width) )
	{
	  free(im1->data);
	  free(im1->comment);
	  free(im1);
	  fprintf(stderr,"Only read %zd of %zd bytes of image data\n",read,n_bytes);
	  err = TRUE;
	}

    }
  if(!err)
    {
      uint8_t byte;
      //read = -1;
      read = fread(&byte, sizeof(uint8_t),1,fp);
      if(read !=0)
	{
	  Image_free(im1);
	  fprintf(stderr,"There are stray bytes at the end of the file\n");
	  err = TRUE;
	}	
    }
  if(err)
    {
      return NULL;
    }

  if(fp)
    {
      fclose(fp);
    }
  //im2=im1;
  //Image_free(im1);
   return im1;
}

int Image_save(const char * filename, Image * image)
{
  int err = FALSE;
  FILE * fp = NULL;
  uint8_t * buffer = NULL;
  size_t written = 0;
  
  //open file for writing;
  fp = fopen(filename,"wb");
  if(fp==NULL)
{
  fprintf(stderr,"FAiled to open '%s' for writing\n", filename);
  return FALSE;
 }

  //Number of bytes stored on each row
  size_t row_bytes = (image->width);

  //prepare the header
  ImageHeader Iheader;
  Iheader.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  Iheader.width = image->width;
  Iheader.height = image->height;
  Iheader.comment_len = strlen(image->comment)+1;
  
  //Write the header
  if(!err)
    {
      written = fwrite(&Iheader,sizeof(ImageHeader),1,fp);//err points to unitialized value
	if(written != 1)
	  {
	    fprintf(stderr,"Error:only wrote %zd of %zd of file header to '%s'\n",
		    written,sizeof(ImageHeader),filename);
	    err = TRUE;
	  }
    }
  written=fwrite(image->comment,Iheader.comment_len,1,fp);
  
  
  //Write a buffer
  buffer = malloc(row_bytes);//invalid write size of 1 during write
  if(buffer == NULL)
    {
      fprintf(stderr,"Error:failed to allocate wwrite bffer\n");
      err = TRUE;
    }
  else
    {
      memset(buffer,0,row_bytes);
    }
  
  //Write pixels
  if(!err)
    {
      uint8_t * readptr = image->data;
      int row,col;
      uint8_t * writeptr = buffer;
      for(row=0;row<Iheader.height  && ! err; ++row)
	{
	  writeptr=buffer;
	  for(col = 0;col < Iheader.width; ++col)
	    {//sets each row in buffer
	      *writeptr++ = *readptr;
	      readptr++;
	    }
	  //writing from buffer to file
	  written=fwrite(buffer,sizeof(uint8_t),row_bytes,fp);//err points to unitialized value
	  if(written !=row_bytes )
	    {
	      fprintf(stderr,"FAiled to write pixel data to file\n");
	      err=TRUE;
	    }
	}
    }
    
  //CLEANUP
  free(buffer);
  if(!err)fclose(fp);

  return !err;
    
}

void Image_free(Image * image)
{
  //if(image != NULL) 
  //{
      free(image->data);
      free(image->comment);
      free(image);
      //}
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int min = 255;
  int max = 0;
  int i=0;
  int i2=0;//nested loop
  int x =0;
  uint8_t cmp;

  for(x=0;x<height*width;x++)
    {
      	  cmp = intensity[x];
	  if(cmp<min)
	    {
	      min=cmp;
	    }
	  if(cmp>max)
	    {
	      max = cmp; 
	    }
    }
  
  for(i=0;i<height;i++)
    {
      for(i2=0;i2<width;i2++)
	{

	  intensity[i2+i*width]=(intensity[i2+i*width]-min)*255/(max-min);
	}
    }
  
}






static int Headercheck(ImageHeader * header)
{
  if(header->magic_number != ECE264_IMAGE_MAGIC_NUMBER)
    {   
      return FALSE;
    }
  if( (header->width==0))//conditional jump depends on unitialized value
    {
      return FALSE;
    }  
  if((header->height==0))
    {   
      return FALSE;
    } 
  if(header->comment_len<2)
    { 
      return FALSE;  
    }  
  return TRUE;
}
