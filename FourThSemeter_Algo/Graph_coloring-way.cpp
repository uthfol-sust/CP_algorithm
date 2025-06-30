#include<bits/stdc++.h>
using  namespace std;

bool isValid(vector<vector<int>>graph, vector<int>color, int cur_v,int c){
    for(auto V: graph[cur_v])
    {
        if(color[V]==c)
        return false;
    }

    return true;
}

void graphcoloring(vector<vector<int>>graph, vector<int>color, int cur_v,int V,int M){
    if(cur_v==V)
    {
        for(int i=0; i<V; i++)
        {
           cout << color[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int c=1; c<=M; c++){
        if(isValid(graph, color,cur_v,c))
        {
            color[cur_v]=c;
            
            graphcoloring(graph,color,cur_v+1,V,M);

            color[cur_v]=0;
        }
    }

}

int main(){
   int V,E,M;
   cin >> V >> E >> M;
   
   vector<vector<int>> graph(V);
   vector<int>color(V,0);

   for(int i=0; i<E; i++)
   {
     int u,v;
     cin >> u >> v;

     graph[u].push_back(v);
     graph[v].push_back(u);
   }

   graphcoloring(graph,color,0,V,M);
   //cout << "Chromatic Number is " << c ;
}