//
// Created by c4lculater on 29.11.2022.
//

#include "TreeIterator.cpp"

template<class T>
class IterableAVL : public AVLTree<T> {
public:
    IterableAVL() {}
    TreeIterator<T> begin() {
        return TreeIterator<T>(this->Min(this->getRoot()));
    }

    TreeIterator<T> end() {
        return TreeIterator<T>(NULL);
    }

    template<class E>
    friend ostream& operator<< (ostream& stream, IterableAVL<E>& Tree);
};


template<class T>
ostream& operator<< (ostream& stream, IterableAVL<T>& Tree) {
    auto it = Tree.begin();
    while(it != Tree.end()){
        stream << (*it).getData() << " ";
        it++;
    }
    return stream;
}


//int main() {
//    IterableAVL<int> T = IterableAVL<int>();
//
//    for (int i = 0; i < 88; i++)
//        T.Add(i);
//    auto it = T.begin();
////    auto it = TreeIterator<int>(T.Max(T.getRoot()));
////    while(it != T.begin()) {
////        cout << (*it).getData() << " ";
////        it--;
////    }
//    it++;
//    it++;
//    it++;
//    it++;
//    it++;
//    it++;
//    it++;
//    it--;
//    it--;
//
//
//    cout << (*it).getData();
//    //cout << T;
//    return 0;
//}
