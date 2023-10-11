#include <bits/stdc++.h>

using namespace std;

vector <int> s = {3, 1, 2};
vector <vector<int>> permuations;

int main() {

    //next_permutation requires the sorted array as it generates the permutations in lexicographically increasing order
    sort(s.begin(), s.end());

    do {
        permuations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    for (const auto &x: permuations) {
        for (const auto &y: x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}