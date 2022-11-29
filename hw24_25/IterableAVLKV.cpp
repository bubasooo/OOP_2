//
// Created by c4lculater on 30.11.2022.
//

#include "TreeIteratorKV.cpp"

template<class K, class V>
class IterableAVLKV : public AVLTreeKV<K,V> {
public:
    IterableAVLKV() {}
    TreeIteratorKV<K,V> begin() {
        return TreeIteratorKV<K,V>(this->Min(this->getRoot()));
    }

    TreeIteratorKV<K,V> end() {
        return TreeIteratorKV<K,V>(NULL);
    }

    template<class L, class M>
    friend ostream& operator<< (ostream& stream, IterableAVLKV<L,M>& Tree);
};


template<class K,class V>
ostream& operator<< (ostream& stream, IterableAVLKV<K,V>& Tree) {
    auto it = Tree.begin();
    stream << "Key , Values" << '\n';
    while(it != Tree.end()){
        stream << (*it).getKey() << " : " << (*it).getValue() << '\n';
        it++;
    }
    return stream;
}
