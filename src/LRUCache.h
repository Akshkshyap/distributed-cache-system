#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include<unordered_map>
#include "Node.h"

using namespace std;

class LRUCache{
private:
    int capacity;

    unordered_map<int, Node*> cache; //(key, node)

    Node* head;
    Node* tail;
    
    void addNode(Node* node);
    void deleteNode(Node* node);

public:
    LRUCache(int cap);

    int get(int key);

    void put(int key, int value);

    void display();
};

#endif