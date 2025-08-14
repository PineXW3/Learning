#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 20
int main(void) {
    Hashtable *hashtable = create_hashtable(CAPACITY);
    Person *person = create_person("John", "Happy");
    Person *person2 = create_person("Lucas", "Sad");
    Person *person3 = create_person("Kevin", "Jealous");

    insert_hashtable(hashtable, person);
    insert_hashtable(hashtable, person2);
    insert_hashtable(hashtable, person3);

    Person *search = search_hashtable(hashtable, "John");

    printf("%s is %s\n", search->key, search->value);
    delete_hashtable(hashtable, "John");

    search = search_hashtable(hashtable, "John");
    if (search == NULL)
        printf("Bye John");
    else
        printf("John don't wanna go");

    destroy_hashtable(hashtable);

    return 0;
}