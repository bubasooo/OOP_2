//
// Created by c4lculater on 30.11.2022.
//

#include "NodeDupl.cpp"
#include <list>
template<class K, class V>
class BITreeDuplicates : public BITree<K,V> {
public:
    void Add(K key, V value) {
        NodeDupl<K,V>* nodeInTree = BITree<K,V>::searchByKey(key);
        if(nodeInTree == NULL)
            this->BITree<K,V>::Add(key,value);
        else
            nodeInTree->addSameKey(new NodeDupl<K,V>(key,value));
    }
    list<V> operator[] (K key) {
        list<V> lst;
        NodeDupl<K,V>* ls = BITree<K,V>::searchByKey(key);
        if(ls == NULL)
            return lst;
        else {
            while(ls->getSameKeys() != NULL){
                lst.push_back(ls->getValue());
                ls = ls->getSameKeys();
            }
            return lst;
        }
    }

    NodeKV<K,V>* deleteByKey(K key) override {
        NodeDupl<K,V>* delNode = searchByKey(key);
        if(delNode == NULL)
            return NULL;

        if(delNode->getSameKeys() == NULL)
            return deleteByKey(key);

        NodeDupl<K,V> parent = delNode->getParent();
        NodeDupl<K,V> lChild = delNode->getLeft();
        NodeDupl<K,V> rChild = delNode->getRight();
        NodeDupl<K,V> successor = delNode->getSameKeys();

        AVLTreeKV<K,V>::disconnectNode(delNode);
        if(parent.getRight() == delNode)
            AVLTreeKV<K,V>::connectNodes(parent, true);
        else
            AVLTreeKV<K,V>::connectNodes(parent, false);

        AVLTreeKV<K,V>::connectNodes(successor, lChild, true);
        AVLTreeKV<K,V>::connectNodes(successor, rChild, false);

        return delNode;
    }
};
