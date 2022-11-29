//
// Created by c4lculater on 30.11.2022.
//

#include "BITree.cpp"

template<class K, class V>
class NodeDupl : public NodeKV<K,V> {
public:
    NodeKV<K,V>* getSameKeys() {
        return sameKeys;
    }
    void addSameKey(NodeKV<K,V>* nodeToAdd) {
        if(sameKeys == NULL) {
            sameKeys = nodeToAdd;
        }
        NodeKV<K,V> current = this;
        while(current->sameKeys != NULL){
            current = current->sameKeys;
        }
    }
private:
    NodeKV<K,V>* sameKeys = NULL;
};