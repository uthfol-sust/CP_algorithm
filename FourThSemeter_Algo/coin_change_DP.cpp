#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define faster_code() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ull unsigned long long
#define vect vector<int>
#define pb push_back
#define sort(x) sort(x.begin(), x.end());
#define sort_pair(x) sort(x.begin(), x.end(), comp);
#define PI 3.14159265
const int mod = 1e9 + 7;
const int N = 1e5 + 2;

vector<int> coin;
vector<vector<int>> dp;

int countWays(int n, int sum) {
    if (sum == 0) return 1; 
    if (sum < 0 || n == 0) return 0; 

    if (dp[n][sum] != -1) return dp[n][sum];

    return dp[n][sum] = countWays(n, sum - coin[n - 1]) + countWays(n - 1, sum);
}

void solve() {
    int n, m;
   
     cin >> n >> m;
    coin.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> coin[i];
    }

    dp.assign(m + 1, vector<int>(n + 1, -1));

    cout << countWays(m, n);
}

signed main() {
    faster_code();

    // int tt;
    // cin >> tt;
    // while (tt--) {
     solve();
    // }
    return 0;
}
