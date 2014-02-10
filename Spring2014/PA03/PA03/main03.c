#include "answer03.h"

int main(int argc, char * * argv)
{
  char ** dest;
  const char * delim = ' ';
  int* len;
  char ** strary;
  char * test2;
  const char * test='test this function';
  new=strcat_ex(dest,len,'hello');
  *len=strlen(test);
  strary=explode(test,delim,len);
  test2=implode(strary,strlen(*strary),delim);
  
  
  
}
