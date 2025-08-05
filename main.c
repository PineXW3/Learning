#include "Tries.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "Words.txt"
#define MAX_WORD_LENGTH 21

void printTrie(TrieTree *trie); //print all words in the trie
void printWord(TrieNode *node, char *word, int length); //helper function of printTrie
char intToChar(int number); //change index to lowercase letter; assume 0 <= number < 26

int main(void) {
    TrieTree *trie = (TrieTree *) malloc(sizeof(TrieTree));
    if (!trie) return 1;

    trie->root = createTrieNode();
    if (!trie->root) {
        free(trie);
        return 1;
    }

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Error opening file");
        free(trie);
        return 1;
    }

    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        insert(trie, word);
    }

    printTrie(trie);

    deleteWord(trie->root, "nice", 0);
    deleteWord(trie->root, "seeing", 0);

    int exist = ( search(trie, "nice") || search(trie, "seeing") )? 1 : 0;
    if (!exist) {
        printf("\n");
        printTrie(trie);
    }

    printf("and\nbye");

    fclose(file);
    deleteTree(trie);
    return 0;
}

void printTrie(TrieTree *trie) {
    if (!trie || !trie->root) return;
    TrieNode *node = trie->root;

    char word[MAX_WORD_LENGTH] = "";
    printWord(node, word, 0);
}

void printWord(TrieNode *node, char *word, int length) {
    if (!node) return;

    if (node->endOfWord) {
        word[length] = '\0';
        printf("%s\n", word);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            word[length] = intToChar(i);
            printWord(node->children[i], word, length + 1);
        }
    }
}

char intToChar(int number) {
    return number + 'a';
}