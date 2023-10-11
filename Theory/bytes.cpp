#include <bits/stdc++.h>

using namespace std;

int main() {
    int k = 0;
    cout << (7 & (1 << k)) << endl; // if == 0 -> bit(k) = 0 else bit(k) = 1 
    cout << (7 | (1 << k)) << endl; // set bit(k) to 1
    cout << (7 & ~(1 << k)) << endl; // set bit(k) to 0
    cout << (7 ^ (1 << k)) << endl; // inverst bit(k)
    cout << (7 & (7 -1)) << endl; // сбрасывает последний единичный бит x в нуль. If == 0 -> является степенью двойки
    cout << (7 & (-7)) << endl; // сбрасывает в нуль все единичные биты, кроме последнего
    cout << (7 | (7 - 1)) << endl; // инвертирует все биты после последнего единичного


    int x = 123; // 1111011
    cout << __builtin_clz(x) << endl; // количество нулей в начале двоичного представления (int = 4 bytes)
    cout << __builtin_ctz(x) << endl; // amount of zeroes in the end
    cout << __builtin_popcount(x) << endl; // amount of ones

}