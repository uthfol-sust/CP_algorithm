#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define faster_code() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vect vector<int>
#define pb push_back
#define sort(x) sort(x.begin(), x.end());
#define sort_pair(x) sort(x.begin(), x.end(), comp);
const int mod = 1e9 + 7;
const int N = 1e5 + 2;

void prime_factor(int n){
  for(int i=2; i*i<=n; i++){
     if(n%i==0){
        int cnt = 0;
        while(n%i==0){
            cnt ++;
            n/=i;
        }
        cout << i<<"^"<< cnt << ", ";
     }
  }

  if(n>1) cout <<n << "^" <<"1";

  cout << endl;
}

void solve(){
    int n;
    cin >> n;

    prime_factor(n);
}

signed main() {
   // int tt;
   // cin >> tt;
   // while(tt--){
        solve();
   // }
    return 0;
}