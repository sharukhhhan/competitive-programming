#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a = {3, 4, 6, 10};

    cout << upper_bound(a.begin(), a.end(), 2) - a.begin() - 1;
    // cout << lower_bound(a.begin(), a.end(), 2) - a.begin();

    cout << upper_bound(a.begin(), a.end(), 11) - a.begin() - 1;
    // cout << lower_bound(a.begin(), a.end(), 11) - a.begin();
}