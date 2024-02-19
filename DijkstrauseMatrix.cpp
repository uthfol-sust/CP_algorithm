#include<bits/stdc++.h>
using namespace std;

#define v 9
int parent[100];
vector<bool>processed(100,false);
vector<int>value(100,INT_MAX);

int minvertex()
{
    int vertex,mn=INT_MAX;
    
    for(int i=0; i<100; i++)
    {
        if(processed[i]==false && value[i]<mn)
        {
            vertex=i;
            mn=value[i];
        }
    }
    return vertex;
}

void dijkstra(int src,int matx[9][9])
{
  parent[src]=-1;
  value[src]=0;

  for(int i=0; i<v-1; i++)
  {
    int u = minvertex();
    processed[u]=true;

    for(int j=0; j<v; j++)
    {
      if(matx[u][j]!=0 && processed[j]==false && value[u]!=INT_MAX && (value[u]+matx[u][j]<value[j]))
      {
        value[j] = value[u]+matx[u][j];
        parent[j]=u;
      }
    }
  }

  for(int i=0; i<v; i++)
   {
    cout << "distance from "<<src << " to " << i << " node "<< value[i] << "\n";
   }

}

int main()
{
  /* int v,m;
   cin >> v >> m;

   int matx[n][n];

   for(int i=0; i<m; i++)
   {
    int x,y,z;

    cin >> x >> y >> z;
    matx[x][y]=z;
    matx[y][x]=z;
   }*/

    int matx[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

   dijkstra(0,matx); 
}