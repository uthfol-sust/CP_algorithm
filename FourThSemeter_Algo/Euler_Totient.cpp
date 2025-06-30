#include<bits/stdc++.h>
using namespace std;

int Totient(int n){
    int res = n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0)
            {
                n /= i;
            }
            res = res * (i-1);
            res /= i;
        }
    }

    if(n>1){
        res = res * (n-1);
        res /= n;
    }

    return res;
}

int main()
{
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;

        cout << Totient(n) << endl;
    }
}