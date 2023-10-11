#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> subsets;
// set for collecting subsets
vector <int> subset;
vector <int> original_set = {4, 1, 5, 7, 2};
int n = original_set.size();
void search(int k) {
    if (k == n) {
        // здесь функция понимает, что все элементы обработаны и подмножество сгенерировано 
        subsets.push_back(subset);
    } else {
        // include k into subset
        subset.push_back(original_set[k]);
        search(k + 1);
        // not include k into subset
        subset.pop_back();
        search(k + 1);
    }
}

int main() {
    search(0);
    for (const auto &x: subsets) {
        for (const auto &y: x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}