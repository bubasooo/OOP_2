//
// Created by c4lculater on 08.11.2022.
//

#include "task21.cpp"
#include <vector>

template<class K, class V>
typename multimap<K,V>::iterator searchByValueMulti(multimap<K , V>& enterMap , V value) {
    typename multimap<K,V>::iterator it_mapus = enterMap.begin();
    while(it_mapus != enterMap.end()) {
        if(it_mapus->second == value)
            return it_mapus;
        it_mapus++;
    }
    return it_mapus;
}

template<class K, class V>
typename multimap<K,V>::iterator searchByKeyMulti(multimap<K , V>& enterMap , K key) {
    typename multimap<K, V>::iterator it_mapus = enterMap.find(key);
    return it_mapus;
}

template<class K, class V>
void showTreeMulti(multimap<K, V>& enterMap) {
    cout << "MultiMap:" << "\n";

    for(auto v: enterMap)
        cout << v.first << " -> " << v.second << "\n";
}

template<class K, class V>
multimap<K, V> filterMulti(bool(*predicat)(typename multimap<K, V>::iterator), multimap<K, V>& enterMap) {
    multimap<K, V> newMultiMap;
    typename multimap<K, V>::iterator it = enterMap.begin();
    while(it != enterMap.end()){
        if(predicat(it))
            newMultiMap[it->first] = it->second;
        it++;
    }
    return newMultiMap;
}

template <class K, class V>
set<V> retUniqValuesMulti(multimap<K, V>& enterMap) {
    typename multimap<K, V>::iterator it_mapus = enterMap.begin();
    set<V> newSet;
    while(it_mapus != enterMap.end()) {
        newSet.insert(it_mapus->second);
        it_mapus++;
    }
    return newSet;
}

template<class K, class V>
vector<V> retElementsBySameKeys(multimap<K,V>& enterMap,K key) {
    vector<V> valuesWithSameKeys;
    typename multimap<K, V>::iterator it_multiMapus = enterMap.begin();
    while(it_multiMapus != enterMap.end()) {
        if(it_multiMapus->first == key)
            valuesWithSameKeys.push_back(it_multiMapus->second);
        it_multiMapus++;
    }
    return valuesWithSameKeys;
}

int main() {
    cout <<"Nice";
    return 0;
}