#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void print(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// 1 priority queue
vector<int> topk(vector<int> input, int k) {
    int n = input.size();
    vector<int> r;
    if (n <= 0 || k > n) return r; 
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i) {
        pq.push(input[i]);
    }
    for (int i = k; i < n; ++i) {
        if (input[i] < pq.top()) {
            pq.pop();
            pq.push(input[i]);
        }
    }
    while (!pq.empty()) {
        r.push_back(pq.top());
        pq.pop();
    }
    return r;
}

// 2 algorithm heap
vector<int> topk_ii(vector<int> input, int k) {
    int n = input.size();
    vector<int> r;
    if (n <= 0 || k > n) return r;
    for (int i = 0; i < k; ++i) {
        r.push_back(input[i]);
    }
    make_heap(r.begin(), r.end());
    for (int i = k; i < n; ++i) {
        if (input[i] < r[0]) {
            pop_heap(r.begin(), r.end());
            r.pop_back();
            r.push_back(input[i]);
            push_heap(r.begin(), r.end());
        }
    }
    return r;
}

// 3 adjust heap 
void adjust_heap(vector<int> &array, int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int target = i;
    if  (left < n && array[left] > array[target]) target = left;
    if (right < n && array[right] > array[target]) target = right;
    if (target != i) {
        swap(array[target], array[i]);
        adjust_heap(array, target, n);
    }
}

void make_heap_iii(vector<int> &array) {
    int n = array.size();
    for (int i = (n-1)/2; i >= 0; --i) {
        adjust_heap(array, i, n);
    }
}

vector<int> topk_iii(vector<int> input, int k) {
    int n = input.size();
    vector<int> r;
    if (n <= 0 || k > n) return r;
    for (int i = 0; i < k; ++i) {
        r.push_back(input[i]);
    }
    make_heap_iii(r);
    for (int i = k; i < n; ++i) {
        if (input[i] < r[0]) {
            r[0] = input[i];
            adjust_heap(r, 0, k);
        }
    }
    return r;
}

// 4 quick sort
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

vector<int> topk_iiii(vector<int> input, int k) {
    int n = input.size();
    vector<int> r;
    if (n <= 0 || k > n) return r;
    quick_sort(input, 0, n-1);
    r.assign(input.begin(), input.begin() + k);
    return r;
}

int main() {
    vector<int> array = {1, 3, 5, 2, 4};
    int k = 3;
    cout << "topk :";
    print(topk(array, 3));
    cout << "topk_ii :";
    print(topk_ii(array, 3));
    cout << "topk_iii :";
    print(topk_iii(array, 3));
    cout << "topk_iiii :";
    print(topk_iiii(array, 3));
    return 0;
}
