#include <iostream>
#include "mymap.h"
#include <string>

int main() {
    auto* myMap = new MyMap<int, char>();

    myMap->put(1, 'A');
    myMap->put(2, 'B');
    myMap->put(3, 'C');
    myMap->print();
    return 0;
}
