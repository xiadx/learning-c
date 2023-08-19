#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    vector<int> array = {3, 1, 2, 4, 5};
    priority_queue<int> pq(array.begin(), array.end());
    cout << "top: " << pq.top() << endl;
    pq.pop();
    cout << "top: " << pq.top() << endl;
    cout << "size: " << pq.size() << endl;
    pq.push(7);
    cout << "top: " << pq.top() << endl;
    pq.push(6);
    cout << "top: " << pq.top() << endl;
    return 0;
}
