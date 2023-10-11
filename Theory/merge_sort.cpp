#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();
    vector<int> res(n + m);

    int i = 0, j = 0, k = 0;

    while (i < n or j < m) {
        if (j == m or (i < n and a[i] < b[j])) {
            res[k++] = a[i++];
        } else {
            res[k++] = b[j++];
        }
    }
    return res;
}

vector<int> mergeSort(vector<int> v) {
    int n = v.size();

    if (n == 1) {
        return v;
    }

    vector<int> vl(v.begin(), v.begin()+n/2);
    vector<int> vr(v.begin()+n/2, v.end());

    vl = mergeSort(vl);
    vr = mergeSort(vr);

    return merge(vl, vr);
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> sorted = mergeSort(v);

    for (int i: sorted) {
        cout << i << " ";
    }
}
