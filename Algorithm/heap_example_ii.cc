#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array = {3, 1, 5, 2, 4};
    print(array);
    make_heap(array.begin(), array.end());
    cout << "front: " << array.front() << endl;
    make_heap(array.begin(), array.end(), greater<int>());
    cout << "front: " << array.front() << endl;
    print(array);
    pop_heap(array.begin(), array.end());
    print(array);
    array.push_back(0);
    print(array);
    push_heap(array.begin(), array.end());
    print(array);
    sort_heap(array.begin(), array.end());
    print(array);
    return 0;
}
