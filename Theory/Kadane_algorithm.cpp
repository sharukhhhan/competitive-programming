#include <bits/stdc++.h>

using namespace std;

int main() {
    vector <int> a = {2, -1, 3, 4, -5};
    int sum = 0, best = 0;

    for (int i = 0; i < a.size(); i++) {
        sum = max(a[i], sum + a[i]);
        best = max(best, sum);
    }

    cout << best;
}