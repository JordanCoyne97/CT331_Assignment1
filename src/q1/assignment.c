#include <stdio.h>

int main(int arg, char* argc[]){

  int a;
  int *b;
  long c;
  double *d;
  char **e;

  printf("size of a %lu \n", sizeof(a));
  printf("size of b %lu \n", sizeof(b));
  printf("size of b %ld \n", sizeof(c));
  printf("size of b %lu \n", sizeof(d));
  printf("size of b %lu \n", sizeof(e));
  
}