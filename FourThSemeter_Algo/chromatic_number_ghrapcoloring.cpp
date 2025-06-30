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

bool graphcoloring(vector<vector<int>>graph, vector<int>color, int cur_v,int V,int M){
    if(cur_v==V)
    {
        return true;
    }

    for(int c=1; c<=M; c++){
        if(isValid(graph, color,cur_v,c))
        {
            color[cur_v]=c;
            
            if(graphcoloring(graph,color,cur_v+1,V,M))
            return true;

            color[cur_v]=0;
        }
    }

    return false;
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

   int c=1;
   while(1){
     if(graphcoloring(graph,color,0,V,c))
     {
        break;
     }
     else{
        c++;
     }
   }
   cout << "Chromatic Number is " << c ;
}