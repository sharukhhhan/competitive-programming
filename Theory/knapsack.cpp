#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> w = {2, 3, 4, 5};
    vector<int> c = {3, 4, 5, 6};

    int s = 5;
    int n = c.size();

    vector <vector<int>> dp(n+1, vector<int>(s+1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j-w[i-1]] + c[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (auto& x: dp) {
        for (auto& y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    int i = n, j = s;
    while (i >  0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            cout << i << " ";
            j -= w[i - 1];
            i--;
        }
    }
}