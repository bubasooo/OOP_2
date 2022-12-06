//
// Created by c4lculater on 29.11.2022.
//
#include "BinTreeKV.cpp"

template<class K,class V>
class AVLTreeKV : public BinTreeKV<K,V> {
protected:
    const bool LEFT = true;
    const bool RIGHT = false;
    //delta(a) = h(La) - h(Ra)

    void disconnectNode(NodeKV<K,V>* node) {
        NodeKV<K,V>* parentNode = node->getParent();
        NodeKV<K,V>* childR = node->getRight();
        NodeKV<K,V>* childL = node->getLeft();

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

    void connectNodes(NodeKV<K,V>* node, NodeKV<K,V>* nodeToConnect,bool side) {
        if(node != NULL) {
            if (side == LEFT)
                node->setLeft(nodeToConnect);
            if (side == RIGHT)
                node->setRight(nodeToConnect);
        }
        if(nodeToConnect != NULL)
            nodeToConnect->setParent(node);
    }


    void movement(NodeKV<K,V>* nodeIB, NodeKV<K,V>* childOfInbalance, bool sideOfInbalance, NodeKV<K,V>* brotherOfInbalance) {
        NodeKV<K,V>* childLeft = childOfInbalance->getLeft();
        NodeKV<K,V>* childRight = childOfInbalance->getRight();

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

        //        if(sideOfInbalacne == RIGHT) { //delta(a) == -2
//            Node<T>* childRLeft = childR->getLeft();
//            Node<T>* childRRight = childR->getRight();
//
//            disconnectNode(childR);
//            disconnectNode(nodeIB);
//
//            connectNodes(nodeIB, childL, LEFT);
//            connectNodes(nodeIB, childRLeft, RIGHT);
//
//            connectNodes(childR, nodeIB, LEFT);
//            connectNodes(childR, childRRight,RIGHT);
//
//            if(whereNodeIB == RIGHT)
//                connectNodes(parent, childR, RIGHT);
//            if(whereNodeIB == LEFT)
//                connectNodes(parent, childR, LEFT);
//        }
    }


    void balanceDBZero(NodeKV<K,V>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        NodeKV<K,V>* parent = nodeIB->getParent();
        NodeKV<K,V>* childL = nodeIB->getLeft();
        NodeKV<K,V>* childR = nodeIB->getRight();

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

    void balanceDBMinusOne(NodeKV<K,V>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        NodeKV<K,V>* parent = nodeIB->getParent();
        NodeKV<K,V>* childL = nodeIB->getLeft();
        NodeKV<K,V>* childR = nodeIB->getRight();

        if(sideOfInbalacne == LEFT) {
            auto c = childR;
            childR = childL;
            childL = c;
        }

        movement(nodeIB, childR, sideOfInbalacne, childL);

        connectNodes(parent, childR, whereNodeIB);

        nodeIB->setHeight(nodeIB->getHeight() - 2);
    }

    void balanceDBPlusOne(NodeKV<K,V>* nodeIB, bool sideOfInbalacne, bool whereNodeIB) {
        NodeKV<K,V>* childL = nodeIB->getLeft();
        NodeKV<K,V>* childR = nodeIB->getRight();


        if(sideOfInbalacne == LEFT) {
            auto c = childR;
            childR = childL;
            childL = c;
        }

        balanceDBZero(childR, !sideOfInbalacne,sideOfInbalacne);
        balanceDBMinusOne(nodeIB,sideOfInbalacne,whereNodeIB);
    }

    int delta(NodeKV<K,V>* node) {
        if(node == NULL)
            return 0;
        int lCh = node->getLeft() == NULL ? 0 : node->getLeft()->getHeight();
        int rCh = node->getRight() == NULL ? 0 : node->getRight()->getHeight();
        return lCh - rCh;
    }
    //единственный минус не пересчитываем height
    void nodeBalance(NodeKV<K,V>* node) {
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

    void calcHeight(NodeKV<K,V>* node) {
        if(node == NULL)
            return;
        int lCh = node->getLeft() == NULL ? 0 : node->getLeft()->getHeight();
        int rCh = node->getRight() == NULL ? 0 : node->getRight()->getHeight();
        node->setHeight(1 + max(lCh, rCh));
    }
    NodeKV<K,V>* Add_R(NodeKV<K,V>* N, NodeKV<K,V>* Current) override {
        if (N == NULL)
            return NULL;

        if (BinTreeKV<K,V>::root == NULL) {
            BinTreeKV<K,V>::root = N;
            return N;
        }

        if (Current->getKey() > N->getKey()) {
            //идем влево
            if (Current->getLeft() != NULL)
                Add_R(N, Current->getLeft());
            else {
                Current->setLeft(N);
                Current->getLeft()->setParent(Current);
            }
        }

        if (Current->getKey() < N->getKey()) {
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
            BinTreeKV<K,V>::root = this->getRoot()->getParent();

        }
        return Current;
    }

    NodeKV<K,V>* Add_R(NodeKV<K,V>* N) override {
        return Add_R(N,this->getRoot());
    }



public:

    void Add(K key, V value) {
        NodeKV<K,V>* N = new NodeKV<K,V>(key, value);
        Add_R(N);
    }
    NodeKV<K,V>* Find(K key) {
        return BinTreeKV<K,V>::Find(key, BinTreeKV<K,V>::root);
    }
    NodeKV<K,V>* Delete(K key) {
        return BinTreeKV<K,V>::Delete(new NodeKV<K,V>(key));
    }

};
