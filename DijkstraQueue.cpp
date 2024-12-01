#include <bits/stdc++.h>
using namespace std;

int n, m;
int source = 0; 
const int INF = INT_MAX;

vector<vector<pair<int, int>>> graph;

void printpath(int node, vector<int>& parent) {
    stack<int>path;

    while (node != -1) {
        path.push(node);
        node = parent[node];
    }


    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}

void Dijkstra() {
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qu;
    qu.push({0, source});

    while (!qu.empty()) {
        int d = qu.top().first;
        int u = qu.top().second;
        qu.pop();

        if (d > dist[u]) continue;

        for (auto& cur : graph[u]) {
            int v = cur.first;
            int w = cur.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                qu.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << "  Distance: " << ((dist[i] == INF) ? -1 : dist[i]) << "  Path: ";
        if (dist[i] == INF) {
            cout << "NO path.";
        } else {
            printpath(i, parent);
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n); // Initialize graph size

    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    Dijkstra();
    return 0;
}
