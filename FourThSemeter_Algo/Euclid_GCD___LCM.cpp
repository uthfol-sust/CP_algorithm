#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
    if(a==0) return b;

    return GCD(b%a, a);
}

int LCM(int a,int b, int gcd){
    return (a*b)/gcd;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int a,b;
        cin >> a >> b;
        
        int ans = GCD(a,b);
        cout << "GCD ="  << ans << endl;
        cout << "LCM =" <<LCM(a,b,ans) << endl;
    }
}