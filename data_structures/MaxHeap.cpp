// C++ program to show that priority_queue is by default a Max Heap
// g++ MaxHeap.cpp -o output
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main ()
{
    // Creates a max heap
    priority_queue <int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from max heap
    while (pq.empty() == false) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}