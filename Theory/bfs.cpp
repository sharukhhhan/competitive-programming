#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++) {
        int start, finish;
        cin >> start >> finish;
        g[start-1].push_back(finish-1);
    }
    cin >> s;
    
    queue<int> q;
    vector<int> d(n), p(n);
    vector<char> used(n);
    q.push(s);
    used[s] = 1;
    p[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + 1; // к прошлой вершине прибавляем один
                p[to] = v; // записываем, откуда пришли к вершине to
            }
        }

        
    }

    int to;
    cin >> to;
    // выведем путь
    if (!used[--to]) {
        cout << "NO PATH";
    } else {
        vector<int> path;
        for (int i = to; i != -1; i = p[i]) { // циклом идем назад по предкам
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (auto& x: path) {
            cout << x+1 << " ";
        }
    }
}