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

vector<int> wt, pt, dp;

int knapSack(int W) {
    dp.resize(W + 1, 0);

    for (int i = 1; i <= wt.size(); i++) {
        for (int w = W; w >= 0; w--) {
            if (wt[i - 1] <= w) {
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + pt[i - 1]);
            }
        }
    }
    return dp[W];
}

void solve() {
    int n, w;
    cin >> n >> w;

    wt.resize(n);
    pt.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> pt[i];
    }

    int ans = knapSack(w);
    cout << ans << endl;
}

signed main() {
    faster_code();

    int tt;
    cin >> tt;
    while (tt--) {
    solve();
    }
    return 0;
}
