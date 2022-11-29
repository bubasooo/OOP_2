//
// Created by c4lculater on 30.11.2022.
//


#include <stack>
#include "AVLTreeKV.cpp"

template<class K, class V>
class TreeIteratorKV {
public:

    TreeIteratorKV() {}
    TreeIteratorKV(NodeKV<K,V>* nodeO) {node = nodeO;}



    NodeKV<K,V>& operator*() {
        return (*node);
    }

    TreeIteratorKV<K,V>& operator++ () {
        node = getNext(node);
        return *this;

    }
    TreeIteratorKV<K,V>& operator ++ (int v) {
        TreeIteratorKV<K,V>* it = new TreeIteratorKV<K,V>(node);
        node = getNext(node);
        return *it;
    }
    TreeIteratorKV<K,V>& operator -- ()  {
        node = getPrevious(node);
        return *this;
    }
    TreeIteratorKV& operator -- (int v)  {
        TreeIteratorKV<K,V>* it = new TreeIteratorKV<K,V>(node);
        node = getPrevious(node);
        return *it;
    }

    bool operator != (TreeIteratorKV<K,V> other) const {
        return node != other.getNode();
    }


    bool operator == (TreeIteratorKV<K,V> other) const {
        return !(this != other);
    }

    NodeKV<K,V>* getNode() {
        return node;
    }


private:
    NodeKV<K,V>* node;
    stack < NodeKV<K,V>* > sMax;
    stack < NodeKV<K,V>* > sMin;

    NodeKV<K,V>* getNext(NodeKV<K,V>* node) {
        NodeKV<K,V>* nextNode = NULL;
        if(node->getRight() != NULL) {
            sMax.push(node);
            nextNode = node->getRight();
            while(nextNode->getLeft() != NULL) {
                nextNode = nextNode->getLeft();
            }
        }
        else {

            if(node->getParent() != NULL)
                nextNode = node->getParent();
            if(!sMax.empty()) {
                while (!sMax.empty() && sMax.top() == nextNode) {
                    if(nextNode->getParent() == NULL)
                        break;
                    nextNode = nextNode->getParent();
                    sMax.pop();
                }
            }
        }
        if(!sMax.empty() && nextNode == sMax.top())
            return NULL;

        return nextNode;
    }

    NodeKV<K,V>* getPrevious(NodeKV<K,V>* node) {
        NodeKV<K,V>* nextNode = NULL;
        if(node->getLeft() != NULL) {
            sMin.push(node);
            nextNode = node->getLeft();
            while(nextNode->getRight() != NULL) {
                nextNode = nextNode->getRight();
            }
        }
        else {

            if(node->getParent() != NULL)
                nextNode = node->getParent();
            if(!sMin.empty()) {
                while (!sMin.empty() && sMin.top() == nextNode) {
                    if(nextNode->getParent() == NULL)
                        break;
                    nextNode = nextNode->getParent();
                    sMin.pop();
                }
            }
        }
        if(!sMin.empty() && nextNode == sMin.top())
            return NULL;

        return nextNode;

    }


};
