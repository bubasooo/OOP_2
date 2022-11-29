//
// Created by c4lculater on 28.11.2022.
//


#include "Node.cpp"

template<class T>
class Tree {
protected:
    //корень - его достаточно для хранения всего дерева
    Node<T>* root;
public:
    //доступ к корневому элементу
    virtual Node<T>* getRoot() { return root; }

    //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
    Tree<T>() { root = NULL; }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual Node<T>* Add_R(Node<T>* N) {
        return Add_R(N, root);
    }

    virtual Node<T>* Add_R(Node<T>* N, Node<T>* Current) {

        if (N == NULL)
            return NULL;

        if (root == NULL) {
            root = N;
            return N;
        }

        if (Current->getData() > N->getData()) {
            //идем влево
            if (Current->getLeft() != NULL)
                Current->setLeft(Add_R(N, Current->getLeft()));
            else
                Current->setLeft(N);
            Current->getLeft()->setParent(Current);
        }

        if (Current->getData() < N->getData()) {
            //идем вправо
            if (Current->getRight() != NULL)
                Current->setRight(Add_R(N, Current->getRight()));
            else
                Current->setRight(N);
            Current->getRight()->setParent(Current);
        }
        if (Current->getData() == N->getData()); //нашли совпадение
        //для несбалансированного дерева поиска

        return Current;
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual void Add(int n) {
        Node<T>* N = new Node<T>;
        N->setData(n);
        Add_R(N);
    }

    virtual Node<T>* Min(Node<T>* Current=NULL) { //минимум - это самый "левый" узел. Идём по дереву всегда влево
        if (root == NULL) return NULL;
        if(Current==NULL)
            Current = root;
        while (Current->getLeft() != NULL)
            Current = Current->getLeft();
        return Current;
    }

    virtual Node<T>* Max(Node<T>* Current = NULL) { //минимум - это самый "правый" узел. Идём по дереву всегда вправо
        if (root == NULL) return NULL;

        if (Current == NULL)
            Current = root;
        while (Current->getRight() != NULL)
            Current = Current->getRight();
        return Current;
    }

    //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
    virtual Node<T>* Find(T data, Node<T>* Current) {
        //база рекурсии
        if (Current == NULL)
            return NULL;
        if (Current->getData() == data)
            return Current;
        //рекурсивный вызов
        if (Current->getData() > data)
            return Find(data,Current->getLeft());
        if (Current->getData() < data)
            return Find(data,Current->getRight());
    }

    //три обхода дерева
    virtual void PreOrder(Node<T>* N, void (*f)(Node<T>*)) {
        if (N != NULL)
            f(N);
        if (N != NULL && N->getLeft() != NULL)
            PreOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PreOrder(N->getRight(), f);
    }

    //InOrder-обход даст отсортированную последовательность
    virtual void InOrder(Node<T>* N, void (*f)(Node<T>*)) {
        if (N != NULL && N->getLeft() != NULL)
            InOrder(N->getLeft(), f);
        if (N != NULL)
            f(N);
        if (N != NULL && N->getRight() != NULL)
            InOrder(N->getRight(), f);


    }
    virtual void PostOrder(Node<T>* N, void (*f)(Node<T>*)) {
        if (N != NULL && N->getLeft() != NULL)
            PostOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PostOrder(N->getRight(), f);
        if (N != NULL)
            f(N);
    }
};

//int main() {
//    Tree<int> tree = Tree<int>();
//    for(int i = 0;i < 8;i++)
//        tree.Add(i);
//    if(tree.Find(9, tree.getRoot()) == NULL)
//        cout << "super!";
//    else
//        cout << tree.Find(9, tree.getRoot())->getData();
//}