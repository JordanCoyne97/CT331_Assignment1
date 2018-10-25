#ifndef CT331_ASSIGNMENT_1
#define CT331_ASSIGNMENT_1

typedef void (*printString) (void *data);

typedef struct genericListElementStruct{
  void *data;
  size_t size;
  printString print;
  struct genericListElementStruct *next;
} genericListElement;

int length(genericListElement *list);


void push(genericListElement **list, void *data, size_t size, printString);

genericListElement *pop(genericListElement **list);

void enqueue(genericListElement **list, void *data, size_t size, printString);

genericListElement *dequeue(genericListElement *list);

genericListElement *createEl(void *data, size_t size, printString);

void traverse(genericListElement *start);

genericListElement* insertAfter(genericListElement* after, void *data, size_t size, printString);

void deleteAfter(genericListElement* after);


#endif

