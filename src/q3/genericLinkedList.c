#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"


int length(genericListElement* list){  //gets the current size of the linked list
    
    genericListElement* current = list;
    int size = 0;

    while (current != 0) {
       ++size;
       current = current->next;
    }
  printf("Size of list = %d\n", size );
  return size;
}
void push(genericListElement **list, void *data, size_t size, printString print) {
   
    genericListElement *newElement = createEl(data, size, print);
    newElement->next = *list;
    *list = newElement;
    //printf("Pushing %s\n",data );
}

genericListElement *pop(genericListElement **list) {
    genericListElement *headElement = *list;
    if (headElement) {
        *list = headElement->next; 
    }
    return headElement;
}


void enqueue(genericListElement **list, void *data, size_t size, printString print) {

    genericListElement *newElement = createEl(data, size, print);
    newElement->next = *list;
    *list = newElement;
}

genericListElement *dequeue(genericListElement *list) {
    genericListElement *temp = list;
    
    while((temp->next)->next != NULL) {
       temp = temp->next;
    }
    genericListElement *tailElement = temp->next;
    temp->next = NULL;
    return tailElement;
}

genericListElement *createEl(void *data, size_t size, printString print){
  genericListElement* e = malloc(sizeof(genericListElement));
  if(e == NULL){
    return NULL; 
  }
  void *dataPointer = malloc(size);
  if(dataPointer == NULL){
    free(e); 
    return NULL;
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->print = print; 
  e->next = NULL;
  //printf("Creating %s\n",data );
  return e;
}

void traverse(genericListElement *start){
  genericListElement *current = start;

  while(current != NULL){
    //printf("Traversing the list, %s\n", current->data);
    current->print(current->data);
    current = current->next;
  }
}

genericListElement* insertAfter(genericListElement* el, void *data, size_t size, printString print){
  genericListElement* newEl = createEl(data, size, print);
  genericListElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  //printf("Inserting after: %s\n",data );
  return newEl;
}

void deleteAfter(genericListElement* after){
  genericListElement* delete = after->next;
  genericListElement* newNext = delete->next;
  after->next = newNext;

  free(delete->data);
  free(delete);
}