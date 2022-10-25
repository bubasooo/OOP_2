#include <iostream>
//#include "DListQueue.cpp"
#include "OrderD.cpp"
using namespace std;

int main() {
    //DListQueue<int> lstq = DListQueue<int>();
    OrderD<int> lstq = OrderD<int>();
    lstq.push(7);
    lstq.push(2);
    lstq.push(3);
    //lstq.pop();
    cout << lstq;
}