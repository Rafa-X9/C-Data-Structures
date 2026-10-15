typedef struct arraylist {
    int *array;
    int count;
    int capacity;
} arraylist;

arraylist *arraylist_create();
void arraylist_add(arraylist *list, int item);
void arraylist_print(const arraylist *list);
void arraylist_destroy(arraylist *list);