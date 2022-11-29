//
// Created by c4lculater on 29.11.2022.
//

#include <iostream>
using namespace std;

template<class K, class V>
class NodeKV {
private:
    //закрытые переменные Node N; N.data = 10 вызовет ошибку
    K key;
    V value;

    //не можем хранить Node, но имеем право хранить указатель
    NodeKV* left;
    NodeKV* right;
    NodeKV* parent;

    //переменная, необходимая для поддержания баланса дерева
    int height;
public:

    K getKey() { return key; }
    V getValue() { return value; }
    int getHeight() { return height; }

    NodeKV<K,V>* getLeft() { return left; }
    NodeKV<K,V>* getRight() { return right; }
    NodeKV<K,V>* getParent() { return parent; }
    void setLeft(NodeKV<K,V>* N) { left = N; }
    void setRight(NodeKV<K,V>* N) { right = N; }
    void setParent(NodeKV<K,V>* N) { parent = N; }

    //Конструктор. Устанавливаем стартовые значения для указателей
    NodeKV<K,V>(K keyO, V valueO) {
        key = keyO;
        value = valueO;
        left = right = parent = NULL;
        height = 1;
    }

    virtual void print() {
        cout << "Key : " << key << " Value : " << value;
    }

    virtual void setHeight(int h) {
        height = h;
    }

    template<class L, class M>
    friend ostream& operator<< (ostream& stream, NodeKV<L, M>& N);
};

template<class K, class V>
ostream& operator<< (ostream& stream, NodeKV<K,V>& N) {
    stream << "\nNode key: " << N.getKey() << "; value: " << N.getValue() << ", height: " << N.getHeight();
    return stream;
}

template<class K, class V>
void print(NodeKV<K,V>* N) { cout << "\n" << N->getValue(); }