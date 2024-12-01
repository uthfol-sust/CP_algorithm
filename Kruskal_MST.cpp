#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define faster_code ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    faster_code;

    int v, e;
    cin >> v >> e;

    // Initialize disjoint sets
    for (int i = 0; i < v; i++) {
        make_set(i);
    }

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end()); // Sort edges by weight
    int cost = 0;

    for (auto it : edges) {
        int w = it[0];
        int u = it[1];
        int v = it[2];

        if (u == v) continue; // Exclude self-loops

        int x = find_set(u);
        int y = find_set(v);

        if (x != y) {
            cout << u << " " << v << endl;
            cost += w;
            union_sets(u, v);
        }
    }
    cout << cost << endl;

    return 0;
}
