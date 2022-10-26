//
// Created by c4lculater on 26.10.2022.
//
#include "hw2.cpp"

template<class T>
class DListQueueIterator : public ListIterator<T> {
public:
    DListQueueIterator() {}
    DListQueueIterator(Element<T>* p) { ptr = p; }

    Element<T>& operator*(){
        return *ptr;
    }

    DListQueueIterator<T>& operator ++ () {
        ptr = ptr->getNext();
        return *this;
    }

    DListQueueIterator<T>& operator ++ (int v) {
        ptr = ptr->getNext();
        return *this;
    }

    DListQueueIterator<T>& operator --(){
        ptr = ptr -> getPrevious();
        return *this;
    }

    DListQueueIterator<T>& operator --(int v) {
        ptr = ptr ->getPrevious();
        return *this;
    }

    bool operator != (DListQueueIterator<T> const& other) const {
        return ptr != other.ptr;
    }

    bool operator == (DListQueueIterator<T> const& other) const {
        return ptr == other.ptr;
    }
private:
    Element<T>* ptr;
};
