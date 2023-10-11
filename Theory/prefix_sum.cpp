//
// Created by sharukhhhan on 11/4/22.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v = {{3, 4, 6}, {5, 7, 8}, {5, 8, 10}};
    vector<vector<int>> prefix_sum(4, vector<int> (4, 0));
    for(int i = 1; i<=3; i++){
        for(int j = 1; j <=3; j++){
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1] + v[i-1][j-1];
        }
    }
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i<=3; i++){
        for (int j = 0; j <= 3; j++){
            cout << prefix_sum[i][j] << ' ';
        }
        cout << endl;
    }

    cout << prefix_sum[2][3] - prefix_sum[2][1] - prefix_sum[0][3] + prefix_sum[0][1];

}