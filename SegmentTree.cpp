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

int SumQuery(int a[],int node,int st,int en,int l,int r)
{
    if(r<st || l>en){
        return 0;
    }

    if(l<=st && en<=r){
        return tree[node];
    }

    int mid = (st+en)/2;

     int q1 = SumQuery(a,2*node,st,mid,l,r);
     int q2 = SumQuery(a,2*node+1,mid+1,en,l,r);

     return q1+q2;
}

int main()
{
    int n,q;
    cin >> n >> q;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    BuildTree(a,1,0,n-1);

    //print segment tree
    for(int i=1; i<tree.size(); i++)
    {
        if(tree[i]==-1) break;

        cout << tree[i] << " ";
    }
    cout <<"\n";

    while(q--)
    {
        int l,r;
        cin >> l >> r;

       int QueryAns = SumQuery(a,1,0,n-1,l,r);
        cout << QueryAns << "\n";
    }
    return 0;
}
