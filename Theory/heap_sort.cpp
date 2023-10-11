#include <bits/stdc++.h>
using namespace std;

vector<int> heap;

void sift_up(int i) {
    while (i > 0 and heap[i] < heap[(i-1)/2]) {
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1) / 2;
    }
}

void sift_down(int i, int size) {
    while (true) {
        int j = i;
        if (2*i + 1 < size and heap[2*i + 1] < heap[j]) {
            j = 2*i + 1;
        }
        if (2*i+2 < size and heap[2*i+2] < heap[j]) {
            j = 2*i + 2;
        }
        if (i == j) break;

        swap(heap[i], heap[j]);
        i = j;
    }
}


int main() {

    heap = {43, 11, 1, 343, 12, 4};

    for (int i = 0; i < heap.size(); i++) {
        sift_up(i);
    }
    for (int x: heap) {
        cout << x << " ";
    }


    for (int i = heap.size() - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        sift_down(0, i);
    }
    for (int x: heap) {
        cout << x << " ";
    }
}