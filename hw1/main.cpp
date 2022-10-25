//
// Created by c4lculater on 26.10.2022.
//

#include "Human.cpp"

int main() {

    list<char> lst;
    int i = 0;
    for(i = 0;i < 10;i += 2)
        lst.push_back('A' + i);
    push(lst, 'X');
    //pop(lst, 'G');
    //list<char> lst2 = filter(pred , lst);
    list<char>::iterator p = lst.begin();
    /*
    while(p != lst.end()) { //перемещение по контейнеру с помощью указателя, нет операции [i]
        cout << *p << "";
        p++;
    }
    */
    showList(lst);
    Human human1 = Human().age(11).height(170);
    human1.showStatistics();
    return 0;
}
