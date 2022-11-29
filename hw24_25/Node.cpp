//
// Created by c4lculater on 29.11.2022.
//

#include <iostream>
using namespace std;

template<class T>
class Node { //узел
protected:
    //закрытые переменные Node N; N.data = 10 вызовет ошибку
    T data;

    //не можем хранить Node, но имеем право хранить указатель
    Node* left;
    Node* right;
    Node* parent;

    //переменная, необходимая для поддержания баланса дерева
    int height;
public:

    //доступные извне переменные и функции
    virtual void setData(T d) { data = d; }
    virtual T getData() { return data; }
    int getHeight() { return height; }

    virtual Node* getLeft() { return left; }
    virtual Node* getRight() { return right; }
    virtual Node* getParent() { return parent; }
    virtual void setLeft(Node* N) { left = N; }
    virtual void setRight(Node* N) { right = N; }
    virtual void setParent(Node* N) { parent = N; }

    //Конструктор. Устанавливаем стартовые значения для указателей
    Node<T>(T n) {
        data = n;
        left = right = parent = NULL;
        height = 1;
    }

    Node<T>() {
        left = NULL;
        right = NULL;
        parent = NULL;
        data = 0;
        height = 1;
    }

    virtual void print() {
        cout << "\n" << data;
    }

    virtual void setHeight(int h) {
        height = h;
    }

    template<class E>
    friend ostream& operator<< (ostream& stream, Node<E>& N);
};

template<class T>
ostream& operator<< (ostream& stream, Node<T>& N) {
    stream << "\nNode data: " << N.data << ", height: " << N.height;
    return stream;
}

template<class T>
void print(Node<T>* N) { cout << "\n" << N->getData(); }
