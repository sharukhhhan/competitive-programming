#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

ll bp(ll b, ll p, ll m){ // b^p % m, binpow()
    if(p == 0){
        return 1;
    }
    if(p % 2 == 1){
        return bp(b, p-1, m) * b % m;
    }else{
        ll a = bp(b, p/2, m);
        return a*a % m;
    }
}
ll phi (ll n){ // euler's function
    ll result = n;
    for(ll i = 2; i*i <= n; ++i){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1){
        result -= result / n;
    }
    return result;
}