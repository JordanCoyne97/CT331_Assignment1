#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
    if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}

void push(listElement** list, char* data, size_t size){

    listElement *newElement = createEl(data, size);
    newElement-> next = *list;
    *list = newElement;
     
}

int length(listElement* list){  //gets the current size of the linked list
    
    listElement* cur = list;
    int size = 0;

    while (cur != 0) {
       ++size;
       cur = cur->next;
    }

  return size;
}

listElement* pop(listElement** list){

    listElement *headElement = *list;
    
    if(headElement) {
        *list = headElement-> next;
    }
    
    return headElement;
}

void enqueue(listElement **list, char *dataBits, size_t size) {
    
    listElement *newElement = createEl(dataBits, size);
    newElement-> next = *list;
    *list = newElement;
    
}

listElement *dequeue(listElement *list) {
    listElement *temp = list;
    
    
    while((temp-> next)-> next != NULL) { //finds the tail element
        temp = temp-> next;
    }
    
    listElement *tailElement = temp-> next; //go to the tail
    temp-> next = NULL; //delete the tail
    
    return tailElement;
    
}
//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}