#include <bits/stdc++.h>
using namespace std;
string rec;
int b = 0, s = 0, c = 0;
int nb, ns, nc, pb, ps, pc;
long long money;

bool okay(long long mid) {
    long long lb = (nb - mid*b) < 0 ? (nb - mid*b) : 0; 
    long long ls = (ns - mid*s) < 0 ? (ns - mid*s) : 0; 
    long long lc = (nc - mid*c) < 0 ? (nc - mid*c) : 0;
    return ((lb * pb  + ls * ps + lc * pc) + money >= 0) ? true : false;
}

int main() {
    cin >> rec;
    for (int i = 0; i < rec.size(); i++) {
        if (rec[i] == 'B') {
            b++;
        } else if (rec[i] == 'S') {
            s++;
        } else {
            c++;
        }
    }
    cin >> nb >> ns >> nc >> pb >> ps >> pc;
    cin >> money;

    long long l = 0, r = 2*1e12;

    while (r - l > 1) {
        long long mid = (r + l) / 2;

        if (okay(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << "\n";
    
}