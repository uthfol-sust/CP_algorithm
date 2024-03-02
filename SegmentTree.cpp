#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<int>tree(N,-1);

void BuildTree(int a[],int node, int st, int en)
{
    if(st == en)
    {
        tree[node] = a[st];
        return;
    }

    int mid = (st+en)/2;

    BuildTree(a,2*node,st,mid);
    BuildTree(a,2*node+1,mid+1,en);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    BuildTree(a,1,0,n-1);

    for(int i=1; i<tree.size(); i++)
    {
        if(tree[i]==-1)break;
        
        cout << tree[i] << " ";
    }

    return 0;
}
