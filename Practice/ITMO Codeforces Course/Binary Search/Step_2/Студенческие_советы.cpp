// G. Студенческие советы
// ограничение по времени на тест0.5 секунд
// ограничение по памяти на тест256 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// Задано число k
// . Каждый студенческий совет должен состоять из k
//  студентов. Важное правило — каждый совет состоит из студентов из разных групп. То есть никакие два студента из одной группы не могут оказаться в одном совете.

// Конечно, каждый студент должен входить не более чем в один совет (возможно, что некоторые студенты не входят ни в один).

// Задан массив a[1..n]
// , где a[i]
//  — количество студентов в i
// -й группе. Какое максимальное число советов может быть образовано?

// Входные данные
// В первой строке задано k
//  (2≤k≤20
// ). Во второй строке задано n
//  (k≤n≤50
// ). Затем заданы элементы a[1],a[2],…,a[n]
//  (1≤a[i]≤109
// ).

// Выходные данные
// Выведите искомое значение.

// Примеры
// входные данныеСкопировать
// 3
// 5
// 4
// 4
// 4
// 4
// 4
// выходные данныеСкопировать
// 6
// входные данныеСкопировать
// 4
// 6
// 1
// 2
// 3
// 4
// 5
// 6
// выходные данныеСкопировать
// 5

#include <bits/stdc++.h>
using namespace std;

bool ok(long long mid, vector<int> a, int k) {
    long long st = k * mid;
    for (int i = 0; i < a.size(); i++) {
        st -= min((long long)(a[i]), mid);
    }

    return st <= 0;
} 

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = 1, r = 25 * 1e9 + 1;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (ok(mid, a, k)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
}