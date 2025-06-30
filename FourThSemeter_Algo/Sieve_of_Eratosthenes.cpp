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

void sive_algo(int n){

    vector<bool> prime(n + 1, true); 
    prime[0] = prime[1] = false;
   
    for(int i=2; i*i<=n; i++)
    {
        if(prime[i]){
            for(int j=i*i; j<=n; j+=i)
            {
                prime[j]=false;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(prime[i])
        cout << i << " ";
    }

    cout << endl;
}

signed main() {
    int n;
    cin >> n;

    sive_algo(n);
    return 0;
}