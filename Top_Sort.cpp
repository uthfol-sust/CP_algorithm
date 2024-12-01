
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[10001];
vector<int>indegree(10001,0),result;
queue<int>qu;

int node,edge;

void topSort(){
  
  for(int i=0; i<node; i++){
    if(indegree[i]==0)
    {
        qu.push(i);
    }
  }

  while(!qu.empty()){
     int cur = qu.front();
     result.push_back(cur);
     qu.pop();

     for(auto v: graph[cur]){
        indegree[v]--;

        if(indegree[v]==0){
            qu.push(v);
        }
     }
  }

  if(result.size()!=node){
    cout << "IMPOSSIBLE!";
  }
  else{
    for(auto it:result)
    {
        cout << it <<" ";
    }
  }

}


int main(){
    cin >> node >> edge;
    
    int u,v;
    for(int i=0; i<node; i++){
     cin >> u >> v;
     graph[u].push_back(v);
     
     indegree[v]++;
    }

    topSort();
}