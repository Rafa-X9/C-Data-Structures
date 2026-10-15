typedef struct arraylist {
    int *array;
    int count;
    int capacity;
} arraylist;

arraylist *arraylist_create();
void arraylist_add(arraylist *list, int item);
void arraylist_print(const arraylist *list);
void arraylist_destroy(arraylist *list);

typedef struct listnode {
    int item;
    struct listnode *next;
    struct listnode *previous;
} listnode;

typedef struct linkedlist {
    listnode* first;
    listnode* last;
    int count;
} linkedlist;

linkedlist *linkedlist_create();
void linkedlist_add(linkedlist *list, int item);
void linkedlist_print(const linkedlist *list);
void linkedlist_destroy(linkedlist *list);