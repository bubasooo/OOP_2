//
// Created by c4lculater on 25.10.2022.
//

#include "DListQueueIterator.cpp"
template<class T>
class DListQueue : public IteratedLinkedList<T> {
public:
    DListQueue() {}
    Element<T>* push(T data) override { //добавляетт элемент в конец
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

    DListQueueIterator<T> begin()  {
        DListQueueIterator<T> it = DListQueueIterator<T>(LinkedListParent<T>::head);
        return it;
    }
    DListQueueIterator<T> end() { //доделать бага на энд
        DListQueueIterator<T> it = DListQueueIterator<T>(LinkedListParent<T>::tail->getNext());
        return it;
    }
    /*
    template<class E>
    friend ostream& operator << (ostream& ustream, DListQueue<E>& lstq);
    */
protected:
    void connectNodes(Element<T>* current,Element<T>* other) {
        if(current == NULL) {
            other->setPrevious(current);
            return;
        }
        if(other == NULL) {
            current->setNext(other);
            return;
        }
        current->setNext(other);
        other->setPrevious(current);
    }
};

template<class T>
ostream& operator << (ostream& ustream, DListQueue<T>& lstq) {
    ustream << "\nLength: " << lstq.Number() << "\n";
    int i = 0;
    DListQueueIterator<T> current = lstq.begin();
    //ListIterator<T> current = lstq.begin();
    while(current != lstq.end()){
        ustream << "arr[" << i << "] = " << *current << "\n";
        current++;
        i++;
    }

    return ustream;
}

template<class T>
DListQueue<T>& filter(bool(*predicat)(T) ,DListQueue<T>& lst) {
    DListQueue<T> newLst = new DListQueue<T>();
    for(T node : lst)
        if(predicat(node))
            push(newLst, node);
    return newLst;
}




