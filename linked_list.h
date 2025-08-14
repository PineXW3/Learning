//
// Created by wu_17 on 2025/8/12.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Person {
    char *key;
    char *value;
    struct Person *next;
} Person;

typedef struct Person_List {
    struct Person *head;
} Person_List;

//Create and Destroy List
Person_List * create_list(void);
void destroy_list(Person_List *list);

//Operations of Linked List
int insert_linkedlist(Person_List *list, Person *the_person);
Person * search_linkedlist(Person_List *list, char *key);
int delete_linkedlist(Person_List *list, char *key);

//Helper Function
void free_person(Person *person);
Person * create_person(char *key, char *value);
char * allocate_string(char *the_string);

#endif //LINKED_LIST_H
