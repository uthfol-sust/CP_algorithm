#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[30000];

void BFS(int node)
{
   vector<bool> visited(30000, false); 
   queue<int>qu;
   vector<int>path;
   
   qu.push(node);
   visited[node]=true;

   while(!qu.empty())
   {
     int cur = qu.front();
     path.push_back(cur);
     qu.pop();

     for(int i:adj_list[cur])
     {
        if(!visited[i])
        {
            qu.push(i);
            visited[i]=true;
        }
     }
   }

   for(auto it:path) cout<<it <<" ";

}

int main()
{
   int n,m;
   //cout << "Enter the number of vertices & Edage : ";
   cin >> n >> m;

   while(m--)
   {
     int a,b;
     cin>>a >>b;

     adj_list[a].push_back(b);
     adj_list[b].push_back(a);
   }
   
   int start=0;
   BFS(start);

}
