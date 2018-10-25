#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void testFunction1(){
    //tests queues
    printf("Testing Queues\n");
    listElement *list = createEl("Element (a)", 30); //creates
    traverse(list);   //reads the list

    enqueue(&list, "Element (b)", 30);
    traverse(list);
    
    printf("Dequeue \n");
    dequeue(list);
    insertAfter(list, "Element (c)", 30);  
    traverse(list);
    length(list);
  
    printf("Delete after\n");
    deleteAfter(list);
    traverse(list);
    length(list);
    printf("\n");
}

void testFunction2(){ 
    //tests stack
    printf("Testing stacks\n");
    listElement *list = createEl("Element (e)", 30);
    traverse(list);
    length(list);
    
    push(&list, "Element (f)", 30);
    insertAfter(list, "Element (g)", 30);
    push(&list, "Element (h)", 30);
    traverse(list);
    length(list);
    
    printf("Popping an element\n");
    pop(&list);
    traverse(list);
    length(list);

    printf("Deleting after\n");
    deleteAfter(list);
    traverse(list);
    length(list);
}

void runTests(){
  testFunction1();
  testFunction2();

  printf("\nTests complete.\n");
}