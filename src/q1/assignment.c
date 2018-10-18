#include <stdio.h>

int main(int arg, char* argc[]){

  int a;
  int* b;
  long c;
  double* d;
  char** e;

  printf("size of A %lu \n", sizeof(a));
  printf("size of B %lu \n", sizeof(b));
  printf("size of C %ld \n", sizeof(c));
  printf("size of D %lu \n", sizeof(d));
  printf("size of E %lu \n", sizeof(e));
  
  return 0;
}