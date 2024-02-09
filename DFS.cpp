#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[30000];
vector<int>visited(30000,0);

void DFS(int node)
{
   visited[node]=1;
   cout <<node << " ";//printing visited node
   
   for(int i:adj_list[node])
   {
     if(!visited[i])//check current node  visited or not
     {
        DFS(i);
     }
   }
}

int main()
{
   int n,m;
   cout << "Enter the number of vertices & Edage : ";
   cin >> n >> m;

   while(m--)
   {
     int a,b;
     cin>>a >>b;

     adj_list[a].push_back(b);//only it's used when graph is directed
     adj_list[b].push_back(a);//both are used when graph is undirected
   }
   
   int start=1;//starting 1
   DFS(start);

}