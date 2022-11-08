//
// Created by c4lculater on 08.11.2022.
//


#include <map>
#include <iostream>
#include <set>

using namespace std;

template<class K, class V>
typename map<K,V>::iterator searchByValue(map<K , V>& enterMap , V value) {
    typename map<K,V>::iterator it_mapus = enterMap.begin();
    while(it_mapus != enterMap.end()) {
        if(it_mapus->second == value)
            return it_mapus;
        it_mapus++;
    }
    return it_mapus;
}

template<class K, class V>
typename map<K,V>::iterator searchByKey(map<K , V>& enterMap , K key) {
    typename map<K, V>::iterator it_mapus = enterMap.find(key);
    return it_mapus;
}

template<class K, class V>
void showTree(map<K, V>& enterMap) {
    cout << "Map:" << "\n";

    for(auto v: enterMap)
        cout << v.first << " -> " << v.second << "\n";
}

template<class K, class V>
map<K, V> filter(bool(*predicat)(typename map<K, V>::iterator), map<K, V>& enterMap) {
    map<K, V> newMap;
    typename map<K, V>::iterator it = enterMap.begin();
    while(it != enterMap.end()){
        if(predicat(it))
            newMap[it->first] = it->second;
        it++;
    }
    return newMap;
}

bool testPedict(map<string , int>::iterator it) {
    return it->second > 4;
}

template <class K, class V>
set<V> retUniqValues(map<K, V>& enterMap) {
    typename map<K, V>::iterator it_mapus = enterMap.begin();
    set<V> newSet;
    while(it_mapus != enterMap.end()) {
        newSet.insert(it_mapus->second);
        it_mapus++;
    }
    return newSet;
}


//
//int main() {
//
//}