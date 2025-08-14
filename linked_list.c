//
// Created by wu_17 on 2025/8/12.
//

#include "linked_list.h"

#include <stdlib.h>
#include <string.h>


//Create and Destroy functions
Person_List * create_list(void) {
    //Allocating memory
    Person_List *list = (Person_List *)malloc(sizeof(Person_List));
    if (list == NULL) return NULL;

    //Initializing member
    list->head = NULL;

    //Return
    return list;
}

void destroy_list(Person_List *list) {
    if (list == NULL) return; //Check if list is valid

    //Create pointers for traversing
    Person *prev = NULL;
    Person *curr = list->head;

    //Traversing the list and free the previous person
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free_person(prev);
    }

    //Free the list at the end
    free(list);
}

//Operations
int insert_linkedlist(Person_List *list, Person *the_person) {
    if (list == NULL || the_person == NULL) return 0; //safety check

    //If list is empty
    if (list->head == NULL) {
        list->head = the_person;
        return 1; //Successfully inserted
    }

    //Traverse to the end of the list
    Person *head = list->head;
    while (head->next != NULL) {
        head = head->next;
    }

    //Link the person to the end of the list
    head->next = the_person;
    return 1; //Successfully inserted
}

Person * search_linkedlist(Person_List *list, char *key) {
    if (list == NULL || key == NULL) return NULL; //safety check

    //Traverse the list to the end and return the person if exist
    Person *head = list->head;
    while (head != NULL) {
        if (strcmp(key, head->key) == 0) return head;
        head = head->next;
    }

    //The person does not exist in the list
    return NULL;
}

int delete_linkedlist(Person_List *list, char *key) {
    if (list == NULL || key == NULL) return 0; //safety check

    //Create pointers for traversing purpose
    Person *prev = NULL;
    Person *curr = list->head;


    //Traverse the list and delete the person if found
    while (curr != NULL) {
        if (strcmp(key, curr->key) == 0) {
            if (prev == NULL) //if person at head
                list->head = curr->next;
            else //else prev is not null
                prev->next = curr->next;

            free_person(curr);
            return 1; //Successfully delete it
        }

        //Move a step forward
        prev = curr;
        curr = curr->next;
    }

    return 0; //Did not delete
}

//Helper Functions
void free_person(Person *person) {
    if (person == NULL) return; //safety check

    //free members
    free(person->key);
    free(person->value);

    //free the person
    free(person);
}

Person * create_person(char *key, char *value) {
    //Allocate memory for person
    Person *person = (Person *)malloc(sizeof(Person));
    if (person == NULL) return NULL;

    //Initializing the members
    person->key = allocate_string(key);
    person->value = allocate_string(value);
    person->next = NULL;

    //return the person
    return person;
}

char * allocate_string(char *the_string) {
    if (the_string == NULL) return NULL; //safety check

    //Get the size of the string and allocate memory of the size of the string
    int length = (int) strlen(the_string) + 1;
    char * return_string = (char *) malloc(sizeof(char) * length);
    if (return_string == NULL) return NULL;

    //Copy the_string value to return_string
    strcpy(return_string, the_string);

    //return the allocated string
    return return_string;
}
