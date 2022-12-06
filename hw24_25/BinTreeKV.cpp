//
// Created by c4lculater on 29.11.2022.
//

#include "NodeKV.cpp"

template<class K, class V>
class BinTreeKV {
protected:
    //корень - его достаточно для хранения всего дерева
    NodeKV<K,V>* root;
public:
    //доступ к корневому элементу
    virtual NodeKV<K,V>* getRoot() { return root; }

    //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
    BinTreeKV<K,V>() { root = NULL; }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual NodeKV<K,V>* Add_R(NodeKV<K,V>* N) {
        return Add_R(N, root);
    }

    virtual NodeKV<K,V>* Add_R(NodeKV<K,V>* N, NodeKV<K,V>* Current) {

        if (N == NULL)
            return NULL;

        if (root == NULL) {
            root = N;
            return N;
        }

        if (Current->getKey() > N->getKey()) {
            //идем влево
            if (Current->getLeft() != NULL)
                Current->setLeft(Add_R(N, Current->getLeft()));
            else
                Current->setLeft(N);
            Current->getLeft()->setParent(Current);
        }

        if (Current->getKey() < N->getKey()) {
            //идем вправо
            if (Current->getRight() != NULL)
                Current->setRight(Add_R(N, Current->getRight()));
            else
                Current->setRight(N);
            Current->getRight()->setParent(Current);
        }
        //if (Current->getKey() == N->getKey()); //нашли совпадение
        //для несбалансированного дерева поиска

        return Current;
    }

    void swapNodes(NodeKV<K,V>* fNode, NodeKV<K,V>* sNode) {
        NodeKV<K,V>* fParent = fNode->getParent();
        NodeKV<K,V>* sParent = sNode->getParent();
        NodeKV<K,V>* fLChild = fNode->getLeft();
        NodeKV<K,V>* fRChild = fNode->getRight();
        NodeKV<K,V>* sLChild = sNode->getLeft();
        NodeKV<K,V>* sRChild = sNode->getRight();

        if(fParent != NULL)
            if (fParent->getLeft() == fNode)
                fParent->setLeft(sNode);
            else
                fParent->setRight(sNode);
        sNode->setParent(fParent);

        if(sParent != NULL)
            if(sParent->getLeft() == sNode)
                sParent->setLeft(fNode);
            else
                sParent->setRight(fNode);
        fNode->setParent(sParent);

        if(fLChild != NULL)
            fLChild->setParent(sNode);
        sNode->setLeft(fLChild);

        if(fRChild != NULL)
            fRChild->setParent(sNode);
        sNode->setRight(fRChild);

        if(sLChild != NULL)
            sLChild->setParent(fNode);
        fNode->setLeft(sLChild);

        if(sRChild != NULL)
            sRChild->setParent(fNode);
        fNode->setRight(sRChild);

    }

    virtual NodeKV<K,V>* swapSuccessorAndDel(NodeKV<K,V>* delNode,NodeKV<K,V>* Current) {
        if (Current->getLeft() == NULL) {
            swapNodes(delNode, Current);
            return deleteNode(delNode, true);
        }

        return swapSuccessorAndDel(delNode, Current->getLeft());
    }

    virtual NodeKV<K,V>* deleteNode(NodeKV<K,V>* Current,bool LR) {
        if(Current->getRight() == NULL) {
            if (Current->getParent() != NULL) { //если не корень
                if(LR) {
                    NodeKV<K, V>* parent = Current->getParent();
                    parent->setLeft(Current->getLeft());
                    Current->getLeft()->setParent(parent);
                    //delete(Current);
                }
                else {
                    NodeKV<K, V>* parent = Current->getParent();
                    parent->setRight(Current->getLeft());
                    Current->getLeft()->setParent(parent);
                    //delete(Current);
                }
            }
            else { //если корент
                root = Current->getLeft();
                Current->getLeft()->setParent(NULL);
                //delete(Current);
            }
            return Current;
        }

        return swapSuccessorAndDel(Current, Current->getRight());
    }

    virtual NodeKV<K,V>* Delete(NodeKV<K,V>* delNode, NodeKV<K,V>* Current) {

        if(Current->getKey() == delNode->getKey()) {
            if(Current->getParent()->getLeft() == Current)
                return deleteNode(Current, true);
            else
                return deleteNode(Current,false);
        }

        if (Current->getKey() > delNode->getKey()) {
            //идем влево
            if (Current->getLeft() != NULL)
                return Delete(delNode, Current->getLeft());
        }

        if (Current->getKey() < delNode->getKey()) {
            //идем вправо
            if (Current->getRight() != NULL)
                return Delete(delNode, Current->getRight());
        }

        return NULL;
    }



    void Add(K key, V value) {
        NodeKV<K,V>* N = new NodeKV<K,V>(key,value);
        Add_R(N);
    }
    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
//    virtual void Add(int n) {
//        NodeKV<K,V>* N = new NodeKV<K,V>;
//        N->setData(n);
//        Add_R(N);
//    }

    virtual NodeKV<K,V>* Min(NodeKV<K,V>* Current=NULL) { //минимум - это самый "левый" узел. Идём по дереву всегда влево
        if (root == NULL) return NULL;
        if(Current==NULL)
            Current = root;
        while (Current->getLeft() != NULL)
            Current = Current->getLeft();
        return Current;
    }

    virtual NodeKV<K,V>* Max(NodeKV<K,V>* Current = NULL) { //минимум - это самый "правый" узел. Идём по дереву всегда вправо
        if (root == NULL) return NULL;

        if (Current == NULL)
            Current = root;
        while (Current->getRight() != NULL)
            Current = Current->getRight();
        return Current;
    }

    //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
    virtual NodeKV<K,V>* FindByKey(K key, NodeKV<K,V>* Current) {
        //база рекурсии
        if (Current == NULL)
            return NULL;
        if (Current->getKey() == key)
            return Current;
        //рекурсивный вызов
        if (Current->getKey() > key)
            return FindByKey(key,Current->getLeft());
        if (Current->getKey() < key)
            return FindByKey(key,Current->getRight());
    }

    //три обхода дерева
    virtual void PreOrder(NodeKV<K,V>* N, void (*f)(NodeKV<K,V>*)) {
        if (N != NULL)
            f(N);
        if (N != NULL && N->getLeft() != NULL)
            PreOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PreOrder(N->getRight(), f);
    }

    //InOrder-обход даст отсортированную последовательность
    virtual void InOrder(NodeKV<K,V>* N, void (*f)(NodeKV<K,V>*)) {
        if (N != NULL && N->getLeft() != NULL)
            InOrder(N->getLeft(), f);
        if (N != NULL)
            f(N);
        if (N != NULL && N->getRight() != NULL)
            InOrder(N->getRight(), f);


    }
    virtual void PostOrder(NodeKV<K,V>* N, void (*f)(NodeKV<K,V>*)) {
        if (N != NULL && N->getLeft() != NULL)
            PostOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PostOrder(N->getRight(), f);
        if (N != NULL)
            f(N);
    }

    void showTree(NodeKV<K,V>* localRoot) {
        if(localRoot != NULL) {
            showTree(localRoot->getLeft());
            cout << "KEY: " << localRoot->getKey() << " VALUE: " << localRoot->getValue() << '\n';
            showTree(localRoot->getRight());
        }
    }

};