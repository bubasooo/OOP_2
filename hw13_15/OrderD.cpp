//
// Created by c4lculater on 25.10.2022.
//
#include "DListQueue.cpp"
template<class T>
class OrderD : public DListQueue<T> {
public:

    Element<T>* push(T data) override { //нот нул
        Element<T>* node = new Element<T>(data, NULL, NULL);
        Element<T>* current = DListQueue<T>::head;
        Element<T>* prev = NULL;
        while(current != NULL) {
            if(current->getValue() > data)
                break;
            prev = current;
            current = current->getNext();
        }
        if(current == NULL) {
            DListQueue<T>::push(data);
            return node;
            DListQueue<T>::num++;
        }
        DListQueue<T>::connectNodes(prev, node);
        DListQueue<T>::connectNodes(node, current);
        DListQueue<T>::num++;
        if(current == DListQueue<T>::head)
            DListQueue<T>::head = node;
        return node;
    }

};
