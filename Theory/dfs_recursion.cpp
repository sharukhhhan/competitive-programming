#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<char> used(n);
    for (int i = 0; i < k; i++) {
        int st, fn;
        cin >> st >> fn;
        g[st-1].push_back(fn-1);
    }
    int start;
    cin >> start;

    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (int i: g[v]) {
            if (!used[i]) {
                dfs(i);
            }
        }
    };   

    dfs(start);

}