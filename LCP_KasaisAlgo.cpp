#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ull unsigned long long
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define PI 3.14159265


const ll mod =1e9 + 7;
const int N=1e5+2;

struct suffix
{
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}

vector<int> buildSuffixArray(string str,int n)
{
  vector<suffix> suffixes(n); 

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = str[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (str[i + 1] - 'a'): -1;
    }

    sort(suffixes.begin(), suffixes.end(), cmp); 

    int ind[n];

    for (int k = 4; k < 2*n; k = k*2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else 
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                        suffixes[ind[nextindex]].rank[0]: -1;
        }
 
       
     sort(suffixes.begin(), suffixes.end(), cmp);
    }

    vector<int>suffixArr(n);
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
    return  suffixArr;

}

vector<int> kasai(string txt, vector<int> suffixArr) {
    int n = suffixArr.size();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0);

    for (int i = 0; i < n; i++)
        invSuff[suffixArr[i]] = i;

    int k = 0;

    for (int i = 0; i < n; i++) {
        if (invSuff[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = suffixArr[invSuff[i] + 1];
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k]){
            k++;
        }

        lcp[invSuff[i]] = k;

        if (k>0)
            k--;
    }

    return lcp;
}


void solve()
{
     string str;
     cin >> str;

     vector<int> suffixArr = buildSuffixArray(str, str.length());

     ll n = str.size();
     vector<int> lcp = kasai(str, suffixArr);

    ll total=0;
    total = accumulate(lcp.begin(), lcp.end(), 0LL);

    ll  ans = (n*(n+1))/2 - total;    
    cout << ans << endl;   

}

int main()
{
    faster_code;

//   int tt;
//   cin >> tt;
//   while(tt--){
        solve();
//    }
    return 0;
}