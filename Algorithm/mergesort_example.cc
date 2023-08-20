#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &array, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid+1, right);
    int i = left, j = mid+1;
    while (i <= mid && j <= right) {
        if (array[j] < array[i]) {
            int tmp = array[j];
            for (int k = j; k > i; --k) array[k] = array[k-1];
            array[i] = tmp;
            ++j;
        }
        else ++i;
    }
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
    merge_sort(array, 0, 4);
    print(array);
    return 0;
}
