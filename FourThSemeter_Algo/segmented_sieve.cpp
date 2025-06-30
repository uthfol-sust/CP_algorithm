#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define faster_code() ios_base::sync_with_stdio(false); cin.tie(NULL);
const int mod = 1e9 + 7;
const int N = 1e5 + 2;

vector<int> v;

void sive(int n){
    vector<bool> prime(n + 1, true); 
   
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
      v.push_back(i);
    }
}

void seg_sieve(int l, int r){
   if(l==1) l++;
   int mx = r-l+1;
   vector<bool>arr(mx+1,true);

   for( auto p:v){
    if(p*p<=r){
        int it = (l/p)*p;
        if(it<l) it+=p;
        for( ; it<=r; it+=p){
            if(it!=p) 
            arr[it-l]=false;
        }
    }
   }

   for(int i=0; i<mx; i++)
   {
    if(arr[i])
    cout << i+l << " " ;
   }

   cout <<endl;
}

signed main() {
   sive(N);
   int tt;
   cin >> tt;
   while(tt--)
   {
    int l,r;
    cin >> l >> r;
    
    seg_sieve(l,r);
   }
   return 0;
}