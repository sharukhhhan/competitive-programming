#include <bits/stdc++.h>

using namespace std;

int main() {
    bitset<10> s;

    s[1] = 1;
    s[3] = 1;

    cout << s[1] << " " << s[0] << " " << s[3] << endl;

    bitset<10> a;
    a[1] = 1;
    a[5] = 1;

    bitset<10> inter = s&a; // intersection
    bitset<10> uni = s | a; // union
    bitset<10> c = (~s); // complement
    bitset<10> diff = s & (~a); // difference s / a
    cout << s << " " << a << endl;
    cout << diff << endl;
}