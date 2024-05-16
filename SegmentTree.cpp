#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e5+2;
vector<int>tree(4*N,-1);

void Buildtree(int a[],int node, int st, int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }

    int mid = (st+en)/2;

    Buildtree(a,2*node,st,mid);
    Buildtree(a,2*node+1,mid+1,en);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int sumquery(int a[],int node,int st,int en,int l,int r){
    if(r<st || l>en)
    return 0;

    if(l<=st && en<=r){
        return tree[node];
    }

    int mid = (st+en)/2;
    int q1 = sumquery(a,2*node,st,mid,l,r);
    int q2 = sumquery(a,2*node+1,mid+1,en,l,r);

    return q1+q2;
}

void update(int a[],int node,int st, int en,int pos, int val)
{
    if(st==en){
        if(val!=0){
          tree[node]+=val;
          return;
        }
        else{
            tree[node]=0;
            return;
        }

    }

    int mid = (st+en)/2;

    if(pos<=mid){
        update(a,2*node,st,mid,pos,val);
    }
    else{
        update(a,2*node+1,mid+1,en,pos,val);
    }

    tree[node] = tree[2*node]+tree[2*node+1];
}

int main(){

    int tt,cs=1;  cin >> tt;
    while(tt--){
        cout << "Case " << cs << ":" << endl;
         
       int n,q,k;
       cin >> n >> q;

       int a[n+1];
       for(int i=0; i<n; i++)
       {
        cin >> a[i];
       }
       
       Buildtree(a,1,0,n-1);

       while(q--)
       {
        cin >> k;
        if(k==3)
        {
           int l,r;
           cin >> l >> r;

          int ans = sumquery(a,1,0,n-1,l,r);
          cout  << ans << endl;
        }
        else if(k==2)
        {
            int p,v;
           cin >> p >> v;
           update(a,1,0,n-1,p,v);
        }
        else if(k==1){
            int pos;
            cin >> pos;
            int ans = sumquery(a,1,0,n-1,pos,pos);
            update(a,1,0,n-1,pos,0);
            cout << ans << endl;
        }

       }
       cs++;
    }
}