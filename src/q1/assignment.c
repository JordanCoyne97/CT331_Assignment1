#include <stdio.h>

int main(int arg, char* argc[]){

  int a;
  int* b;
  long c;
  double* d;
  char** e;

  printf("size of a %lu \n", sizeof(a));
  printf("size of b %lu \n", sizeof(b));
  printf("size of c %ld \n", sizeof(c));
  printf("size of d %lu \n", sizeof(d));
  printf("size of e %lu \n", sizeof(e));
  
  return 0;
}