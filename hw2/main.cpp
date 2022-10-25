#include <iostream>
#include "DListQueue.cpp"
using namespace std;

int main() {
    DListQueue<int> lstq = DListQueue<int>();
    lstq.push(7);
    lstq.push(2);
    lstq.push(3);
    lstq.pop();
    cout << lstq;
}