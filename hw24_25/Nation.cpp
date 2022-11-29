//
// Created by c4lculater on 30.11.2022.
//
#include "BITreeDuplicates.cpp"
class Nation {
public:
    Nation() {}
    Nation name(string name0) {
        names = name0;
    }
    Nation capital(string capital0) {
        capitals = capital0;
    }
    Nation lang(string lang0) {
        langs = lang0;
    }
    Nation populus(long populus0) {
        populuss = populus0;
    }
    Nation square(long square0) {
        squares = square0;
    }

    const string &getNames() const {
        return names;
    }

    const string &getCapitals() const {
        return capitals;
    }

    const string &getLangs() const {
        return langs;
    }

    long getPopuluss() const {
        return populuss;
    }

    long getSquares() const {
        return squares;
    }

    bool operator < (Nation other) {
        return names > other.getNames() && squares < other.squares && populuss < other.populuss;
    }
    bool operator > (Nation other) {
        return names < other.getNames() && squares > other.squares && populuss > other.populuss;
    }
private:
    string names;
    string capitals;
    string langs;
    long populuss;
    long squares;
};
