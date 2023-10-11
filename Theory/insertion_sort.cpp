#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {7, 3, 1, 4, 5, 10, 12, 2};
    for (int i = 0; i < a.size(); i++) {
        int j = i;
        while (j > 0 and a[j] < a[j-1]) {
            swap(a[j-1], a[j]);
            j--;
        }
    }
    for (auto x: a) {
        cout << x << " ";
    }
}

