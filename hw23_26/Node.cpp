//
// Created by c4lculater on 06.12.2022.
//

#include <iostream>
using namespace std;
//узел дерева
template <class T>
class Node {
private:
    T value;
public:

    T getValue() { return value; } //установить данные в узле

    void setValue(T v) { value = v; }

    int operator<(Node N) { return (value < N.getValue()); } //сравнение узлов

    int operator>(Node N) {
        return (value > N.getValue());
    }


    void print() { //вывод содержимого одного узла
        cout << value;
    }
};

template <class T>
void print(Node<T>* N)
{
    cout << N->getValue() << "\n";
}