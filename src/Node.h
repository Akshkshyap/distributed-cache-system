#ifndef NODE_H
#define NODE_H

class Node{
public: 
    int key;
    int value;

    Node *left;
    Node *right;

    Node(int k, int v){
        key = k;
        value = v;
        left = right = nullptr;
    }
};

#endif