#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll base, ll pow ,ll mod) {
    ll res = 1;
    while (pow > 0) {
        if (pow % 2) {
            res = (res*base)%mod;
            pow--;
        } else {
            base = (base*base)%mod;
            pow /= 2;
        }
    }
    return res%mod;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--){
       int a,b, mod; //(a/b)%mod

       cin >> a >> b >> mod;

       ll x = power(b, mod-2,mod);

       ll ans = ((a)%mod*x) % mod;

       cout << ans << endl;
    }
    return 0;
}
