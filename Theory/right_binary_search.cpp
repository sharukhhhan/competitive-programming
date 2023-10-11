#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n+2);
    v[0] = INT32_MIN;
    v[n+1] = INT32_MAX;
    vector<int> q(k);
    for(int i = 1; i < n+1; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> q[i];
    }

    for(int i = 0; i < k; i++) {
        int x = q[i];
        int l = 0, r = n+1;
        while(r - l > 1) {
            int m = (r + l) / 2;
            if (v[m] < x) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << r << "\n";
    }

}