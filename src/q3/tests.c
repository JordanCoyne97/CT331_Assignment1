#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

void printChar(void *data){
  printf("%c\n", *(char*)data); 
}

void printStr(void *data){
  printf("%s\n", data); 
}

void printFloat(void *data){
  printf("%f\n", *(float*)data); 
}

void printDouble(void *data){
	printf("%lf\n", *(double*)data);
}

void printInt(void *data){
  printf("%d\n", *(int*)data); 
}

void runTests(){
  printf("Tests running...\n");

  char a = 'C';
  genericListElement *list = createEl(&a, sizeof(char), &printChar);
  traverse(list);
  length(list); 

  char str[] = "Programming";
  genericListElement *list2 = insertAfter(list, &str, sizeof(str), &printStr);
  traverse(list);
  length(list); 
   
  float f = 45.501;
  insertAfter(list2, &f, sizeof(f), &printFloat);  
  traverse(list);
  length(list); 

  double d = 123.12312;
  insertAfter(list2, &d, sizeof(d), &printDouble);
  traverse(list);
  length(list);

  int i = 23;
  insertAfter(list2, &i, sizeof(i), &printInt);
  traverse(list2);
  length(list2); 
    
  printf("\nTests complete.\n");
}

