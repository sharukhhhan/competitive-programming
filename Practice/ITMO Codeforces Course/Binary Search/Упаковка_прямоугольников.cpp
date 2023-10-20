// A. Упаковка прямоугольников
// ограничение по времени на тест2 секунды
// ограничение по памяти на тест512 мегабайт
// вводстандартный ввод
// выводстандартный вывод
// Есть n
//  прямоугольников одинакового размера: w
//  в ширину и h
//  в длину. Требуется найти квадрат минимального размера, в который можно упаковать данные прямоугольники. Прямоугольники при этом нельзя поворачивать.


// Входные данные
// Ввод содержит три целых числа: w
// , h
// , n
//  (1≤w,h,n≤109
// ).

// Выходные данные
// Выведите минимальную длину стороны квадрата, в который можно упаковать заданные прямоугольники.

// Пример
// входные данныеСкопировать
// 2 3 10
// выходные данныеСкопировать
// 9

#include <bits/stdc++.h>

using namespace std;

bool good(long long w, long long h, long long n, long long m) {
    return (m / w) * (m / h) >= n;
}

int main() {
    long long w, h, n;
    cin >> w >> h >> n;

    long long  l = 0, r = 1; // l должен быть точно неподходящим

    while (!good(w, h, n, r)) {
        r *= 2; // здесь мы ищем точный r, чтобы он был подходящий
    }

    while (r - l > 1) { // здесь binary search ищет минимальную величину, когда функция дает output  1
        long long m = (l + r) / 2;

        if (good(w, h, n, m)) {
            r = m;
        } else {
            l = m;
        }

    }

    cout << r << '\n';

}