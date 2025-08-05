#include "Tries.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void insert(TrieTree *trie, char *word) {
    if (!trie || !trie->root) return;
    TrieNode *current = trie->root;

    int length = (int) strlen(word);
    for (int i = 0; i < length; i++) {
        char c = (char) tolower(word[i]);
        int index = charToIndex(c);

        if (current->children[index] == NULL)
            current->children[index] = createTrieNode();

        current = current->children[index];
    }

    current->endOfWord = 1;
}

int search(TrieTree *trie, char *word) {
    if (!trie || !trie->root) return 0;
    TrieNode *current = trie->root;

    int length = (int) strlen(word);
    for (int i = 0; i < length; i++) {
        char c = (char) tolower(word[i]);
        int index = charToIndex(c);

        if (!current->children[index]) return 0;

        current = current->children[index];
    }

    return current->endOfWord;
}

int deleteWord(TrieNode *node, char *word, int position) {
    if (!node) return 0;

    int length = (int) strlen(word);
    if (position == length) {
        if (hasChildren(node)) {
            node->endOfWord = 0;
            return 0;
        }

        free(node);
        return 1;
    }

    int index = charToIndex(tolower(word[position]));
    int lost = deleteWord(node->children[index], word, position + 1);

    if (lost) {
        node->children[index] = NULL;

        if (position == 0) return 0;

        if (hasChildren(node) || node->endOfWord) {
            return 0;
        }

        free(node);
        return 1;
    }

    return 0;
}

void deleteTree(TrieTree *trie) {
    if (!trie) return;
    deleteNodes(trie->root);
    free(trie);
}

TrieNode * createTrieNode() {
    TrieNode *node = (TrieNode *) malloc(sizeof(TrieNode));
    if (!node) return NULL;

    node->endOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void deleteNodes(TrieNode *root) {
    if (!root) return;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            deleteNodes(root->children[i]);
            root->children[i] = NULL;
        }
    }

    free(root);
}

int hasChildren(TrieNode *node) {
    if (!node) return 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) return 1;
    }

    return 0;
}
int charToIndex(char c) {
    return c - 'a';
}