// CPP program to implement hashing with chaining
#include<iostream>
#include "hash.hpp"


using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    table = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key % tableSize);
}

// TODO Complete this function
//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    node* temp = new node;
    temp = table[index];
    while(temp!=NULL){
        if(temp->key == key){
            return temp;
        }
        temp = temp->next;
    }
    return temp;
    //TODO: Search the list at that specific index and return the node if found
}

//Function to insert
bool HashTable::insertItem(int key)//CONFIRMED GUD
{
    if(!searchItem(key))
    {
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        int index = hashFunction(key);
        if(!table[index]){
            table[index] = createNode(key, NULL);
        }
        node* temp = createNode(key, table[index]);
        table[index] = temp;
        return true;
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
}

//Function to display hash table
void HashTable::printTable()
{
    node* temp = new node;
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        temp = table[i];
        while(temp!=NULL){
            cout << table[i]->key << endl;
            temp = temp->next;
        }
    }
 }
