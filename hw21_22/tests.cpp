//
// Created by c4lculater on 08.11.2022.
//
#include "task22.cpp"

using namespace std;


void getByValueTEST1() {
    map<string, int> marks;
    marks["Petrov"] = 5;
    marks["Ivanov"] = 4;
    marks["Sidorov"] = 5;
    marks["Nikolaev"] = 3;
    marks["Abramov"] = 4;


    map<string, int>::iterator search = searchByValue(marks, 4);
    if (search == marks.end())
        cout << "Not found";

    else
        cout << "Found in map: " << search->first << " " << search->second;
}




void getByValueTEST2() {
    map<string, int> marks;
    marks["Petrov"] = 5;
    marks["Ivanov"] = 4;
    marks["Sidorov"] = 5;
    marks["Nikolaev"] = 3;
    marks["Abramov"] = 4;

    map<string, int>::iterator search = searchByValue(marks, 0);
    if (search == marks.end())
        cout << "Not found";

    else
        cout << "Found in map: " << search->first << " " << search->second;
}



//bool getByKeyTEST() {
//    map<string, int> marks;
//    marks["Petrov"] = 5;
//    marks["Ivanov"] = 4;
//    marks["Sidorov"] = 5;
//    marks["Nikolaev"] = 3;
//    marks["Abramov"] = 4;
//
//    bool testingScore;
//
//    map<string , int>::iterator search = searchByKey(marks , "Ivanov");
//    testingScore = search == marks.end() ? false : true;
//
//    map<string , int>::iterator search2 = searchByKey(marks , "Bubich");
//    testingScore &= search2 == marks.end() ? true : false;
//
//    return testingScore;
//}
void filterTEST() {
    map<string, int> marks;
    marks["Petrov"] = 5;
    marks["Ivanov"] = 4;
    marks["Sidorov"] = 5;
    marks["Nikolaev"] = 3;
    marks["Abramov"] = 4;

    map<string ,int> newMap = filter(testPedict, marks);
    showTree(newMap);
}

void retUniqValuesTEST() {
    map<string, int> marks;
    marks["Petrov"] = 5;
    marks["Ivanov"] = 4;
    marks["Sidorov"] = 5;
    marks["Nikolaev"] = 3;
    marks["Abramov"] = 4;

    set<int> st = retUniqValues(marks);
    for(auto v: st)
        cout << v << " ";
}

void retElementsBySameKeysTEST() {
    multimap<int, string> marks;
    marks.insert(pair<int, string>(5,"Petrov"));
    marks.insert(pair<int, string>(4,"Ivanov"));
    marks.insert(pair<int, string>(5,"Sidorov"));
    marks.insert(pair<int, string>(3,"Nikolaev"));
    marks.insert(pair<int, string>(4,"Abramov"));

    vector<string> val = retElementsBySameKeys(marks, 4);
    for(auto v: val)
        cout << v << '\n';
}