#ifndef HASH_HPP
#define HASH_HPP
#include <string>
using namespace std;

/*struct node
{
    int key;
    struct node* next;
};*/

class HashTable
{
    const int static tableSize = 10009;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int table[tableSize];

    int numAdded;



public:
    int loadFactor;
    HashTable();  // Constructor
    // inserts a key into hash table
    bool insertItem(int key);
    bool deleteItem(int key);
    // hash function to map values to key
    unsigned int hashFunction(int key);
    void printTable();
    int Lookup(int key);
    int calcLoadFactor();
};

#endif
