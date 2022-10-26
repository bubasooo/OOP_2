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
    pop(lst, 'G');
    //list<char> lst2 = filter(pred , lst);
    list<char>::iterator p = lst.begin();
    showList(lst);

    Human human1 = Human().age(11).height(170);
    Human human2 = Human().age(13).height(190);
    Human human3 = Human().age(13).height(190).weight(30);
    Human human4 = Human().age(16).height(156).weight(67);
    list<Human> people;
    push(people , human1);
    push(people , human2);
    push(people , human3);
    push(people , human4);
    for(auto v : people) {
        v.showStatistics();
        cout << '\n';
    }
    //human1.showStatistics();


    return 0;
}
