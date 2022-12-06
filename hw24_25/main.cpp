//
// Created by c4lculater on 30.11.2022.
//

#include "Nation.cpp"
int main() {
    //BITree<int,string> tree = BITree<int, string>();
    BinTreeKV<int,string> tree = BinTreeKV<int,string>();
    tree.Add(2, "huk");
    tree.Add(4,"back");
    tree.Add(9, "i");
    tree.Delete(new NodeKV<int,string>(9,"lol"),tree.getRoot());
    tree.showTree(tree.getRoot());

}
