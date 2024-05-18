#include<bits/stdc++.h>
using namespace std ;

#define int long long int
#define double long double
#define endl '\n'
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mx = 10000;
int BITree[mx];

int getsum(int idx)
{
    int sum = 0;

    idx +=1;

    while(idx >0)
    {
        sum += BITree[idx];

        idx -= (idx & (-idx));
    }

    return sum;
}

void UpdateBIT(int n,int idx,int val)
{
   idx +=1;

   while(idx <= n)
   {
    BITree[idx] += val;

    idx += (idx &(-idx));
   }
}

void BuildBITree(int ary[],int n)
{
   for (int i=0; i<=n; i++){ 
        BITree[i] = 0;
   }

   
   for(int i=0; i<n; i++)
   {
     UpdateBIT(n,i,ary[i]);
   }
}

void solve(){
    int n,q;
    cin >> n >> q;

    int ary[n];
    for (int i=0; i<n; i++){ 
     cin >> ary[i];
    }

    BuildBITree(ary,n);

    while(q--)
    {
        int type;
        cin >> type; 

        if(type==1)
        { 
            int index;
            cin >> index;
            index --;
            int ans = getsum(index); 

            cout << ans << endl;
        }
        else{
            int index,val;
            index --;
            cin >> index >> val;

            UpdateBIT(n,index,val);
        }
    }
}

signed main()
{
    faster_code;
    // int tt;
    // cin >> tt;
    // while(tt--)
    // {
       solve();
    // }
    return 0;
}