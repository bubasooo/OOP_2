//
// Created by c4lculater on 25.10.2022.
//

#include "hw2.cpp"
template<class T>
class DListQueue : public IteratedLinkedList<T> {
public:
    DListQueue() {}
    Element<T>* push(T data) override {
        Element<T>* node = new Element<T>(data,NULL,NULL);
        if(LinkedListParent<T>::head == NULL) {
            LinkedListParent<T>::head = node;
            LinkedListParent<T>::tail = node;
            LinkedListParent<T>::num++;
            return node;
        }
        connectNodes(LinkedListParent<T>::tail, node);
        LinkedListParent<T>::tail = node;
        LinkedListParent<T>::num++;
        return node;
    }

    Element<T>* pop() override {
        if(LinkedListParent<T>::head == NULL)
            throw;
        Element<T>* nextAfterHead = LinkedListParent<T>::head->getNext();
        LinkedListParent<T>::head = nextAfterHead;
        nextAfterHead->setPrevious(NULL);
        LinkedListParent<T>::num--;

    }
    ~DListQueue() {
        Element<T>* current = LinkedListParent<T>::head;
        Element<T>* node;
        while(current->getNext() != NULL) {
            node = current;
            current = current->getNext();
            delete node;
        }

    }

protected:
    void connectNodes(Element<T>* current,Element<T>* other) {
        current->setNext(other);
        other->setPrevious(current);
    }
};

template<class T>
DListQueue<T> filter(bool(*predicat)(T) ,DListQueue<T>& lst);



