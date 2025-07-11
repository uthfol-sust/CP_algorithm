#include <bits/stdc++.h> 
using namespace std;

// Extended Euclidean Algorithm function
int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0)  { 
        x = 0; 
        y = 1; 
        return b; 
    } 

    int x1, y1; 
    int gcd = gcdExtended(b % a, a, x1, y1); 

    x = y1 - (b / a) * x1; 
    y = x1; 
    return gcd; 
} 

int main()  { 
    int a = 35, b = 15;
    int x, y;

    int g = gcdExtended(a, b, x, y); 

    cout << "GCD: " << g << endl;
    cout << "x: " << x << ", y: " << y << endl;

    return 0; 
}  
