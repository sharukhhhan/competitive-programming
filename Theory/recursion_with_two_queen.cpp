#include <bits/stdc++.h>

using namespace std;

int n = 8;
int cnt = 0;
vector<int> col(n);
vector<int> diag1((n-1)*2+1);
vector<int> diag2((n-1)*2+1);

void search(int y) {
    if (y == n) {
        cnt++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0; 
    }
}

int main() {
    search(0);
    cout << cnt;
}