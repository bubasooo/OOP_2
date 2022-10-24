//
// Created by c4lculater on 25.10.2022.
//

#include "hw1.h"

#include <list>
#include <iostream>
using namespace std;

/*
template<class T>
void insert(list<T>& lst, T element) {
    typename list<T>::iterator p = lst.begin();
    while (p != lst.end()) {
        if (*p > element)
            break;
        p++;
    }
    lst.insert(p, element);
}
 */
class Human {
public:

    int getAge() const {
        return h_age;
    }

    int getHeight() const {
        return h_height;
    }

    int getWeight() const {
        return h_weight;
    }

    const string& getSurname() const {
        return h_surname;
    }

    const string& getName() const {
        return h_name;
    }

    bool getSex() const {
        return h_sex;
    }

    const string& getBirthdayDate() const {
        return h_birthdayDate;
    }

    const string& getPhoneNumber() const {
        return h_phoneNumber;
    }

    const string& getAdress() const {
        return h_adress;
    }

    void showStatistics() {
        cout << "Age : " << h_age << "\n";
        cout << "Weight : " << h_weight << "\n";
        cout << "Height :  " << h_height << "\n";
        cout << "Surname : " << h_surname << "\n";
        cout << "Name : " << h_name << "\n";
        cout << "Sex : " << h_sex << "\n";
        cout << "Adress : " << h_adress << "\n";
        cout << "Phone :  " << h_phoneNumber << "\n";
        cout << "Born :  " << h_birthdayDate << "\n";
    }
    bool operator < (Human h1) const {
        if(h_age != h1.getAge())
            return h_age < h1.getAge();

        if(h_height != h1.getHeight())
            return h_height < h1.getHeight();

        if(h_weight != h1.getWeight())
            return h_weight < h1.getWeight();

        if(h_surname != h1.getSurname())
            return h_surname < h1.getSurname();

        if(h_name != h1.getName())
            return h_name < h1.getName();

        return false;
    }
    bool operator > (Human h1) const {
        if(h_age != h1.getAge())
            return h_age > h1.getAge();

        if(h_height != h1.getHeight())
            return h_height > h1.getHeight();

        if(h_weight != h1.getWeight())
            return h_weight > h1.getWeight();

        if(h_surname != h1.getSurname())
            return h_surname > h1.getSurname();

        if(h_name != h1.getName())
            return h_name > h1.getName();

        return false;
    }
    Human() {}
    Human age(int hAge) {
        h_age = hAge;
        return *this;
    }

    Human height(int hHeight) {
        h_height = hHeight;
        return *this;
    }
    Human weight(int hWeight) {
        h_weight = hWeight;
        return *this;
    }
    Human surname(string& hSurname) {
        h_surname = hSurname;
        return *this;
    }
    Human name(string& hName) {
        h_name = hName;
        return *this;
    }
    Human sex(bool hSex) {
        h_sex = hSex;
        return *this;
    }
    Human birthDate(string& hBirthDate) {
        h_birthdayDate = hBirthDate;
        return *this;
    }
    Human phoneNumber(string& hPhoneNumber) {
        h_phoneNumber = hPhoneNumber;
        return *this;
    }
    Human adress(string& hAdress) {
        h_adress = hAdress;
        return *this;
    }
private:
    int h_age = 18;
    int h_height = 170;
    int h_weight = 70;
    string h_surname = "";
    string h_name = "";
    bool h_sex = true;
    string h_birthdayDate = "01.01.1970";
    string h_phoneNumber = "8-900-000-00-00";
    string h_adress = "";

};

template<class T>
void push(list<T>& lst, T element) {
    typename list<T>::iterator pointer = lst.begin();
    while (pointer != lst.end()) {
        if (*pointer > element)
            break;
        pointer++;
    }
    lst.insert(pointer, element);
}

template<class T>
T pop(list<T>& lst , T element) {
    lst.remove(element);
    return *(--lst.end());
}


template <class T>
list<T> filter(bool(*predicat)(T), list<T>& lst) {
    list<T> newlist;
    for (T node: lst)
        if (predicat(node))
            push(newlist, node);
    return newlist;
}

template <class T>
void showList(list<T>& lst) {
    typename list<T>::iterator pointer = lst.begin();
    while(pointer != lst.end()) {
        cout << *pointer << " ";
        pointer++;
    }
}

bool pred(char a) {
    return a != 'I';
}



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

