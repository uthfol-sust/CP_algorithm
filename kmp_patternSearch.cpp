#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ull unsigned long long
#define faster_code ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define pb push_back

vector<int> calculateLPSarry(string pat,int m)
{
   vector<int>lps(m,0);
   for(int i=1; i<n; i++){
      int j = lps[i-1];

      while(j>0 && pat[i]!=pat[j])
       j = lps[i-1];

      if(pat[i]==pat) 
      j++;

      pi[i] = j;
   }

   return lps;
}

void KMPSearch(string txt,string pat)
{
    int n = txt.size();
    int m = pat.size();
    vi ans;

    vector<int> lps = calculateLPSarry(pat,m);

    int i=0,j=0;

    while(i<n)
    {
         if(txt[i]==pat[j])
         {
            j++;
            i++;
         }

         if(j==m)
         {
            ans.pb(i - j);
            j = lps[j-1];
         }
         else if(i < n && txt[i] != pat[j]){
                if (j != 0)
                j = lps[j - 1];
            else
                i++;
         }
    }

    if(!ans.empty())
    {
      cout << ans.size() << endl;

      for(auto it:ans) cout << it+1 <<" " ;
    }
    else 
    {
      cout << "Not Found";
    }

}

int main()
{
    faster_code;

  int tt,cs,i=1;
  cin >> tt;
  cs = tt;
  while(tt--){

   string txt,pat;
   cin >> txt >> pat;

   KMPSearch(txt,pat);

   cout << endl;
   }
    return 0;
}