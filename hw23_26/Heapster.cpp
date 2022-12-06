//
// Created by c4lculater on 06.12.2022.
//

#include "Heap.cpp"

template<class T>
class Heapster : public Heap<T> {
    //реализуем
//    void SiftUp(int index = -1) override {
//
//    }

//    void push(Node<T>* N) override {
//
//    }

    void siftDown(int v) {
        while(2*v + 1 < Heap<T>::size) {
            int u = 2*v + 1;
            if(2*v + 2 < Heap<T>::size && Heap<T>::arr[2*v + 2] > Heap<T>::arr[2*v + 1]) {
                u = 2*v + 2;
            }
            if (Heap<T>::arr[u] > Heap<T>::arr[v]) {
                Heap<T>::Swap(v, u);
                v = u;
            }
            else break;
        }

    }

    void Heapify(int index = 0) override {
        for (int i = Heap<T>::size-1; i >= 0;--i) {
            siftDown(i);
        }
    }

    Node<T>* ExtractMax() {
        Swap(0, Heap<T>::len);
        Heap<T>::len--;
        siftDown(0);
    }

    Node<T>* del(int ind) {
         Swap(ind, Heap<T>::len);
         Heap<T>::len--;
         if(Heap<T>::arr[ind] < Heap<T>::arr[Heap<T>::len+1])
            siftDown(ind);
         else
             Heap<T>::SiftUp(ind);
    }
};
