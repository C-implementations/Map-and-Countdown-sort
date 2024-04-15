//
// Created by DanielMolnar on 2024-04-15.
//

#ifndef COUNTDOWNSORT_MYMAP_H
#define COUNTDOWNSORT_MYMAP_H

template <class T, class K>
class MyMap {
public:
    MyMap();
    ~MyMap();
    void put(const T key, const K value);
    K getValue(const T key);
    void print();
private:
    T* _keys;
    K* _values;
    int _actualPosition = 0;
    int _actualCapacity = 5;
    void checkCapacity();
};

//
// Created by DanielMolnar on 2024-04-15.
//
#include <iostream>
#include "mymap.h"

template<class T, class K>
MyMap<T, K>::MyMap() {
    _keys = new T[_actualCapacity];
    _values = new K[_actualCapacity];
    _actualPosition = 0; // element count in the map
    _actualCapacity = 5; // maximum capacity of the _keys and _values array
}

template<class T, class K>
void MyMap<T, K>::put(const T key, const K value) {
    checkCapacity();
    _keys[_actualPosition] = key;
    _values[_actualPosition] = value;
    _actualPosition++;
}

template<class T, class K>
K MyMap<T, K>::getValue(const T key) {
    for (int i = 0; i < _actualPosition; i++)
    {
        if (_keys[i] == key) {
            return _values[i];
        }
    }

    return nullptr;
}

template<class T, class K>
void MyMap<T, K>::print() {
    for (int i = 0; i < _actualPosition; i++)
    {
        std::cout << "Key: " << _keys[i] << " Value: " << _values[i] << std::endl;
    }
}

template<class T, class K>
MyMap<T, K>::~MyMap() {
    if (_keys) {
        delete _keys;
    }

    if (_values) {
        delete _values;
    }
}

template<class T, class K>
void MyMap<T, K>::checkCapacity() {
    if (_actualPosition == _actualCapacity) {  // Simplified check
        T* newKeys = new T[_actualCapacity * 2];
        K* newValues = new K[_actualCapacity * 2];

        for (int i = 0; i < _actualCapacity; i++) {
            newKeys[i] = _keys[i];
            newValues[i] = _values[i];
        }

        _actualCapacity *= 2;
        delete[] _keys;  // Deallocate old memory before assigning new
        delete[] _values;
        _keys = newKeys;
        _values = newValues;
    }
}

#endif //COUNTDOWNSORT_MYMAP_H
