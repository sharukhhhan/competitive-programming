#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> q(k);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> q[i];
    }

    for(int i = 0; i < k; i++) {
        int x = q[i];
        int l = 0, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;  

            if (v[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (v[l] != x and v[r] != x) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << "\n";
    }

}
