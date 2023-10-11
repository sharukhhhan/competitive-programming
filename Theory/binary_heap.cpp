#include <bits/stdc++.h>
using namespace std;

vector<int> heap;

void insert(int x) {
    heap.push_back(x);
    int n = heap.size();
    int i = n - 1;
    while (i > 0 and heap[i] < heap[(i-1)/2]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1) / 2;
    }
}

int remove_min() {
    int res = heap[0];
    int n = heap.size();
    heap[0] = heap[n-1];
    heap.pop_back();
    int i = 0;
    while (true) {
        int j = i;
        if (2*i + 1 < n and heap[2*i + 1] < heap[j]) {
            j = 2*i + 1;
        }
        if (2*i+2 < n and heap[2*i+2] < heap[j]) {
            j = 2*i +2;
        }
        if (i == j) break;

        swap(heap[i], heap[j]);
        i = j;
    }
    return res;
}


int main() {

    heap = {5, 7, 10, 8, 11, 38, 13, 14, 27};
    insert(12);
    remove_min();
    for (int x: heap) {
        cout << x << " ";
    }
}