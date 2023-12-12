#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        g[start-1].push_back(end-1);
    }

    stack<int> stack;
    vector<int> d(n), p(n);
    vector<char> used(n);
    int start;
    cin >> start;
    stack.push(start);
    used[start] = 1;
    p[start] = -1;

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = 1;
                stack.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }

    int to;
    cin >> to;
    if (!used[--to]) {
        cout << "NO PATH!!";
    } else {

        vector<int> path;
        for (int i = to; i != -1; i = p[i]) {
            path.push_back(i);
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    }
}