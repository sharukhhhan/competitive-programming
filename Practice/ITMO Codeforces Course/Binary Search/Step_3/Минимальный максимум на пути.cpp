// D. Минимальный максимум на пути
// ограничение по времени на тест2 секунды
// ограничение по памяти на тест512 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// Дорожная сеть состоит из n
//  перекрестков и m
//  односторонних дорог, при этом каждая дорога ведет из перекрестка с меньшим номером в перекресток с большим номером. Каждой дороге соответствует некоторое число. Требуется найти путь из перекрестка 1 в перекресток n
// , состоящий из не более d
//  ребер, на котором максимум из чисел, соответствующих ребрам, минимален.

// Входные данные
// Первая строка содержит целые числа n
// , m
//  и d
//  (2≤n≤105
// , 1≤m,d≤105
// ). Следующие m
//  строк содержат тройки чисел ai
// , bi
// , ci
//  (1≤ai<bi≤n
// , 0≤ci≤109
// ), которые означают, что есть дорога, ведущая из перекрестка ai
//  в перекресток bi
// , которой соответствует число ci
// . Для каждой пары перекрестков существует не более одной дороги, которая их соединяет.

// Выходные данные
// В первой строке выведите число ребер в выбранном пути k
//  (k≤d
// ). В следующей строке выведите k+1
//  число — номера перекрестков, которые посещает выбранный путь.

// Если не существует пути из перекрестка 1 в перекресток n
// , состоящего из не более d
//  ребер, выведите одно число −1
// .

// Примеры
// входные данныеСкопировать
// 4 5 2
// 1 2 5
// 2 3 3
// 1 3 7
// 2 4 6
// 3 4 4
// выходные данныеСкопировать
// 2
// 1 2 4 
// входные данныеСкопировать
// 3 3 2
// 1 2 1
// 2 3 2
// 1 3 1
// выходные данныеСкопировать
// 1
// 1 3 
// входные данныеСкопировать
// 3 2 1
// 1 2 1
// 2 3 1
// выходные данныеСкопировать
// -1

#include <bits/stdc++.h>

using namespace std;


bool okay(int mid, int m, int n, int d, vector<vector<pair<int, int>>> g) {
    deque<int> deq;
    vector<int> dist(n);
    vector<bool> used(n);
    deq.push_back(0);
    used[0] = 1;

    while (!deq.empty()) {
        int v = deq.front();
        deq.pop_front();
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i].first;
            if (!used[to] && dist[v] + 1 <= d && g[v][i].second <= mid) {
                used[to] = 1;
                deq.push_back(to);
                dist[to] = dist[v] + 1;
            }
        }
    }


    if (!used[n-1]) {
        return false;
    } else {
        return true;
    }
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        g[from-1].push_back(make_pair(to-1, w));
    }

    int l = -1, r = 1e9+1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (okay(mid, m, n, d, g)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (r == 1e9+1) {
        cout << -1;
    } else {
        deque<int> deq;
        vector<int> dist(n), p(n);
        vector<char> used(n);
        deq.push_back(0);
        used[0] = 1;
        p[0] = -1;

        while (!deq.empty()) {
            int v = deq.front();
            deq.pop_front();
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v][i].first;
                if (!used[to] && dist[v] + 1 <= d && g[v][i].second <= r) {
                    used[to] = 1;
                    deq.push_back(to);
                    dist[to] = dist[v] + 1;
                    p[to] = v;
                }
            }
        }

        vector<int> path;
        for (int i = n - 1; i != -1; i = p[i]) {
            path.push_back(i);
        }

        reverse(path.begin(), path.end());
        cout << dist[n-1] << '\n';
        for (auto x: path) {
            cout << x+1 << " ";
        }
    }

}