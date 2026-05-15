#include<iostream>
#include "LRUCache.h"

using namespace std;

int main(){
    LRUCache cache(3);

    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);

    cache.display();

    cout << "Get 1: " << cache.get(1) << endl;

    cache.display();

    cache.put(4,40);

    cache.display();

    cout << "Get 2: " << cache.get(2) << endl;
    
    cache.display();
    
    cout << "Get 4: " << cache.get(4) << endl;
}