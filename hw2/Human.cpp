//
// Created by c4lc on 26.10.22.
//

//
// Created by c4lculater on 26.10.2022.
//
#include "iostream"
using namespace std;
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
            return h_age > h1.getAge();

        if(h_height != h1.getHeight())
            return h_height > h1.getHeight();

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
            return h_age < h1.getAge();

        if(h_height != h1.getHeight())
            return h_height < h1.getHeight();

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

