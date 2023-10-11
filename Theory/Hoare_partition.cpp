#include <bits/stdc++.h>
using namespace std;
// алгоритм Хоара
vector<int> arr;
int find(int l, int r, int k) {
    if (r - l == 1) {
        return arr[l];
    }
    int ind = rand() % (r - l) + l;
    int x = arr[ind];
    int m = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < x) {
            swap(arr[i], arr[m]);
            m++;
        }
    }

    if (k < m) {
        find(l, m, k);
    } else {
        find(m, r, k);
    }
}
int main() {
    arr = {4, 1, 5, 7, 3, 2};
    cout << find(0, arr.size(), 2);
}