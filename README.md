# Hashtable and Linked List

## Description
This branch is mainly about Hashtable, but it also covered linked list because I implemented with Linked List.  
The Hashtable is a very interesting topic to learn and implement.  
During the implementation, I had a great idea of what I can do with this Hashtable.  
I will use this implemented Hashtable to create a project in other repo.

## Time Complexity
Hash function - O(k), where k is the length of the key.  
However, if the length of k is constant we could also seem O(k) as O(1).  
  
The insertion, search, and deletion are all involved Hash function, meaning their time complexity will also be O(k) or O(1).  
That was just the average time complexity for these operations.  
The worst time complexity is O(n) for these operations, because the items could be stored all in same index of the Hashtable.  
Therefore, it could form a linked list of n elements, and insert, search, or delete in a linked list could all cost O(n).