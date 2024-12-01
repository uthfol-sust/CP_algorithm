#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int u,v,weight;
};

int n,m;
vector<Edge> graph;

void printPath(vector<int>& parent, int v){
    stack<int> path;

    while(v != -1){
        path.push(v);
        v = parent[v];
    }

    while(!path.empty()){
        cout << path.top() << " ";
        path.pop();
    }
}

void  negativeCycle(vector<int>& parent, int start){
     vector<int> cycle;
    int current = start;

    for(int i=1; i<n; i++){
       current = parent[current];
    }

    int cycle_start = current;
    cycle.push_back(cycle_start);
    current = parent[cycle_start];

    while(current != cycle_start){
       cycle.push_back(current);
       current = parent[current];
    }
    cycle.push_back(cycle_start);

    //print negative cycle
    reverse(cycle.begin(), cycle.end());
    for(auto it: cycle){
        cout << it << " ";
    }
    cout << endl;
}

void bellmanFord(int source){
    vector<int>dist(n, INT_MAX);
    vector<int>parent(n,-1);
    dist[source] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int u = graph[j].u;
            int v = graph[j].v;
            int weight = graph[j].weight;

            if(dist[u] != INT_MAX && dist[u]+ weight < dist[v]){
                dist[v] = dist[u]+weight;
                parent[v] = u;
            }
        }
    }

    for(int j=0; j<m; j++){
        int u = graph[j].u;
        int v = graph[j].v;
        int weight = graph[j].weight;

        if(dist[u] != INT_MAX && dist[u]+ weight < dist[v]){
            cout << "Negative Cycle: ";
            negativeCycle(parent , v);
            return;
        }
    }


    // print path
    for(int i=0; i<n; i++){
        cout << "Distance from" << source << " to " << i <<" :" <<((dist[i]==INT_MAX)?-1:dist[i]) << " Path: ";

        if(dist[i]==INT_MAX){
            cout << "NO path exits";
        }
        else{
            printPath(parent, i);
            cout << endl;
        }
    }
}

int main(){

    cin >> n >> m;

    graph.resize(m);

    for(int i=0; i<m; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].weight;
    }

    int src;
    cin >> src;

    bellmanFord(src);
    return 0;
}