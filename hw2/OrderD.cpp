//
// Created by c4lculater on 25.10.2022.
//
#include "DListQueue.cpp"
template<class T>
class OrderD : public DListQueue<T> {
public:
    Element<T>* push(T data) override {
        Element<T>* node = new Element<T>(data, NULL, NULL);
        Element<T>* current = DListQueue<T>::head;
        while(current != NULL) {
            if(*current > data)
                break;
            current = current->getNext();
        }
        Element<T>* prev = current->getPrevious();
        connectNodes(prev, node);
        connectNodes(node, current);
    }
};
