#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long 

bool prime_test(int n){
    if(n<2) return false;
    else if(n<=3) return true;
    else if(n%2==0) return false;
    
    for(int i=3; i*i<=n; i++){
        if(n%i==0)
        return false;
    }

    return true;
}

void solve(){
    int n;
    cin >> n;

    cout << (prime_test(n)? "Prime": "Not prime" )<< endl;
}

signed main()
{
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}