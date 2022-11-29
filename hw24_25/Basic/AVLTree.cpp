//
// Created by c4lculater on 28.11.2022.
//

#include "BinTree.cpp"

template<class T>
class AVLTree : public Tree<T> {

    const bool LEFT = true;
    const bool RIGHT = false;
    //delta(a) = h(La) - h(Ra)

    void disconnectNode(Node<T>* node) {
        Node<T>* parentNode = node->getParent();
        Node<T>* childR = node->getRight();
        Node<T>* childL = node->getLeft();

        if(parentNode != NULL) {
            if (node == parentNode->getLeft())
                parentNode->setLeft(NULL);
            if (node == parentNode->getRight())
                parentNode->setRight(NULL);
            node->setParent(NULL);
        }

        if(childR != NULL) {
            childR->setParent(NULL);
            node->setRight(NULL);
        }

        if(childL != NULL) {
            childL->setParent(NULL);
            node->setLeft(NULL);
        }
    }

    void connectNodes(Node<T>* node, Node<T>* nodeToConnect,bool side) {
        if(node != NULL) {
            if (side == LEFT)
                node->setLeft(nodeToConnect);
            if (side == RIGHT)
                node->setRight(nodeToConnect);
        }
        if(nodeToConnect != NULL)
            nodeToConnect->setParent(node);
    }


    void movement(Node<T>* nodeIB, Node<T>* childOfInbalance, bool sideOfInbalance, Node<T>* brotherOfInbalance) {
        Node<T>* childLeft = childOfInbalance->getLeft();
        Node<T>* childRight = childOfInbalance->getRight();

        disconnectNode(childOfInbalance);
        disconnectNode(nodeIB);

        connectNodes(nodeIB,brotherOfInbalance , !sideOfInbalance);
        if(sideOfInbalance == LEFT) {
            connectNodes(nodeIB, childRight, sideOfInbalance);
            connectNodes(childOfInbalance,childLeft , sideOfInbalance);
        }
        else {
            connectNodes(nodeIB, childLeft, sideOfInbalance);
            connectNodes(childOfInbalance,childRight , sideOfInbalance);
        }

        connectNodes(childOfInbalance, nodeIB, !sideOfInbalance);

    }


    void balanceDBZero(Node<T>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        Node<T>* parent = nodeIB->getParent();
        Node<T>* childL = nodeIB->getLeft();
        Node<T>* childR = nodeIB->getRight();

        if(sideOfInbalacne == LEFT) {
            auto c = childR;
            childR = childL;
            childL = c;
        }

        movement(nodeIB, childR, sideOfInbalacne, childL);

        connectNodes(parent, childR, whereNodeIB);

        childR->setHeight(childR->getHeight() + 1);
        nodeIB->setHeight(nodeIB->getHeight() - 1);

    }

    void balanceDBMinusOne(Node<T>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        Node<T>* parent = nodeIB->getParent();
        Node<T>* childL = nodeIB->getLeft();
        Node<T>* childR = nodeIB->getRight();

        if(sideOfInbalacne == LEFT) {
            auto c = childR;
            childR = childL;
            childL = c;
        }

        movement(nodeIB, childR, sideOfInbalacne, childL);

        connectNodes(parent, childR, whereNodeIB);

        nodeIB->setHeight(nodeIB->getHeight() - 2);
    }

    void balanceDBPlusOne(Node<T>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        Node<T>* childL = nodeIB->getLeft();
        Node<T>* childR = nodeIB->getRight();


        if(sideOfInbalacne == LEFT) {
            auto c = childR;
            childR = childL;
            childL = c;
        }

        balanceDBZero(childR, !sideOfInbalacne,sideOfInbalacne);
        balanceDBMinusOne(nodeIB,sideOfInbalacne,whereNodeIB);
    }

    int delta(Node<T>* node) {
        if(node == NULL)
            return 0;
        int lCh = node->getLeft() == NULL ? 0 : node->getLeft()->getHeight();
        int rCh = node->getRight() == NULL ? 0 : node->getRight()->getHeight();
        return lCh - rCh;
    }
    //единственный минус не пересчитываем height
    void nodeBalance(Node<T>* node) {
        int d = delta(node);

        if(d < 2 && d > -2)
            return;

        bool whereNode;
        if(node->getParent() != NULL)
            whereNode = (node == node->getParent()->getLeft()) ? LEFT : RIGHT;
        else
            whereNode = true;

        if(d == 2) {
            int dCh = delta(node->getLeft());
            if(dCh == 0)
                balanceDBZero(node,LEFT,whereNode);
            if(dCh == -1)
                balanceDBPlusOne(node,LEFT,whereNode);
            if(dCh == 1)
                balanceDBMinusOne(node,LEFT,whereNode);
        }
        if(d == -2) {
            int dCh = delta(node->getRight());
            if(dCh == 0)
                balanceDBZero(node,RIGHT,whereNode);
            if(dCh == 1)
                balanceDBPlusOne(node,RIGHT,whereNode);
            if(dCh == -1)
                balanceDBMinusOne(node,RIGHT,whereNode);
        }

    }

    void calcHeight(Node<T>* node) {
        if(node == NULL)
            return;
        int lCh = node->getLeft() == NULL ? 0 : node->getLeft()->getHeight();
        int rCh = node->getRight() == NULL ? 0 : node->getRight()->getHeight();
        node->setHeight(1 + max(lCh, rCh));
    }
    Node<T>* Add_R(Node<T>* N, Node<T>* Current) override {
        if (N == NULL)
            return NULL;

        if (Tree<T>::root == NULL) {
            Tree<T>::root = N;
            return N;
        }

        if (Current->getData() > N->getData()) {
            //идем влево
            if (Current->getLeft() != NULL)
                Add_R(N, Current->getLeft());
            else {
                Current->setLeft(N);
                Current->getLeft()->setParent(Current);
            }
        }

        if (Current->getData() < N->getData()) {
            //идем вправо
            if (Current->getRight() != NULL)
                Add_R(N, Current->getRight());
            else {
                Current->setRight(N);
                Current->getRight()->setParent(Current);
            }
        }

        nodeBalance(Current);
        calcHeight(Current);
        if(this->getRoot()->getParent() != NULL) {
            Tree<T>::root = this->getRoot()->getParent();

        }
        return Current;
    }

    Node<T>* Add_R(Node<T>* N) override {
        return Add_R(N,this->getRoot());
    }


public:

    virtual void Add(T data) override {
        Node<T>* N = new Node<T>;
        N->setData(data);
        Add_R(N);
    }
    virtual Node<T>* Find(T data) {
        return Tree<T>::Find(data, Tree<T>::root);
    }

};


//int main() {
//    AVLTree<int> T = AVLTree<int>();
//
//    for (int i = 0; i < 6; i++)
//        T.Add(i);
//
//    cout << T.getRoot()->getData();
//    cout << T.Min(T.getRoot())->getData();
//    cout << T.Find(3)->getData();
//    return 0;
//}
