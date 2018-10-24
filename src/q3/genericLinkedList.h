typedef void (*printer) (void *info);

typedef struct genericListElementStruct {
    void *info;
    size_t size;
    print printFunc;
    struct genericListElementStruct *next;
} genericListElement;

genericListElement *createEl(void *info, size_t size, printer);

int length(genericListElement *list);

void push(genericListElement **list, void *info, size_t size, printer);

genericListElement *pop(genericListElement **list);

void enqueue(genericListElement **list, void *info, size_t size, printer);

genericListElement *dequeue(genericListElement *list);

void traverse(genericListElement *beginning);

genericListElement* insertAfter(genericListElement* ele, void *info, size_t size, printer);

void deleteAfter(genericListElement* afterEle);

#endif