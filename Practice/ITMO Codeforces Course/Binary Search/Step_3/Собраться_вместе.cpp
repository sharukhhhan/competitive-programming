// A. Собраться вместе
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест256 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// На прямой расположены n
//  человек, им нужно собраться в одной точке. Про каждого человека известно его текущее положение xi
//  и его скорость vi
// . Помогите им узнать, за какое минимальное время они могут собраться в одной точке.

// Входные данные
// Первая строка содержит целое число n
//  (1≤n≤105
// ), следующие n
//  строк содержат пары целых чисел xi
//  и vi
//  (−109≤xi≤109
// , 1≤vi≤109
// ).

// Выходные данные
// Выведите одно число — минимальное время, за которое люди могут собраться в одной точке. Ответ будет считаться верным, если относительная или абсолютная погрешность не превышает 10−6
// .

// Пример
// входные данныеСкопировать
// 5
// -1 5
// 10 3
// 4 2
// 7 10
// 8 1
// выходные данныеСкопировать
// 1.5

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> a; 

bool okay(double T) {
    vector<pair<double, double>> intervals(n);
    for (int i = 0; i < n; i++) {
        intervals[i] = make_pair(a[i].first - a[i].second*T, a[i].first + a[i].second*T);
    }
    pair<double, double> intersection = {-1e9, 1e9};
    for (int i = 0; i < n; i++) {
        intersection.first = max(intersection.first, intervals[i].first);
        intersection.second = min(intersection.second, intervals[i].second);
    }
    
    return (intersection.first <= intersection.second) ? true : false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        a.push_back(make_pair(x, v));
    }

    double l = 0, r = 1;
    while (!okay(r)) {
        r *= 2;
    }

    for (int i = 0; i < 100; i++) {
        double mid = (l + r) * 0.5;

        if (okay(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << setprecision(7) << r << "\n";

}