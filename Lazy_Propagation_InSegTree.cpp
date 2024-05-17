#include<bits/stdc++.h>
using namespace std ;

#define int long long int
#define double long double
#define endl '\n'
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);


vector<int>tree;
vector<int> lazy;
int sz;

void propagate(int node,int low,int high)
{
    if(lazy[node]!=0)
    {
      int dx = lazy[node];
      tree[node] += dx*(high -  low+1);

      if(low != high)
      {
        lazy[2*node] += dx;
        lazy[2*node+1] += dx;
      }

      lazy[node] = 0;
    }
}

void  rangeUpdate(int low,int high,int val,int node=1,int st=0,int en=sz-1)
{
    propagate(node,st,en);

     if(low > high || low > en || high<st) return;

    if(low<=st && high>= en)
    {
        lazy[node] += val;
        propagate(node,st,en);
        return;
    }

   int mid = (st + en)/2;
   rangeUpdate(low,high,val,2*node,st,mid);
   rangeUpdate(low,high, val, 2*node+1,mid+1,en);

   tree[node] = tree[2*node] + tree[2*node+1];
}

int rangeQuerySum(int low, int high, int node = 1, int st= 0, int en = sz - 1) {
    propagate(node,st,en);
    if (low > high || low > en || high< st) return 0;
    if (low <= st && high >=en) {
        return tree[node];
    }
    int mid = (st + en) / 2;
    int q1 = rangeQuerySum(low,high, 2 * node,st, mid) ;
    int q2 = rangeQuerySum(low,high, 2 * node + 1, mid + 1,en);

    return q1 + q2;
}

void pointUpdate(int pos,int val,int node=1,int low=0,int high=sz-1)
{
   propagate(node,low,high);

   if(pos>high ||  pos<low ) return;

   if(pos == low && pos == high)
   {
    tree[node]=val;
    return;
   }

   int mid = (low + high)/2;
   pointUpdate(pos,val,2*node,low,mid);
   pointUpdate(pos, val, 2*node+1,mid+1,high);

   tree[node] = tree[2*node] + tree[2*node+1];
}

void buildSegmentTree(vector<int> & arry)
{
    int n = arry.size();

    sz =1;

    while(sz<n) sz*=2;

    tree.assign(2*sz,0);
    lazy.assign(2*sz, 0);

    for(int i=0; i<n; i++)
    {
        pointUpdate(i,arry[i]);
    }
}

signed main()
{
    faster_code;
    int tt;
    cin >> tt;
    while(tt--)
    {
        int n,q;
        cin >> n >> q;

        vector<int>a(n,0);

        buildSegmentTree(a);

        while(q--)
        {
            int type ;
            cin >> type;

            if(type==0)
            {
                int l,r,val;
                cin >> l >> r >> val;

                l--; r--;

                rangeUpdate(l,r,val);
            }
            else{
                int l,r;
                cin >> l >> r;
                l--; r--;

                cout << rangeQuerySum(l,r) << endl;
            }
        }
    }
    return 0;
}