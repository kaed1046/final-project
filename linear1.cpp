#include <iostream>
#include "linearHash.hpp"
#include <sstream>
#include <fstream>
#include <istream>
#include <string>
using namespace std;



HashTable::HashTable()
{
    for(int i=0; i < tableSize; i++)
        table[i] = -1;
    numAdded = 0;
    loadFactor = 0;
}

unsigned int HashTable::hashFunction(int key)
{
  int index;
  index = key % tableSize;
  return index;
}

bool HashTable::insertItem(int key)
{
  int place;
  place = hashFunction(key); //produces the ideal index
  for(int i = place; i < tableSize; i++) //starts at ideal index and moves up by one
  {
    if(table[i] == -1) //if it's an empty spot
    {
      table[i] = key; //place the info in the array
      numAdded++;
      loadFactor = calcLoadFactor();
      return true;
    }
  }
  for(int i = 0; i < place; i++)
  //if from the ideal spot to the end is full, start at zero and check for
  //empty spots
  {
    if(table[i] == -1)
    {
      table[i] = key;
      numAdded++;
      loadFactor = calcLoadFactor();
      return true;
    }
  }
  //if there are no empty spots
  return false;
}

int HashTable::Lookup(int key)
{
  int index = hashFunction(key);
  for(int i = index; i < tableSize; i++)
  {
    if(table[i] == key)
    {
      return i;
    }
  }
  for(int i = 0; i < index; i++)
  {
    if(table[i] == key)
    {
      return i;
    }
  }
  return -1;
}

bool HashTable::deleteItem(int key)
{
  int delIndex;
  delIndex = Lookup(key);
  if (delIndex == -1)
  {
    cout << "Key not found" << endl;
    return false;
  }
  else
  {
    table[delIndex] = -1;
    return true;
  }
}

int HashTable::calcLoadFactor()
{
  int loadF;
  loadF = numAdded / tableSize;
  return loadF;
}
