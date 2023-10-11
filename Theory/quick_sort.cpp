#include<bits/stdc++.h>
using namespace std;
vector<int> a;
void quickSort(int l, int r) {
    if (r - l <= 1) {
        return;
    }
    int ind = rand() % (r - l) + l;
    int x = a[ind];
    int m = l;
    int count = 0; // counter нужен для того, чтобы он сдвигал границы второго subarray'а, если попадутся одинаковые элементы
    for (int i = l; i < r; i++) {
        if (a[i] < x) {
            swap(a[i], a[m]);
            m++;
        }
        else if (a[i] == x and i != ind) {
            count += 1;
        }
    }
    quickSort(l, m);
    quickSort(m+count, r);
}
int main() {
    a = {2,12, 1, 3,12, 2, 12, 12, 12, 12};
    quickSort(0, a.size());
    for (auto x: a) {
        cout << x << " ";
    }
}