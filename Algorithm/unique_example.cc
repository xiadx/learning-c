#include<iostream>
#include<vector>
#include<set>
using namespace std;

void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> array = {3, 3, 2, 2, 1, 4, 5};
    sort(array.begin(), array.end());
    print(array);
    auto it = unique(array.begin(), array.end());
    print(array);
    array.erase(it, array.end());
    print(array);
    cout <<  "===============================" << endl;
    array = {3, 3, 2, 2, 1, 4, 5};
    set<int> s(array.begin(), array.end());
    array.assign(s.begin(), s.end());
    print(array);
    return 0;
}
