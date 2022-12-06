//
// Created by c4lculater on 30.11.2022.
//

#include "IterableAVLKV.cpp"

template<class K, class V>
class BITree : public IterableAVLKV<K,V> {
public:
    NodeKV<K,V>* searchByKey(K key) {
        return IterableAVLKV<K,V>::Find(key);
    }
    NodeKV<K,V>* searchByValue(V value) {
        auto it = this->begin();
        while((*it).getValue == value && it != this->end())
            it++;
        return *it;
    }
    void add(K key, V value) {
        IterableAVLKV<K,V>::Add(key, value);
    }
    NodeKV<K,V>* min() {
        return IterableAVLKV<K,V>::Min(this->getRoot());
    }
    NodeKV<K,V>* max() {
        return IterableAVLKV<K,V>::Max(this->getRoot());
    }

    virtual NodeKV<K,V>* deleteByKey(K key) {
        return IterableAVLKV<K,V>::Delete(key);
    }

};
