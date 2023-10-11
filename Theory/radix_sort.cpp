#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {4, 1, 3, 43, 124, 43};
    int n = v.size();
    int max = v[0];
    for (auto x: v) {
        if (x > max) {
            max = x;
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> output(n);
        vector<int> count(10);

        for (int i = 0; i < n; i++) {
            count[(v[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1]; // здесь мы превращаем count в prefix sum array
        }

        for (int i = n - 1; i >= 0; i--) {
            output[count[(v[i] / exp) % 10] -
                   1] = v[i]; // по факту каждый элемент в prefix sum'е показывает сколько элементов было до него, включая его самого. исходя их этого, можно определить его позицию (просто вычитает 1, так как сам элемент тоже включен)
            count[(v[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            v[i] = output[i];
        }
    }
}