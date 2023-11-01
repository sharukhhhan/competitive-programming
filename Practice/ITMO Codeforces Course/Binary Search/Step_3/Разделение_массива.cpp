// B. Разделение массива
// ограничение по времени на тест1 секунда
// ограничение по памяти на тест256 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// Дан массив из n
//  положительных целых чисел. Нужно разбить его на k
//  отрезков так, чтобы максимальная сумма на отрезке была минимально возможной.

// Входные данные
// Первая строка содержит целые числа n
//  и k
//  (1≤k≤n≤105
// ). Вторая строка содержит элементы массива ai
//  (1≤ai≤109
// ).

// Выходные данные
// Выведите одно число — минимально возможную максимальную сумму на отрезке.

// Пример
// входные данныеСкопировать
// 10 4
// 1 3 2 4 10 8 4 2 5 3
// выходные данныеСкопировать
// 12

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool okay(long long x) {
    long long sum = 0;
    int curr_num_groups = 1;
    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= x) {
            sum += a[i];
        } else {
            sum = a[i];
            if (sum > x) {
                return false;
            }
            curr_num_groups++;
        }
    }
    if (curr_num_groups <= k) return true;
    else return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    long long l = 0, r = 1e14+1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (okay(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << "\n";
}