//
// Created by c4lculater on 30.11.2022.
//

#include "Nation.cpp"
int main() {
    BITree<int,string> tree = BITree<int, string>();
    tree.add(2, "huk");
    tree.add(4,"back");
    tree.add(9, "i");
    cout << tree;

}
