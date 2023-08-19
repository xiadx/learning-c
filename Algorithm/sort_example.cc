#include<iostream>
#include<vector>
using namespace std;

void adjust_heap(vector<int> &array, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int target = i;
    if (left < n && array[left] > array[target]) target = left;
    if (right < n && array[right] > array[target]) target = right;
    if (target != i) {
        swap(array[i], array[target]);
        adjust_heap(array, target, n);
    }
}

void make_heap(vector<int> &array) {
    int n = array.size();
    for (int i = (n - 1)/2; i >= 0; --i) {
        adjust_heap(array, i, n);
    }
}

void heap_sort(vector<int> &array) {
    int n = array.size();
    make_heap(array);
    for (int i = n-1; i >= 1; --i) {
        swap(array[0], array[i]);
        adjust_heap(array, 0, i);
    }
    
}

int partition(vector<int> &array, int left, int right) {
    int p = array[left];
    while (left < right) {
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
    quick_sort(array, left, p-1);
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
    vector<int> array = {2, 3, 1, 5, 4};
    print(array);
    heap_sort(array);
    cout << "heap sort: ";
    print(array);
    array = {2, 3, 1, 5, 4};
    print(array);
    quick_sort(array, 0, 4);
    cout << "quick sort: ";
    print(array);
    return 0;
}
