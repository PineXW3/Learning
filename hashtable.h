//
// Created by wu_17 on 2025/8/12.
//

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linked_list.h"

typedef struct Hashtable {
    struct Person_List **table;
    int capacity;
    int size;
} Hashtable;

//Create and Destroy Hashtable
Hashtable * create_hashtable(int capacity);
void destroy_hashtable(Hashtable *hashtable);

//Operations of Hashtable
void insert_hashtable(Hashtable *hashtable, Person *the_person);
Person * search_hashtable(Hashtable *hashtable, char *key);
void delete_hashtable(Hashtable *hashtable, char *key);

//Hash Function
unsigned int hash(Hashtable *hashtable, const char *key);
#endif //HASHTABLE_H
