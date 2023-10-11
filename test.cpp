#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    function<void(int)> reck = [&](int a) {
        if (a == 5) {
            return;
        }
        cout << n << "\n";
        n++;
        reck(n);
    };

    reck(n);
}