
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This does not work... fix it.
void swapString(const char * a, const char * b)
{
  char *tmp;
  tmp = malloc(sizeof(char)*(strlen(a)+1));
  strcpy(tmp,a); 
  free((char*)a);
  a=malloc(sizeof(char)*(strlen(b)+1));
  strcpy((char*)a,b); 
  free((char*)b);
  b=malloc(sizeof(char)*(strlen(tmp)+1));
  strcpy((char*)b,tmp);

  
    printf("Calling swapString(...)\n");
    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&tmp = %p\n", &tmp);
}

int main(int argc, char * * argv)
{
    printf("Welcome to PA03.\n"
	   "\n"
	   "Please make sure that the swapString(...) function works\n"
	   "\n");
    
    printf("Print out some memory addresses for argc, argv...\n"
	   "to illustrate how memory is laid out.\n");
    printf("&argc = %p\n", &argc);
    printf("&argv = %p\n", &argv);
    printf("argv = %p\n", argv);
    printf("*argv = %p\n", *argv);
    printf("*argv = %s\n", *argv);
    printf("**argv = %c\n", **argv);

    // Let's create our own array of strings
    printf("\nTesting swapString(...)\n");
    const char * str1 = "one";
    const char * str2 = "two";
    printf("Before swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);
    swapString(str1, str2);
    printf("After swap, str1 == %p (i.e., '%s'), "
	   "str2 == %p (i.e., '%s')\n", str1, str1, str2, str2);

    return EXIT_SUCCESS;
}


