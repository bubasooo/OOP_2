//
// Created by c4lculater on 07.12.2022.
//

using namespace std;

#include <iostream>
#include <queue>

template<typename T>
void print_queue(T& q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
int main() {
    priority_queue<int> q;
    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q.push(n);
    print_queue(q);
}