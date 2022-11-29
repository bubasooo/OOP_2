//
// Created by c4lculater on 29.11.2022.
//


#include <stack>
#include "AVLTree.cpp"

template<class T>
class TreeIterator {
public:

    TreeIterator() {}
    TreeIterator(Node<T>* nodeO) {node = nodeO;}



    Node<T>& operator*() {
        return (*node);
    }

    TreeIterator<T>& operator++ () {
        node = getNext(node);
        return *this;

    }
    TreeIterator<T>& operator ++ (int v) {
        TreeIterator<T>* it = new TreeIterator<T>(node);
        node = getNext(node);
        return *it;
    }
    TreeIterator& operator -- ()  {
        node = getPrevious(node);
        return *this;
    }
    TreeIterator& operator -- (int v)  {
        TreeIterator<T>* it = new TreeIterator<T>(node);
        node = getPrevious(node);
        return *it;
    }

    bool operator != (TreeIterator<T> other) const {
        return node != other.getNode();
    }


    bool operator == (TreeIterator<T> other) const {
        return !(this != other);
    }

    Node<T>* getNode() {
        return node;
    }

    Node<T>* getNext(Node<T>* node) {
        Node<T>* nextNode = NULL;
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
private:
    Node<T>* node;
    stack < Node<T>* > sMax;
    stack < Node<T>* > sMin;

    Node<T>* getPrevious(Node<T>* node) {
        Node<T>* nextNode = NULL;
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