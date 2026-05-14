#include<iostream>
using namespace std;


struct Node{
    int key;
    int value;

    Node *left;
    Node *right;

    Node(int k, int v){
        key = k;
        value = v;
        left = right = NULL;
    }
};