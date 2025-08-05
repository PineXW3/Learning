#ifndef TRIES_H
#define TRIES_H

#define ALPHABET_SIZE 26

//Struct Tries
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int endOfWord;
} TrieNode;

typedef struct TrieTree {
    TrieNode *root;
} TrieTree;

//Operations
void insert(TrieTree *trie, char *word); //Assume root exist
int search(TrieTree *trie, char *word); //Return 1 to indicate exist, 0 for not exist
int deleteWord(TrieNode *node, char *word, int position); //Delete the word if exist in the trie
void deleteTree(TrieTree *trie); //Delete the entire trie

//Helper Functions
TrieNode * createTrieNode(); //Create a trie node
void deleteNodes(TrieNode *root); //Delete its descendents and itself
int hasChildren(TrieNode *node); //Check if the node has child
int charToIndex(char c); //assume the char is a-z and lowercase

#endif //TRIES_H
