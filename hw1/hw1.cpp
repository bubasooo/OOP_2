//
// Created by c4lculater on 25.10.2022.
//


#include <list>
#include <iostream>
using namespace std;

/*
template<class T>
void insert(list<T>& lst, T element) {
    typename list<T>::iterator p = lst.begin();
    while (p != lst.end()) {
        if (*p > element)
            break;
        p++;
    }
    lst.insert(p, element);
}
 */


template<class T>
void push(list<T>& lst, T element) {
    typename list<T>::iterator pointer = lst.begin();
    while (pointer != lst.end()) {
        if (*pointer > element)
            break;
        pointer++;
    }
    lst.insert(pointer, element);
}

template<class T>
T pop(list<T>& lst , T element) {
    lst.remove(element);
    return *(lst.begin());
}


template <class T>
list<T> filter(bool(*predicat)(T), list<T>& lst) {
    list<T> newlist;
    for (T node: lst)
        if (predicat(node))
            push(newlist, node);
    return newlist;
}

template <class T>
void showList(list<T>& lst) {
    typename list<T>::iterator pointer = lst.begin();
    while(pointer != lst.end()) {
        cout << *pointer << " ";
        pointer++;
    }
}


