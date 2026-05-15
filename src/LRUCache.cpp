#include "LRUCache.h"
#include<iostream>

using namespace std;

LRUCache::LRUCache(int cap){
    capacity = cap;

    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
}

void LRUCache::addNode(Node* newNode){
    Node* temp = head->next;
    
    head->next = newNode;
    newNode->prev = head;

    newNode->next = temp;
    temp->prev = newNode;
}

void LRUCache::deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

int LRUCache::get(int key){
    if(cache.find(key) == cache.end()){
        return -1;
    }

    Node* node = cache[key];
    deleteNode(node);

    addNode(node);

    return node->value;
}

void LRUCache::put(int key, int value){
    if(cache.find(key) != cache.end()){
        Node* node = cache[key];
        node->value = value;

        deleteNode(node);
        addNode(node);
        return;
    }
    if(cache.size() == capacity){
        Node* lru = tail->prev;
        deleteNode(lru);
        cache.erase(lru->key);
        delete lru;
    }
    Node* newNode = new Node(key, value);
    addNode(newNode);
    cache[key] = newNode;
}

void LRUCache::display(){
    Node* temp = head->next;
    cout << "Cache state: ";
    while(temp != tail){
        cout << "(" << temp->key << "," << temp->value << ") ";
        temp = temp->next;
    }
    cout << endl;
}