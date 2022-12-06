//
// Created by c4lculater on 06.12.2022.
//


#include "Node.cpp"

template <class T>
class Heap { //куча (heap)
protected:
    Node<T>* arr; //массив
    int len; //сколько элементов добавлено
    int size; //сколько памяти выделено
public:
    int getCapacity() { return size; } //доступ к вспомогательным полям кучи и оператор индекса

    int getCount() { return len; }

    Node<T>& operator[](int index) {
        if (index < 0 || index >= len)
            return NULL;//?
        return arr[index];
    }

    Heap<T> (int MemorySize = 100) { //конструктор
        arr = new Node<T>[MemorySize];
        len = 0;
        size = MemorySize;
    }

    void Swap(int index1, int index2) { //поменять местами элементы arr[index1], arr[index2]
        if (index1 <= 0 || index1 >= len)
            return;
        if (index2 <= 0 || index2 >= len)
            return;
        //здесь нужна защита от дурака
        Node<T> temp;
        temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    void Copy(Node<T>* dest, Node<T>* source) { //скопировать данные между двумя узлами
        dest->setValue(source->getValue());
    }

    Node<T>* GetLeftChild(int index) { //функции получения левого, правого дочернего элемента, родителя или их индексов в массиве
        if (index < 0 || index * 2 >= len)
            return NULL; //здесь нужна защита от дурака
        return &arr[index * 2 + 1];
    }

    Node<T>* GetRightChild(int index) {
        if (index < 0 || index * 2 >= len)
            return NULL; //здесь нужна защита от дурака
        return &arr[index * 2 + 2];
    }

    Node<T>* GetParent(int index) {
        if (index <= 0 || index >= len)
            return NULL;//здесь нужна защита от дурака
        if (index % 2 == 0)
            return &arr[index / 2 - 1];
        return &arr[index / 2];
    }

    int GetLeftChildIndex(int index) {
        if (index < 0 || index * 2 >= len)
            return -404; //здесь нужна защита от дурака
        return index * 2 + 1;
    }

    int GetRightChildIndex(int index) {
        if (index < 0 || index * 2 >= len)
            return -404;
        //здесь нужна защита от дурака
        return index * 2 + 2;
    }

    int GetParentIndex(int index) {
        if (index <= 0 || index >= len)
            return -404; //здесь нужна защита от дурака
        if (index % 2 == 0)
            return index / 2 - 1;
        return index / 2;
    }


    virtual void SiftUp(int index = -1) { //просеить элемент вверх
        if(index == 0)
            return;
        if (index == -1)
            index = len - 1;
        int parent = GetParentIndex(index);
        int index2 = GetLeftChildIndex(parent);
        if (index2 == index)
            index2 = GetRightChildIndex(parent);
        int max_index = index;
        if (index < len && index2 < len && parent >= 0) {
            if (arr[index] > arr[index2])
                max_index = index;
            if (arr[index] < arr[index2])
                max_index = index2;
        }
        if (parent < len && parent >= 0 && arr[max_index] > arr[parent]) {
            //нужно просеивание вверх
            Swap(max_index, parent);
            SiftUp(parent);
        }
    }

    virtual void push(T v) { //добавление элемента - вставляем его в конец массива и просеиваем вверх
        Node<T>* N = new Node<T>;
        N->setValue(v);
        push(N);
    }

    virtual void push(Node<T>* N) {
        if (len == size) {
            auto ncapacity = size * 2;
            auto t = (Node<T>*) realloc(arr, ncapacity * sizeof(Node<T>*));
            arr = t;
            size = ncapacity;
        }
        arr[len] = *N;
        len++;
        SiftUp();
    }

    virtual void Heapify(int index = 0) { //при удалении элемента делаем просеивание вниз
        // SiftDown() = Heapify()
    }

    void Straight(void(*f)(Node<T>*)) {
        int i;
        for (i = 0; i < len; i++)
        {
            f(&arr[i]);
        }
    }

    void InOrder(void(*f)(Node<T>*), int index = 0) { //перебор элементов, аналогичный проходам бинарного дерева
        if (GetLeftChildIndex(index) < len)
            PreOrder(f, GetLeftChildIndex(index));
        if (index >= 0 && index < len)
            f(&arr[index]);
        if (GetRightChildIndex(index) < len)
            PreOrder(f, GetRightChildIndex(index));
    }
};

int main()
{
    Heap<int> Tree;
    Tree.push(1);
    Tree.push(-1);
    Tree.push(-2);
    Tree.push(2);
    Tree.push(5);
    cout << "\n-----\nStraight:";
    void(*f_ptr)(Node<int>*); f_ptr = print;
    Tree.Straight(f_ptr);
    return 0;
}