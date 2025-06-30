#include <bits/stdc++.h>
using namespace std;

int *mark;
vector<int> prime;

bool check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int Set(int N, int pos) {
    return N | (1 << pos);
}

void BitwiseSieve(int n) {
    int sz = n / 32 + 5;
    mark = new int[sz];
    memset(mark, 0, sizeof(int) * sz);

    for (int i = 3; i * i <= n; i += 2) {
        if (!check(mark[i / 32], i % 32)) {
            for (int j = i * i; j <= n; j += 2 * i) {
                mark[j / 32] = Set(mark[j / 32], j % 32);
            }
        }
    }

    prime.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (!check(mark[i / 32], i % 32)) {
            prime.push_back(i);
        }
    }
}

int main() {
    int n;
    cout << "Enter upper limit for primes: ";
    cin >> n;

    BitwiseSieve(n);

    cout << "Primes up to " << n << ":\n";
    for (int p : prime) {
        cout << p << " ";
    }
    cout << endl;

    delete[] mark;
    return 0;
}
