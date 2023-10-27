#include <bits/stdc++.h>
using namespace std;
unordered_map <char, int> n, p;
int main() {
    n['B'] = 3;
    for (auto x: n) {
        cout << x.first << " " << x.second;
    }
}