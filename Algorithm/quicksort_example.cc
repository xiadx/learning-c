#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &array, int left, int right) {
    int p = array[left];
    while  (left < right) {
        while (left < right && array[right] >= p) --right;
        swap(array[left], array[right]);
        while (left < right && array[left] <= p) ++left;
        swap(array[left], array[right]);
    }
    return left;
}


void quick_sort(vector<int> &array, int left, int right) {
    if (left >= right) return;
    int p = partition(array, left, right);
    quick_sort(array, 0, p-1);
    quick_sort(array, p+1, right);
}

void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> array = {3, 1, 2, 4, 5};
    quick_sort(array, 0, 4);
    print(array);
    return 0;
}
