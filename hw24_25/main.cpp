//
// Created by c4lculater on 30.11.2022.
//

#include "Nation.cpp"
int main() {
    //BITree<int,string> tree = BITree<int, string>();
//    BinTreeKV<int,string> tree = BinTreeKV<int,string>();
//    tree.Add(2, "huk");
//    tree.Add(4,"back");
//    tree.Add(9, "i");
//
//    tree.Delete(new NodeKV<int,string>(2,"lol"),tree.getRoot());
//    //NodeKV<int,string>* v = tree.FindByKey(4,tree.getRoot());
//    //tree.deleteNode(v,false);
//    //cout << v->getKey() << " " << v->getValue() << '\n';
////    if(v->getParent()->getLeft() == v)
////        cout << "LEFT";
////    else
////        cout << "RIGHT";
////    cout << '\n';
//    tree.showTree(tree.getRoot());

    AVLTreeKV<int,string> tree = AVLTreeKV<int,string>();
    tree.Add(5, "lol");
    tree.Add(4, "kek");
    tree.Add(3, "cheburek");
    tree.Delete(new NodeKV<int,string>(3, "kek"), tree.getRoot());
    tree.showTree(tree.getRoot());
}
