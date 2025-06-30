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

int knapSack(int cap, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1));

   
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= cap; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] > w)
                dp[i][w] = dp[i - 1][w];
            else
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                
        }
    }
    return dp[n][cap];
}

signed main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int cap = 50;

    cout << knapSack(cap, weight, profit) << endl;

    return 0;
}