
#include "task22.cpp"

bool testPredict(map<string , int>::iterator it) {
    return it->second > 4;
}

int main() {
    map<string, string> mapus;
    mapus["Vladimir Putin"] = "Kremlin";
    mapus["Dmitry Medvedev"] = "Kremlin";
    mapus["Michail Gorbachev"] = "RIP";
    mapus["Student MIREA"] = "Moscow";
    mapus["Student Chine"] = "Pekin";
    ///
    map<string, int> marks;
    marks["Petrov"] = 5;
    marks["Ivanov"] = 4;
    marks["Sidorov"] = 5;
    marks["Nikolaev"] = 3;
    marks["Abramov"] = 4;

    //Test1 getByValue()
    map<string, int>::iterator search = searchByValue(marks, 4);
    if (search == marks.end())
        cout << "Not found";
    else
        cout << "Found in map: " << search->first << " " << search->second << '\n';

    cout << '\n';

    //Test2 filter()
    map<string ,int> newMap = filter(testPredict, marks);
    showTree(newMap);
    cout << '\n';
    //

    cout << '\n';

    //Test 3 return unique values
    set<int> st = retUniqValues(marks);
    for(auto v: st)
        cout << v << " ";
    cout << '\n';
    //

    cout << '\n';

    //Task4 return element by same keys
    multimap<int, string> mark;
    mark.insert(pair<int, string>(5,"Petrov"));
    mark.insert(pair<int, string>(4,"Ivanov"));
    mark.insert(pair<int, string>(5,"Sidorov"));
    mark.insert(pair<int, string>(3,"Nikolaev"));
    mark.insert(pair<int, string>(4,"Abramov"));

    vector<string> val = retElementsBySameKeys(mark, 4);
    for(auto v: val)
        cout << v << '\n';
    cout << '\n';
    //

    cout << '\n';
}