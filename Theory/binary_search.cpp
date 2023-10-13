#include <bits/stdc++.h>

using namespace std;

int upper_binary_search(vector<int>& a, int x) { // max i : a[i] <= x
    int l = -1;
    int r = a.size();
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l;
}

int lower_binary_search(vector<int>& a, int x) { // min i : a[i] >= x
    int l = -1;
    int r = a.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] < x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

int binary_search(vector<int>& a, int x) {
    int l = -1;
    int r = a.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l >= 0 && a[l] == x ? l : -1;
}

int main() {
    vector<int> a = {1, 1, 1, 8, 10, 13, 17, 17, 17, 18};
    int x = 17;
    cout << (upper_bound(a.begin(), a.end(), x) - a.begin()); // min i : a[i] > x -> max : a[i-1] <= x
    cout << "\n";
    cout << (lower_bound(a.begin(), a.end(), x) - a.begin()) << "\n" << endl; // min i : a[i] >= x 

    cout << upper_binary_search(a, x) << "\n";
    cout << lower_binary_search(a, x) << "\n";


}