#include<bits/stdc++.h>
using namespace std;

int ExtendedGCD(int a, int b, int &x, int &y){
   
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    
    
    int x1,y1;
    int gcd = ExtendedGCD(b%a, a, x1, y1);

    x = y1- (b/a)*x1;
    y = x1;

    return gcd;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int a, m, x ,y ;
        cin >> a >> m;

        int temp = ExtendedGCD(a , m, x, y);

        if (temp != 1)
        cout << "Inverse doesn't exist";
        else {
        int res = (x %m + m) % m;
        cout << "Modular multiplicative inverse is " << res;
        } 
    }
}